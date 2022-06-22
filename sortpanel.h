#ifndef SORTPANEL_H
#define SORTPANEL_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class SortPanel; }
QT_END_NAMESPACE

class SortPanel : public QWidget
{
    Q_OBJECT
public:
    explicit SortPanel(QWidget *parent = nullptr);

private:
    Ui::SortPanel *ui;

};

#endif // SORTPANEL_H
