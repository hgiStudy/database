#include "titlebar.h"
#include <QScreen>

TitleBar::TitleBar(QWidget *parent)
	: QFrame(parent)
{
	ui.setupUi(this);
	
}

TitleBar::~TitleBar()
{}


void TitleBar::resizeEvent(QResizeEvent* event)
{
    QSize size = parentWidget()->size();
    // 获取主屏幕大小
    QScreen* primaryScreen = QGuiApplication::primaryScreen();
    QSize screenSize = primaryScreen->size();


    if (size.width() < screenSize.width()) {
        ui.btn_max->setIcon(QIcon(":/Database/state/max.png"));
    }
    else {
        ui.btn_max->setIcon(QIcon(":/Database/state/zoom.png"));
    }
}

void TitleBar::on_btn_min_clicked()
{
	parentWidget()->showMinimized();
}

void TitleBar::on_btn_max_clicked()
{
	parentWidget()->isMaximized() ? parentWidget()->showNormal() : parentWidget()->showMaximized();
}

void TitleBar::on_btn_exit_clicked()
{
	parentWidget()->close();
}

