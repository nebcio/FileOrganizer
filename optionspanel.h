#ifndef OPTIONSPANEL_H
#define OPTIONSPANEL_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class OptionsPanel; }
QT_END_NAMESPACE

class OptionsPanel : public QWidget
{
    Q_OBJECT
public:
    explicit OptionsPanel(QWidget *parent = nullptr);
    // empty state

private:
    Ui::OptionsPanel *ui;

//signals:

};

#endif // OPTIONSPANEL_H
