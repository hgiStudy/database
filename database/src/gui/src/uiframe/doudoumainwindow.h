#pragma once

#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <QCursor>
#include <QRect>
#include "ui_doudoumainwindow.h"

#define PADDING 2
enum Direction { UP = 0, DOWN = 1, LEFT, RIGHT, LEFTTOP, LEFTBOTTOM, RIGHTBOTTOM, RIGHTTOP, NONE };


class DouDouMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	DouDouMainWindow(QWidget *parent = nullptr);
	~DouDouMainWindow();
    void region(const QPoint& currentGlobalPoint);  //����λ��,�ı���
protected:
    //��갴���ƶ����ͷ��¼�
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;


private:
	Ui::DouDouMainWindowClass ui;
    QPoint m_movePoint;  //����λ��
    bool isLeftPressDown;  // �ж�����Ƿ���
    Direction dir;        // ���ڴ�С�ı�ʱ����¼�ı䷽��
};
