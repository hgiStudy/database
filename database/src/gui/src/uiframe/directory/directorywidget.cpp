#include "directorywidget.h"

DirectoryWidget::DirectoryWidget(QWidget *parent)
	: QWidget(parent)
{
	initUi();
}

DirectoryWidget::~DirectoryWidget()
{}

void DirectoryWidget::initUi()
{
	m_mainLayout = new QVBoxLayout(this);
    m_navigationWidget = new NavigationWidget;

    m_navigationWidget->setColWidth(150);
    m_navigationWidget->addItem(tr("homepage"));
    m_navigationWidget->addItem(tr("edit"));
    /*  navigationWidget->addItem("view");*/
    m_navigationWidget->addItem(tr("system"));
    m_navigationWidget->addItem(tr("help"));

    m_navigationWidget->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->addWidget(m_navigationWidget);

    setLayout(m_mainLayout);
    m_mainLayout->setContentsMargins(0, 0, 0, 0);

    connect(m_navigationWidget, &NavigationWidget::currentItemChanged, this, &DirectoryWidget::currentItemChanged);
}

