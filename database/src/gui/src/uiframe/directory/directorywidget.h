#pragma once

#include "NavigationWidget.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class DirectoryWidget  : public QWidget
{
	Q_OBJECT

public:
	DirectoryWidget(QWidget *parent);
	~DirectoryWidget();
	void initUi();

private:
	QVBoxLayout* m_rightLayout = nullptr;
	QVBoxLayout* m_mainLayout = nullptr;
	NavigationWidget* m_navigationWidget = nullptr;
	QLabel* m_tipsLabel = nullptr;
	QWidget* m_window = nullptr;
};

