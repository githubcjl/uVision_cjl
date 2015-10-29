#include "videoproperty.h"

videoproperty::videoproperty(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle(QString::fromLocal8Bit("视频属性设定"));
}

videoproperty::~videoproperty()
{

}
