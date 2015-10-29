#include "serialparameters.h"

serialparameters::serialparameters(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle(QString::fromLocal8Bit("串口参数设定"));
}

serialparameters::~serialparameters()
{

}
