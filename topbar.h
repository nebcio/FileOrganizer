#ifndef TOPBAR_H
#define TOPBAR_H

#include <QWidget>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class TopBar; }
QT_END_NAMESPACE


class TopBar : public QWidget
{
    Q_OBJECT
public:
    explicit TopBar(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

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
