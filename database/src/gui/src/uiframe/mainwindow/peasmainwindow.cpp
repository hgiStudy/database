#include "peasmainwindow.h"
#include "titlebar.h"
#include "directorywidget.h"
#include "displaywidget.h"
#include "qframeless/qframelesshelper.h"

class PeasPrivate
{
public:
	TitleBar* m_titlebar = nullptr;
	DirectoryWidget* m_directoryWidget = nullptr;
	DisplayWidget* m_displaywidget = nullptr;
	QWidget* m_widget1 = nullptr;
};

PeasMainWindow::PeasMainWindow(QWidget *parent)
	: QFramelessWidget(parent)
	, ui(new Ui::PeasMainWindowClass())
{
	ui->setupUi(this);

	
	d_ptr = new PeasPrivate();
	initUi();
	initModelData();
}

PeasMainWindow::~PeasMainWindow()
{
	if (d_ptr) {
		delete d_ptr;
		d_ptr = nullptr;
	}
	delete ui;
}

void PeasMainWindow::initUi()
{
	d_ptr->m_titlebar = new TitleBar(this);
	d_ptr->m_directoryWidget = new DirectoryWidget(this);
	d_ptr->m_displaywidget = new DisplayWidget(this);
	d_ptr->m_widget1 = new QWidget(this);

	ui->layout_title->addWidget(d_ptr->m_titlebar);
	ui->layout_directory->addWidget(d_ptr->m_directoryWidget);
	ui->layout_display->addWidget(d_ptr->m_displaywidget);
	ui->layout_statusbar->addWidget(d_ptr->m_widget1);

	framelessHelper()->setTitleBar(d_ptr->m_titlebar);

	connect(framelessHelper(), &QFramelessHelper::maximizedChanged, this,
		[this]() { d_ptr->m_titlebar->updateMaxBtnState(); });

}

void PeasMainWindow::initModelData()
{
	connect(d_ptr->m_directoryWidget, &DirectoryWidget::currentItemChanged,
		[this](int index) {
			d_ptr->m_displaywidget->switchPage(index);
		}
	);
}

