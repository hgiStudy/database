#pragma once

#include <QWidget>
#include "ui_databasewidget.h"

class DatabaseWidget : public QWidget
{
	Q_OBJECT

public:
	DatabaseWidget(QWidget *parent = nullptr);
	~DatabaseWidget();

private:
	Ui::DatabaseWidgetClass ui;
};
