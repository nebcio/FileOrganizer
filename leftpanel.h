#ifndef LEFTPANEL_H
#define LEFTPANEL_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class LeftPanel; }
QT_END_NAMESPACE

class LeftPanel : public QWidget
{
    Q_OBJECT
public:
    explicit LeftPanel(QWidget *parent = nullptr);


private:
    Ui::LeftPanel *ui;
    void showGroupPanel();
    void showSortPanel();

signals:
    void signalShowGroupPanel(QPoint pos);
    void signalShowSortPanel(QPoint pos);

};

#endif // LEFTPANEL_H
