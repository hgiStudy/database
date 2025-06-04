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
	void region(const QPoint& currentGlobalPoint);  //����λ��,�ı���
protected:
	//��갴���ƶ����ͷ��¼�
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;

private:
	Ui::FramelessWidgetClass ui;
	QPoint m_movePoint;  //����λ��
	bool isLeftPressDown;  // �ж�����Ƿ���
	Direction dir;        // ���ڴ�С�ı�ʱ����¼�ı䷽��
};

