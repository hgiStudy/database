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


protected:
	void resizeEvent(QResizeEvent* event)override;

private slots:
	void on_btn_min_clicked();
	void on_btn_max_clicked();
	void on_btn_exit_clicked();
private:
	Ui::TitleBarClass ui;
};

