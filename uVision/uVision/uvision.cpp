#include "uvision.h"
#include "ui_uvision.h"


uVision::uVision(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	setWindowTitle("uVision_v1.0");
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
