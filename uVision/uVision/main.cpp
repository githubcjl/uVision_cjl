/*This is uVision_v1.0*/
#include "uvision.h"
#include <QtGui/QApplication>
#include "videoinput.h"
#include <QtCore>
#include "thumbnailthread.h"
#include "siftmatch.h"
#include <QTextCodec>


int picture_num = 0;
std::vector<QImage> vimages;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForName("gb18030"));
	
	

	uVision w;
	w.show();


	return a.exec();
	
}
