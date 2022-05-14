#ifndef GROUPPANEL_H
#define GROUPPANEL_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class GroupPanel; }
QT_END_NAMESPACE

class GroupPanel : public QWidget
{
    Q_OBJECT
public:
    explicit GroupPanel(QWidget *parent = nullptr);

private:
    Ui::GroupPanel *ui;

signals:

};

#endif // GROUPPANEL_H
