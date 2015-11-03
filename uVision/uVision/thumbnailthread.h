#ifndef THUMBNAILTHREAD_H
#define THUMBNAILTHREAD_H

#include <QThread>
#include <QString>
#include <QImage>

class thumbnailthread : public QThread
{
	Q_OBJECT
public:
	thumbnailthread(const QString filename, int n = 1);
	int waitseconds(){return number;};
	~thumbnailthread();
private:
	void run();
	QImage bigpm, smallpm;
	QString pmfilename;
	int number;
signals:
	void thumbnailFinished(QImage);
	void thumbnailFailed(const QString filename);

//public:
//	thumbnailthread(QObject *parent);
//	~thumbnailthread();
//
//private:
	
};

#endif // THUMBNAILTHREAD_H
