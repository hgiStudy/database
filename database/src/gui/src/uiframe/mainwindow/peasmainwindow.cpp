#include "peasmainwindow.h"
#include "titlebar.h"
#include "directorywidget.h"

class PeasPrivate
{
public:
	TitleBar* m_titlebar = nullptr;
	DirectoryWidget* m_directoryWidget = nullptr;
	QWidget* m_widget = nullptr;
	QWidget* m_widget1 = nullptr;
};

PeasMainWindow::PeasMainWindow(QWidget *parent)
	: FramelessWidget(parent)
	, ui(new Ui::PeasMainWindowClass())
{
	ui->setupUi(this);

	d_ptr = new PeasPrivate();
	initUi();
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
	d_ptr->m_widget = new QWidget(this);
	d_ptr->m_widget1 = new QWidget(this);

	ui->layout_title->addWidget(d_ptr->m_titlebar);
	ui->layout_directory->addWidget(d_ptr->m_directoryWidget);
	ui->layout_display->addWidget(d_ptr->m_widget);
	ui->layout_statusbar->addWidget(d_ptr->m_widget1);

	d_ptr->m_titlebar->setMouseTracking(true);
	d_ptr->m_directoryWidget->setMouseTracking(true);
	d_ptr->m_widget->setMouseTracking(true);
	d_ptr->m_widget1->setMouseTracking(true);
}

