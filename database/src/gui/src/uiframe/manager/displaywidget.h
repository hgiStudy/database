#pragma once

#include <QWidget>
#include "ui_displaywidget.h"
#include "settingwidget.h"
#include <QStackedWidget>
#include "peasdefine.h"

class DisplayWidget : public QWidget
{
	Q_OBJECT

public:
	DisplayWidget(QWidget *parent = nullptr);
	~DisplayWidget();
	void switchPage(int index);

private:
	void initUi();

private:
	Ui::DisplayWidgetClass ui;
	SettingWidget* m_settingwidget = nullptr;
	QStackedWidget* m_stackedwidget = nullptr; 
	QHBoxLayout* m_label_layout = nullptr; 
	QWidget* m_widget1 = nullptr;
	QWidget* m_widget2 = nullptr;
	QWidget* m_widget3 = nullptr;
};

