#include "settingwidget.h"

SettingWidget::SettingWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	main_layout = new QVBoxLayout(this);
	QWidget* widget = new QWidget(this);
	main_layout->addWidget(ui.option_frame);
	main_layout->addWidget(widget);
	main_layout->setContentsMargins(9, 9, 9, 9);
	
}

SettingWidget::~SettingWidget()
{}

