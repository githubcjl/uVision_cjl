#include "serialparameters.h"

serialparameters::serialparameters(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle(QString::fromLocal8Bit("���ڲ����趨"));
}

serialparameters::~serialparameters()
{

}
