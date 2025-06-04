#pragma once

#include <QWidget>
#include "ui_framelesswidget.h"
#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <QCursor>
#include <QRect>

#define PADDING 2
enum Direction { UP = 0, DOWN = 1, LEFT, RIGHT, LEFTTOP, LEFTBOTTOM, RIGHTBOTTOM, RIGHTTOP, NONE };

class FramelessWidget : public QWidget
{
	Q_OBJECT

public:
	FramelessWidget(QWidget *parent = nullptr);
	~FramelessWidget();
	void region(const QPoint& currentGlobalPoint);  //鼠标的位置,改变光标
protected:
	//鼠标按下移动及释放事件
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;

private:
	Ui::FramelessWidgetClass ui;
	QPoint m_movePoint;  //鼠标的位置
	bool isLeftPressDown;  // 判断左键是否按下
	Direction dir;        // 窗口大小改变时，记录改变方向
};

