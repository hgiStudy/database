#include "framelesswidget.h"

FramelessWidget::FramelessWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	isLeftPressDown = false;
	this->dir = NONE;
	//ȥ����������������
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);
	setMouseTracking(true);

}

FramelessWidget::~FramelessWidget()
{}

void FramelessWidget::region(const QPoint& currentGlobalPoint)
{
    QRect rect = this->rect();
    QPoint tl = mapToGlobal(rect.topLeft());
    QPoint rb = mapToGlobal(rect.bottomRight());
    int x = currentGlobalPoint.x();
    int y = currentGlobalPoint.y();

    if (tl.x() + PADDING >= x && tl.x() <= x && tl.y() + PADDING >= y && tl.y() <= y) {
        // ���Ͻ�
        dir = LEFTTOP;
        this->setCursor(QCursor(Qt::SizeFDiagCursor));
    }
    else if (x >= rb.x() - PADDING && x <= rb.x() && y >= rb.y() - PADDING && y <= rb.y()) {
        // ���½�
        dir = RIGHTBOTTOM;
        this->setCursor(QCursor(Qt::SizeFDiagCursor));
    }
    else if (x <= tl.x() + PADDING && x >= tl.x() && y >= rb.y() - PADDING && y <= rb.y()) {
        //���½�
        dir = LEFTBOTTOM;
        this->setCursor(QCursor(Qt::SizeBDiagCursor));
    }
    else if (x <= rb.x() && x >= rb.x() - PADDING && y >= tl.y() && y <= tl.y() + PADDING) {
        // ���Ͻ�
        dir = RIGHTTOP;
        this->setCursor(QCursor(Qt::SizeBDiagCursor));
    }
    else if (x <= tl.x() + PADDING && x >= tl.x()) {
        // ���
        dir = LEFT;
        this->setCursor(QCursor(Qt::SizeHorCursor));
    }
    else if (x <= rb.x() && x >= rb.x() - PADDING) {
        // �ұ�
        dir = RIGHT;
        this->setCursor(QCursor(Qt::SizeHorCursor));
    }
    else if (y >= tl.y() && y <= tl.y() + PADDING) {
        // �ϱ�
        dir = UP;
        this->setCursor(QCursor(Qt::SizeVerCursor));
    }
    else if (y <= rb.y() && y >= rb.y() - PADDING) {
        // �±�
        dir = DOWN;
        this->setCursor(QCursor(Qt::SizeVerCursor));
    }
    else {
        // Ĭ��
        dir = NONE;
        this->setCursor(QCursor(Qt::ArrowCursor));
    }
}


//��������¼�����д
//��갴���¼�
void FramelessWidget::mousePressEvent(QMouseEvent* event)
{
    switch (event->button())
    {
    case Qt::LeftButton:
        isLeftPressDown = true;

        if (dir != NONE)
        {
            this->mouseGrabber(); //���ص�ǰץȡ�������Ĵ���
        }
        else
        {
            m_movePoint = event->globalPos() - this->frameGeometry().topLeft();
            //globalPos()���λ�ã�topLeft()�������Ͻǵ�λ��
        }
        break;
    case Qt::RightButton:
        this->setWindowState(Qt::WindowMinimized);
        break;
    default:
        QWidget::mousePressEvent(event);
    }
}



//����ƶ��¼�
void FramelessWidget::mouseMoveEvent(QMouseEvent* event)
{
    QPoint gloPoint = event->globalPos();
    QRect rect = this->rect();
    QPoint tl = mapToGlobal(rect.topLeft());
    QPoint rb = mapToGlobal(rect.bottomRight());

    if (!isLeftPressDown) {
        this->region(gloPoint);
    }
    else {

        if (dir != NONE) {
            QRect rMove(tl, rb);

            switch (dir) {
            case LEFT:
                if (rb.x() - gloPoint.x() <= this->minimumWidth())
                    rMove.setX(tl.x());
                else
                    rMove.setX(gloPoint.x());
                break;
            case RIGHT:
                rMove.setWidth(gloPoint.x() - tl.x());
                break;
            case UP:
                if (rb.y() - gloPoint.y() <= this->minimumHeight())
                    rMove.setY(tl.y());
                else
                    rMove.setY(gloPoint.y());
                break;
            case DOWN:
                rMove.setHeight(gloPoint.y() - tl.y());
                break;
            case LEFTTOP:
                if (rb.x() - gloPoint.x() <= this->minimumWidth())
                    rMove.setX(tl.x());
                else
                    rMove.setX(gloPoint.x());
                if (rb.y() - gloPoint.y() <= this->minimumHeight())
                    rMove.setY(tl.y());
                else
                    rMove.setY(gloPoint.y());
                break;
            case RIGHTTOP:
                rMove.setWidth(gloPoint.x() - tl.x());
                rMove.setY(gloPoint.y());
                break;
            case LEFTBOTTOM:
                rMove.setX(gloPoint.x());
                rMove.setHeight(gloPoint.y() - tl.y());
                break;
            case RIGHTBOTTOM:
                rMove.setWidth(gloPoint.x() - tl.x());
                rMove.setHeight(gloPoint.y() - tl.y());
                break;
            default:

                break;
            }
            this->setGeometry(rMove);
        }
        else {
            move(event->globalPos() - m_movePoint);
            event->accept();
        }
    }
    QWidget::mouseMoveEvent(event);
}


//����ͷ��¼�
void FramelessWidget::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        isLeftPressDown = false;
        if (dir != NONE)
        {
            this->releaseMouse(); //�ͷ����ץȡ
            this->setCursor(QCursor(Qt::ArrowCursor));
            dir = NONE; //��������ָ��
        }
    }
}
