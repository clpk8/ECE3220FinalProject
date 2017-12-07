#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
    QString str = QCoreApplication::applicationDirPath() + "/jesse.png";
    qDebug () <<str;
    QPixmap pix(str);
    ui->label_img->setPixmap(pix);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_Load_clicked()
{
    //Load items to tables
	QSqlQueryModel * modal = new QSqlQueryModel();
	QSqlQueryModel * modal1 = new QSqlQueryModel();
	QSqlQuery query;
	query.prepare("SELECT ItemId, ItemName, Location from Item Where Status = 1");
	query.exec();
	modal->setQuery(query);
	ui->AvaliableItem->setModel(modal);
	QSqlQuery query1;
	query1.prepare("SELECT ItemId, ItemName, Location from Item Where Status = 0 and Pawprint = :Pawprint");
	query1.bindValue(":Pawprint",Pawprint);
	query1.exec();
	modal1->setQuery(query1);
	ui->BorrowedItem->setModel(modal1);
}

//check our item
void MainWindow::on_pushButton_CheckOut_clicked()
{
    //create error handle class with database
    ErrorHandle *E = new ErrorHandle(data);

    //set warning color
	ui->label_Error->setStyleSheet("color:red");
	int errorflag = 1, typeflag = 1;

    //get id from ui
	QString id = ui->lineEdit_ItemId->text();
    //try block to check type
	try{
        if(E->typeCheck(id) == 0){
			throw 0;
		}
	}

	catch(int &d){
        QString error = "Item Id is not valid";
        E->errorMessage(error);
        ui->label_Error->setText(E->msg);
		typeflag = 0;
	}
    //try block to check if empty
	try{
        if(E->isEmpty(id) == 0){
			throw 0;
		}
	}

	catch(int &d){
        QString error = "Item ID is empty";
        E->errorMessage(error);
        ui->label_Error->setText(E->msg);
		typeflag = 0;
	}

    //only if type is right
	if(typeflag == 1){

		int ItemId = id.toInt();

        //try blick to test if it can be checked out
		try{
            if(E->checkoutCheck(ItemId) == 0){
				throw 0;
			}
		}

		catch(int &d){
            QString error = "You can't borrow this Item";
            E->errorMessage(error);
            ui->label_Error->setText(E->msg);
			errorflag = 0;
		}
        //only if everyting are good to go
		if(errorflag == 1){
            //query to check it out
			QSqlQuery query;
			query.prepare("UPDATE Item set Status = 0, Pawprint = :Pawprint, BorrowTime = datetime('now', 'localtime'), ReturnTime = datetime('now','localtime','+' || BorrowLength || ' minutes') where ItemId = :ItemId");
			query.bindValue(":ItemId",ItemId);
			query.bindValue(":Pawprint",Pawprint);
			query.exec();
			ui->label_Error->setText(" ");
		}
	}
}

//return an item
void MainWindow::on_pushButton_Return_clicked()
{

    //ser warning color
	ui->label_Error->setStyleSheet("color:red");
	int errorflag = 1, typeflag = 1;
	String id;

    // open the video camera no. 0
    VideoCapture cap(0);

    //set the size of camera
	cap.set(CV_CAP_PROP_FRAME_WIDTH,320);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT,240);

    // if not success, exit program
    if (!cap.isOpened())
	{
        cout << "Cannot open the video cam" << endl;
	}

    //example code from Zbar
    //create a scanner
	ImageScanner scanner;
    //enable scanner
	scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);

    //get the width and the height of frames of the video
    double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

    //create a window called Press ESC to quit
    namedWindow("Press ESC to quit",CV_WINDOW_AUTOSIZE);

    //flag to stop scan when it found a value
	int flag = 0;

    //do while to stop when QR code was read
	do{
		Mat frame;

        // read a new frame from video
        bool bSuccess = cap.read(frame);

        //if not success, break loop
        if (!bSuccess)
		{
			break;
		}

        //set color of the background
		Mat grey;
		cvtColor(frame,grey,CV_BGR2GRAY);

		int width = frame.cols;
		int height = frame.rows;
		uchar *raw = (uchar *)grey.data;
		// wrap image data
		Image image(width, height, "Y800", raw, width * height);
		// scan the image for barcodes
		int n = scanner.scan(image);
		// extract results

		for(Image::SymbolIterator symbol = image.symbol_begin();
				symbol != image.symbol_end();
				++symbol) {
			vector<Point> vp;
			id = symbol->get_data();
            //found the value
            flag = 1;
			int n = symbol->get_location_size();
			for(int i=0;i<n;i++){
				vp.push_back(Point(symbol->get_location_x(i),symbol->get_location_y(i)));
			}
			RotatedRect r = minAreaRect(vp);
			Point2f pts[4];
			r.points(pts);
			for(int i=0;i<4;i++){
				line(frame,pts[i],pts[(i+1)%4],Scalar(255,0,0),3);
			}
		}

        //show the frame in "MyVideo" window
        imshow("Press ESC to quit", frame);

        //window can be quit with esc as well
        if (waitKey(1) == 27)
		{
			break;
		}

    }while(flag == 0);

    //change id from string to QString
	QString temp = QString::fromStdString(id);

    //create error handling class
    ErrorHandle *E = new ErrorHandle(data);

    //try block to make sure type
	try{
        if(E->typeCheck(temp) == 0){
			throw 0;
		}

	}

	catch(int &d){
		typeflag = 0;
        QString error = "Please use a Valid QR Code";
        E->errorMessage(error);
        ui->label_Error->setText(E->msg);
	}
    //if type is correct
	if(typeflag == 1){

		int ItemId = stoi(id);
        //try block to see if it can be returned
		try{
            if(E->checkIdExist(ItemId,Pawprint) == 0){
				throw 0;
			}
		}

		catch(int &d){
			errorflag = 0;
            QString error = "You can't return this Item";
            E->errorMessage(error);
            ui->label_Error->setText(E->msg);
		}

        //only if everyhint is correct
		if(errorflag == 1){
            ui->label_Error->setText(" ");

			QSqlQuery query;
			query.prepare("UPDATE Item set Status = 1, Pawprint = NULL where ItemId = :ItemId");
			query.bindValue(":ItemId",ItemId);
			query.exec();

			//load again
			QSqlQueryModel * modal = new QSqlQueryModel();
			QSqlQueryModel * modal1 = new QSqlQueryModel();
			QSqlQuery query1;
			query1.prepare("SELECT ItemId, ItemName, Location from Item Where Status = 1");
			query1.exec();
			modal->setQuery(query1);
			ui->AvaliableItem->setModel(modal);
			QSqlQuery query2;
			query2.prepare("SELECT ItemId, ItemName, Location from Item Where Status = 0 and Pawprint = :Pawprint");
			query2.bindValue(":Pawprint",Pawprint);
			query2.exec();
			modal1->setQuery(query2);
			ui->BorrowedItem->setModel(modal1);
		}
	}

    //close scanning window
    cvDestroyWindow("Press ESC to quit");
}
