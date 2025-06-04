#pragma once

#include <QWidget>
#include <QMouseEvent>

class NavigationWidget  : public QWidget
{
	Q_OBJECT

public:
	NavigationWidget(QWidget *parent = 0);
	~NavigationWidget();

    void addItem(const QString& title);
    void setWidth(const int& width);
    void setBackgroundColor(const QString& color);
    void setSelectColor(const QString& color);
    void setRowHeight(const int& height);
    void setColWidth(const int& width);
    void setcurrentIndex(const int& currentIndex);
protected:
    void paintEvent(QPaintEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);

private:
    QList<QString> listItems;
    QString backgroundColor;
    QString selectedColor;
    int rowHeight;
    int colWidth;
    int m_currentIndex;

signals:
    void currentItemChanged(const int& index);
};

