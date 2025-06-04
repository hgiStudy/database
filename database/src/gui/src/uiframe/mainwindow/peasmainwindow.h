#pragma once

#include <QWidget>
#include "ui_peasmainwindow.h"
#include "framelesswidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PeasMainWindowClass; };
QT_END_NAMESPACE

class PeasPrivate;

class PeasMainWindow : public FramelessWidget
{
	Q_OBJECT

public:
	PeasMainWindow(QWidget *parent = nullptr);
	~PeasMainWindow();

private:
	void initUi();
private:
	Ui::PeasMainWindowClass* ui;
	PeasPrivate* d_ptr = nullptr;
};

