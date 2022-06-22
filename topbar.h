#ifndef TOPBAR_H
#define TOPBAR_H

#include <QWidget>
#include <QMouseEvent>
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TopBar; }
QT_END_NAMESPACE


class TopBar : public QWidget
{
    Q_OBJECT
public:
    explicit TopBar(MainWindow *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    QPoint m_restorePos;    // maximize and minimize variables;
    QSize m_restoreSize;

    bool parent_moving;
    QPoint m_startMovePos;
    MainWindow *m_parent;

private:
    Ui::TopBar *ui;

signals:
    void signalExit();
    void signalShowMinimized();
    void signalShowMaximized();

protected slots:
    void onButtonExitClicked();
    void onButtonMinClicked(); // minimized
    void onButtonMaxClicked();

};

#endif // TOPBAR_H
