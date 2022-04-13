#include "topbar.h"
#include "ui_topbar.h"

TopBar::TopBar(QWidget *parent) : QWidget(parent), ui(new Ui::TopBar) {
    ui->setupUi(this);
}

void TopBar::onButtonExitClicked() {
    emit signalExit();
}

void TopBar::onButtonMinClicked() {
    // emit signalShowMinimized();
}

void TopBar::mousePressEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton){
        //parent_moving = true;
        //m_startMovePos = event->pos();
    }
}
void TopBar::mouseMoveEvent(QMouseEvent *event) {
    //if (parent_moving) m_parent->move(event->globalPos() - m_startMovePos);

    /*if (parent_moving && m_parent->pos().x() > QGuiApplication::primaryScreen()->geometry().width() - m_parent->width()) {
        m_parent->move(QGuiApplication::primaryScreen()->geometry().width() - m_parent->width(), m_parent->pos().y());
    }
    else if (parent_moving && m_parent->pos().x() < 0){
        m_parent->move(0, m_parent->pos().y());
    }

    if (parent_moving && m_parent->pos().y() > QGuiApplication::primaryScreen()->geometry().height() - m_parent->height()) {
        m_parent->move(m_parent->pos().x(), QGuiApplication::primaryScreen()->geometry().height() - m_parent->height());
    }
    else if (parent_moving && m_parent->pos().y() < 0){
        m_parent->move(m_parent->pos().x(), 0);
    }*/
}
void TopBar::mouseReleaseEvent(QMouseEvent *event) {
    //parent_moving = false;
}
