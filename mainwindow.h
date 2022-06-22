#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QCoreApplication>
#include <QMouseEvent>
#include <qt_windows.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    //
private:
    Ui::MainWindow *ui;

    bool resizing = false;
    int start_x;
    int start_y;
    QPoint start_pos;

    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *e) override;

protected:
   bool nativeEvent(const QByteArray &eventType, void *message, long *result) override
   {
     MSG *msg = static_cast<MSG*>(message);
     if (msg && msg->message == WM_NCCALCSIZE) {
       // Just return 0 and mark event as handled. This will draw the widget contents
       // into the full size of the frame, instead of leaving room for it.
       *result = 0;
       return true;
     }
     return QWidget::nativeEvent(eventType, message, result);
   }

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void exitApp();
    void minimizeApp();
    void maximizeApp();

    void showSortPanel(QPoint pos);
    void showGroupPanel(QPoint pos);
};
#endif // MAINWINDOW_H
