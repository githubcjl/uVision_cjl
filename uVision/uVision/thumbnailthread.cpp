#include "thumbnailthread.h"
#include <QDebug>

//thumbnailthread::thumbnailthread(QObject *parent)
//	: QThread(parent)
//{
//
//}

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
void thumbnailthread::run()
{
	if( bigpm.isNull())
	{
		emit thumbnailFailed(pmfilename);
	}
	else
	{
		qWarning() << "thread start..." << number;
		sleep(number);
		smallpm = bigpm.scaled(TN_WIDTH, TN_HEIGHT, Qt::KeepAspectRatio);
		emit thumbnailFinished(smallpm);
	}
}
