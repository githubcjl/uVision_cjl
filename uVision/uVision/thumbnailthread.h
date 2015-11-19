#ifndef THUMBNAILTHREAD_H
#define THUMBNAILTHREAD_H

#include <QThread>
#include <QString>
#include <QImage>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>

class thumbnailthread : public QThread
{
	Q_OBJECT
public:
	thumbnailthread(const QString filename, int n = 1);
	int waitseconds(){return number;};
	cv::Mat QImage2cvMat(QImage image);
	~thumbnailthread();
	//static std::vector<QImage> vimages;
private:
	void run();
	QImage bigpm, smallpm;
	QString pmfilename;
	int number;
signals:
	void thumbnailFinished(QImage);
	void thumbnailFailed(const QString filename);
	void thumbnailFinishedInstitch(QImage);

//public:
//	thumbnailthread(QObject *parent);
//	~thumbnailthread();
//
//private:
	
};

#endif // THUMBNAILTHREAD_H
