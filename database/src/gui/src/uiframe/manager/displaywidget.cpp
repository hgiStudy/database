#include "displaywidget.h"

DisplayWidget::DisplayWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initUi();
}

DisplayWidget::~DisplayWidget()
{}

void DisplayWidget::switchPage(int index)
{
	if (!m_stackedwidget || index < 0 || index >= m_stackedwidget->count()) return;

	if (index == 0 || index == 1 || index == 2 || index == 3) {
		m_stackedwidget->setCurrentIndex(index);
	}
}

void DisplayWidget::initUi()
{
	// 垂直布局
	QVBoxLayout* layout = new QVBoxLayout(this);

	// 水平布局
	m_label_layout = new QHBoxLayout;
	m_label_layout->setSpacing(0);
	m_stackedwidget = new QStackedWidget(this);
	std::map<NavigationPage, QWidget*> widget;

	m_widget1 = new QWidget(this);
	widget.insert({ NavigationPage::kProductionPage, m_widget1 });

	m_widget2 = new QWidget(this);
	widget.insert({ NavigationPage::kMakeDrawingsPage, m_widget2 });

	m_settingwidget = new SettingWidget(this);
	widget.insert({ NavigationPage::kSystemSettingPage, m_settingwidget });

	m_widget3 = new QWidget(this);
	widget.insert({ NavigationPage::kHelpPage, m_widget3 });

	for (const auto& it : widget) {
		m_stackedwidget->addWidget(it.second);
	}

	layout->addLayout(m_label_layout, 0);
	layout->addWidget(m_stackedwidget, 1);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);
	setLayout(layout);

}

