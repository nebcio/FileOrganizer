#ifndef UI_CONTENTSEGMENT_H
#define UI_CONTENTSEGMENT_H
#include <QtWidgets/QWidget>
#include <QLabel>
#include <QtGui/QIcon>
#include <QPixmap>
#include <QGridLayout>
#include <QPushButton>
//#include <QtWidgets/QVBoxLayout>
#include "contentsegment.h"

QT_BEGIN_NAMESPACE
class Ui_ContentSegment {
public:

    QHBoxLayout *m_layout_h;

    void setupUi(ContentSegment *ContentSegment) {
        if (ContentSegment->objectName().isEmpty())
            ContentSegment->setObjectName(QString::fromUtf8("ContentSegment"));
        ContentSegment->setMouseTracking(true);
        ContentSegment->setAutoFillBackground(true);


        m_layout_h = new QHBoxLayout(ContentSegment); {
            m_layout_h->setSpacing(0);
            m_layout_h->setContentsMargins(0,0,0,0);
        }

        ContentSegment->setLayout(m_layout_h);
        QMetaObject::connectSlotsByName(ContentSegment);
    } // setupUi


};

namespace Ui {
    class ContentSegment: public Ui_ContentSegment {};
} // namespace Ui
QT_END_NAMESPACE
#endif // UI_CONTENTSEGMENT_H
