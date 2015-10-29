#ifndef VIDEOINPUT_H
#define VIDEOINPUT_H

#include <QWidget>
#include <QImage>
#include <QTimer>
#include "ui_videoinput.h"

#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//namespace Ui{
//	class Ui_VideoInput;
//}
using namespace cv;
class VideoInput : public QWidget
{
	Q_OBJECT

public:
	explicit VideoInput(QWidget *parent = 0);
	~VideoInput();

private:
	Ui::VideoInput *ui;
	QTimer *timer;
	QImage *imag;
	CvCapture *cam;
	//VideoCapture *cam1;
	VideoCapture cap;
	Mat frame_cap;
	IplImage *frame;
private slots:
	void openCamera();
	void readFarame();
	void closeCamera();
	void takingPictures();
};

#endif // VIDEOINPUT_H
