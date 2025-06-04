#include "navigationwidget.h"
#include <QPainter>
#include <QDebug>

NavigationWidget::NavigationWidget(QWidget *parent)
	: QWidget(parent)
{
    backgroundColor = "#9ACBD0";
    selectedColor = "#2973B2";
    rowHeight = 40;
    m_currentIndex = 0;

    setMouseTracking(true);
    setFixedHeight(40);
}

NavigationWidget::~NavigationWidget()
{}

void NavigationWidget::addItem(const QString& title)
{
    listItems << title;

    update();
}

void NavigationWidget::setWidth(const int& width)
{
    setFixedWidth(width);
}

void NavigationWidget::setBackgroundColor(const QString& color)
{
    backgroundColor = color;

    update();
}

void NavigationWidget::setSelectColor(const QString& color)
{
    selectedColor = color;

    update();
}

void NavigationWidget::setRowHeight(const int& height)
{
    rowHeight = height;

    update();
}

void NavigationWidget::setColWidth(const int& width)
{
    colWidth = width;
    update();
}

void NavigationWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // Draw background color.
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(backgroundColor));
    painter.drawRect(rect());

    // Draw Items
    int count = 0;
    for (const QString& str : listItems) {
        QPainterPath itemPath;
        itemPath.addRect(QRect(count * colWidth, 0, colWidth, height()));

        if (m_currentIndex == count) {
            /* painter.setPen("#000000");*/
            painter.setPen("#FFFFFF");
            painter.fillPath(itemPath, QColor(selectedColor));
        }
        else {
            /* painter.setPen("#202020");*/
            painter.setPen("#000000");
            painter.fillPath(itemPath, QColor(backgroundColor));
        }

        painter.drawText(QRect(count * colWidth, 0, colWidth, height()), Qt::AlignVCenter | Qt::AlignHCenter, str);

        ++count;
    }
}

void NavigationWidget::mouseMoveEvent(QMouseEvent* e)
{
    if (e->x() / colWidth < listItems.count()) {
        // qDebug() << e->y() / rowHeight;
    }
}

void NavigationWidget::mousePressEvent(QMouseEvent* e)
{
    if (e->x() / colWidth < listItems.count()) {
        m_currentIndex = e->x() / colWidth;

        emit currentItemChanged(m_currentIndex);

        update();
    }
}

void NavigationWidget::mouseReleaseEvent(QMouseEvent* e)
{
    Q_UNUSED(e);
}

void NavigationWidget::setcurrentIndex(const int& currentIndex)
{
    m_currentIndex = currentIndex;
}

