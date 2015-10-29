#include "videoinput.h"
#include "ui_videoinput.h"
#include <string>


extern int picture_num;


VideoInput::VideoInput(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::VideoInput)
{
	ui->setupUi(this);
	cam = NULL;
	//VideoCapture cam1(0);
	//cam1 = NULL;
	timer = new QTimer(this);
	imag = new QImage();
	connect(timer,SIGNAL(timeout()),this,SLOT(readFarame()));
	connect(ui->playBtn,SIGNAL(clicked()),this,SLOT(openCamera()));
	connect(ui->photoBtn,SIGNAL(clicked()),this,SLOT(takingPictures()));
	connect(ui->stopBtn,SIGNAL(clicked()),this,SLOT(closeCamera()));
}

//void VideoInput::openCamera()  
//{  
//	cam = cvCreateCameraCapture(0);//打开摄像头，从摄像头中获取视频
//	//VideoCapture cam1(0);
//
//	timer->start(33);              // 开始计时，超时则发出timeout()信号  
//}

void VideoInput::openCamera()
{
	 cap.open(1);
	if(!cap.isOpened())
	{
		exit(-1);
	}
	timer->start(33);
}

//void VideoInput::readFarame()  
//{  
//	frame = cvQueryFrame(cam);// 从摄像头中抓取并返回每一帧  
//	// 将抓取到的帧，转换为QImage格式。QImage::Format_RGB888不同的摄像头用不同的格式。  
//	QImage image((const uchar*)frame->imageData, frame->width, frame->height, QImage::Format_RGB888);  
//	ui->videoLabel->setPixmap(QPixmap::fromImage(image));  // 将图片显示到label上  
//	
//}

void VideoInput::readFarame()
{
	
	
		cap>>frame_cap;
		QImage image((const uchar*)frame_cap.data, frame_cap.cols, frame_cap.rows, QImage::Format_RGB888);
		ui->videoLabel->setPixmap(QPixmap::fromImage(image));
	
}

//void VideoInput::takingPictures()  
//{ 
//	picture_num++;
//	std::string picture_s;
//	std::stringstream ss;
//	ss << picture_num;
//	ss >> picture_s;
//	std::string path = "D:\\studysoft\\Image_uV\\";
//	std::string path1 = ".jpg";
//	path = path+picture_s+path1;
//	//path = path+path1;
//	QString Qpath;
//	Qpath = QString(path.c_str());
//	
//	frame = cvQueryFrame(cam);// 从摄像头中抓取并返回每一帧  
//
//	// 将抓取到的帧，转换为QImage格式。QImage::Format_RGB888不同的摄像头用不同的格式。  
//	QImage image((const uchar*)frame->imageData, frame->width, frame->height, QImage::Format_RGB888);  
//
//	ui->photoLabel->setPixmap(QPixmap::fromImage(image));  // 将图片显示到label上
//	//const QPixmap *pixmap = ui->photoLabel->pixmap();
//	//const QPixmap *pixmap = QPixmap::fromImage(image);
//	image.save(Qpath,"JPG");
//	
//}

void VideoInput::takingPictures()  
	{ 
		picture_num++;
		std::string picture_s;
		std::stringstream ss;
		ss << picture_num;
		ss >> picture_s;
		std::string path = "D:\\studysoft\\Image_uV\\";
		std::string path1 = ".jpg";
		path = path+picture_s+path1;
		//path = path+path1;
		QString Qpath;
		Qpath = QString(path.c_str());

		cap>>frame_cap;
		QImage image((const uchar*)frame_cap.data, frame_cap.cols, frame_cap.rows, QImage::Format_RGB888);
		
		ui->photoLabel->setPixmap(QPixmap::fromImage(image));  // 将图片显示到label上
		//const QPixmap *pixmap = ui->photoLabel->pixmap();
		//const QPixmap *pixmap = QPixmap::fromImage(image);
		image.save(Qpath,"JPG");
		
	}

void VideoInput::closeCamera()  
{  
	timer->stop();         // 停止读取数据。  

	cvReleaseCapture(&cam);//释放内存；  
}

VideoInput::~VideoInput()
{
	delete ui;
}
