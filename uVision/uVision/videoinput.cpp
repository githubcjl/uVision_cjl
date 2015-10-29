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
//	cam = cvCreateCameraCapture(0);//������ͷ��������ͷ�л�ȡ��Ƶ
//	//VideoCapture cam1(0);
//
//	timer->start(33);              // ��ʼ��ʱ����ʱ�򷢳�timeout()�ź�  
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
//	frame = cvQueryFrame(cam);// ������ͷ��ץȡ������ÿһ֡  
//	// ��ץȡ����֡��ת��ΪQImage��ʽ��QImage::Format_RGB888��ͬ������ͷ�ò�ͬ�ĸ�ʽ��  
//	QImage image((const uchar*)frame->imageData, frame->width, frame->height, QImage::Format_RGB888);  
//	ui->videoLabel->setPixmap(QPixmap::fromImage(image));  // ��ͼƬ��ʾ��label��  
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
//	frame = cvQueryFrame(cam);// ������ͷ��ץȡ������ÿһ֡  
//
//	// ��ץȡ����֡��ת��ΪQImage��ʽ��QImage::Format_RGB888��ͬ������ͷ�ò�ͬ�ĸ�ʽ��  
//	QImage image((const uchar*)frame->imageData, frame->width, frame->height, QImage::Format_RGB888);  
//
//	ui->photoLabel->setPixmap(QPixmap::fromImage(image));  // ��ͼƬ��ʾ��label��
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
		
		ui->photoLabel->setPixmap(QPixmap::fromImage(image));  // ��ͼƬ��ʾ��label��
		//const QPixmap *pixmap = ui->photoLabel->pixmap();
		//const QPixmap *pixmap = QPixmap::fromImage(image);
		image.save(Qpath,"JPG");
		
	}

void VideoInput::closeCamera()  
{  
	timer->stop();         // ֹͣ��ȡ���ݡ�  

	cvReleaseCapture(&cam);//�ͷ��ڴ棻  
}

VideoInput::~VideoInput()
{
	delete ui;
}
