#pragma once

#include <QWidget>
#include <QFrame>
#include "ui_titlebar.h"

class TitleBar : public QFrame
{
	Q_OBJECT

public:
	TitleBar(QWidget *parent = nullptr);
	~TitleBar();

private:
	Ui::TitleBarClass ui;
};

