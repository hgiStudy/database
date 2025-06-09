#pragma once

#include <QWidget>
#include "ui_peasmainwindow.h"
#include "qframeless/qframelesswidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class PeasMainWindowClass; };
QT_END_NAMESPACE

class PeasPrivate;

class PeasMainWindow : public QFramelessWidget
{
	Q_OBJECT

public:
	PeasMainWindow(QWidget *parent = nullptr);
	~PeasMainWindow();

private:
	void initUi();
	void initModelData();

private:
	Ui::PeasMainWindowClass* ui;
	PeasPrivate* d_ptr = nullptr;
};

