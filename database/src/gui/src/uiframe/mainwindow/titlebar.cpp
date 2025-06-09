#include "titlebar.h"
#include <QScreen>

TitleBar::TitleBar(QWidget *parent)
	: QFrame(parent)
{
	ui.setupUi(this);
	
}

TitleBar::~TitleBar()
{}

void TitleBar::updateMaxBtnState()
{
    ui.btn_max->setIcon(
        QIcon(parentWidget()->isMaximized() ? ":/Database/state/zoom.png" : ":/Database/state/max.png"));
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

