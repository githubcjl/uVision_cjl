#include "thumbnailthread.h"
#include <QDebug>


//thumbnailthread::thumbnailthread(QObject *parent)
//	: QThread(parent)
//{
//
//}

//std::vector<QImage> thumbnailthread::vimages = {};
extern std::vector<QImage> vimages;

thumbnailthread::~thumbnailthread()
{

}

const int TN_WIDTH=160;
const int TN_HEIGHT=120;
thumbnailthread::thumbnailthread(const QString filename, int n)
{
	pmfilename = filename;
	bigpm = QImage(filename);
	number = n;
}

cv::Mat thumbnailthread::QImage2cvMat(QImage image) 
{  
	cv::Mat mat;  
	qDebug() << image.format();  
	switch(image.format())  
	{  
	case QImage::Format_ARGB32:  
	case QImage::Format_RGB32:  
	case QImage::Format_ARGB32_Premultiplied:  
		mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());  
		break;  
	case QImage::Format_RGB888:  
		mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());  
		cv::cvtColor(mat, mat, CV_BGR2RGB);  
		break;  
	case QImage::Format_Indexed8:  
		mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());  
		break;  
	}  
	return mat;  
}  

void thumbnailthread::run()
{
	if( bigpm.isNull())
	{
		emit thumbnailFailed(pmfilename);
	}
	else
	{
		//qWarning() << "thread start..." << number;
		sleep(number);
		smallpm = bigpm.scaled(TN_WIDTH, TN_HEIGHT, Qt::KeepAspectRatio);

		vimages.push_back(smallpm);	
		QImage imagetest = vimages[0].convertToFormat(QImage::Format_RGB32);
		cv::Mat mat = QImage2cvMat(imagetest);
		cv::imshow("Image test",mat);
		cv::waitKey(30000);

		emit thumbnailFinished(smallpm);
		emit thumbnailFinishedInstitch(bigpm);
	}


}
