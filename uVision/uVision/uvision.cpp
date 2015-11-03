#include "uvision.h"
#include "ui_uvision.h"
#include "thumbnailthread.h"
#include <QDebug>
#include <QLabel>
#include <QPalette>
#include <QLayout>
#include <QFileDialog>
#include <QPushButton>
#include <QMessageBox>


uVision::uVision(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{

	ui.setupUi(this);
	setWindowTitle("uVision_v1.0");

	waitseconds = 1;
	QPalette pal = palette();
	pal.setColor(QPalette::Background, Qt::white);
	//setFixedSize(600,400);
	//setWindowTitle("www.cuteqt.com");
	previewwidget = new QWidget(this);	
	//previewwidget->setFixedSize(600,350);
	previewwidget->setPalette(pal);
	previewwidget->setAutoFillBackground(true);
	previewwidget->setGeometry(300,55,480,460);
	//QPushButton* btn = new QPushButton("Open pictures..", this);
	//btn->setGeometry(450, 360, 130, 35);
	connect(ui.actOpenImage, SIGNAL(triggered()), this, SLOT(openFiles()));
	QGridLayout* layout = new QGridLayout(previewwidget);

	connect(ui.actPlay,SIGNAL(triggered()),this,SLOT(on_actPlayBtn_clicked()));
	connect(ui.actParameter,SIGNAL(triggered()),this,SLOT(on_actVideoParameter_clicked()));
	connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(on_serialBtn_clicked()));
}

uVision::~uVision()
{

}

void uVision::on_actPlayBtn_clicked()
{
	VideoInput *vi = new VideoInput;
	vi->show();
}

void uVision::on_actVideoParameter_clicked()
{
	videoproperty *vp = new videoproperty;
	
	vp->show();
}

void uVision::on_serialBtn_clicked()
{
	serialparameters *serial = new serialparameters;
	
	serial->show();
}

void uVision::openFiles()
{
	waitseconds = 1;//reset
	QStringList list = QFileDialog::getOpenFileNames(this, "Open one or more pictures", "", "*.jpg *.png *.bmp");
	if( list.count() == 0)
	{
		return;
	}
	//open files one by one, and create thread to create thumbnail for each file
	QStringList::Iterator it = list.begin();
	while(it != list.end()) 
	{
		createThumbnail(*it);
		++it;
	}
}

void uVision::createThumbnail(const QString& filename)
{
	qDebug() << filename;
	QThread* thread = new thumbnailthread(filename, 10 - waitseconds);
	waitseconds ++;
	connect(thread, SIGNAL(thumbnailFinished(QImage)), this, SLOT(addThumbnail(QImage)));
	connect(thread, SIGNAL(thumbnailFailed(const QString)), this, SLOT(showError(const QString)));
	connect(thread, SIGNAL(finished()), this, SLOT(deleteThread()));
	thread->start();
}

void uVision::deleteThread()
{
	QObject* obj = sender();
	thumbnailthread * th = qobject_cast<thumbnailthread*>(obj);
	qDebug() << "delete thread..." << th->waitseconds();
	obj->deleteLater();
}

void uVision::addThumbnail(QImage smallpm)
{
	static int i = 0;
	static int j = 0;
	//qWarning() << "thumbnail create successfully..." << j << i ;
	//qWarning() << "Small PM:"<<smallpm << smallpm.size();
	QLabel* label = new QLabel;
	label->setPixmap(QPixmap::fromImage(smallpm));
	QGridLayout* gl = qobject_cast<QGridLayout*>(previewwidget->layout());
	gl->addWidget(label, j, i);
	label->show();
	qWarning() << "Label:" <<label << label->isVisible();
	i++;
	if( i > previewwidget->width() / smallpm.width()) 
	{
		i = 0;
		j ++;
	}
}

void uVision::showError(const QString filename)
{
	QMessageBox::information(this, "Error!", filename+" is not a valid picture file.");
}
