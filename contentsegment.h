#ifndef CONTENTSEGMENT_H
#define CONTENTSEGMENT_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ContentSegment; }
QT_END_NAMESPACE

class ContentSegment : public QWidget
{
    Q_OBJECT
public:
    explicit ContentSegment(QWidget *parent = nullptr);

private:
    Ui::ContentSegment *ui;

signals:

};

#endif // CONTENTSEGMENT_H
