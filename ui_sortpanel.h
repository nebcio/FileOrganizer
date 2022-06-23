#ifndef UI_SORTPANEL_H
#define UI_SORTPANEL_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include "sortpanel.h"

#include <QDebug>

QT_BEGIN_NAMESPACE

class Ui_SortPanel {
public:
    QVBoxLayout *m_layoutV_names;
    QVBoxLayout *m_layoutV_inputs;
    QHBoxLayout *m_layoutH;

    QFrame *m_frame;
    QWidget *m_left_widget;
    QWidget *m_right_widget;

    QLabel *m_categories;
    QLabel *m_by;

    QLineEdit *m_cat_lineedit;
    QLineEdit *m_by_lineedit;

    void setupUi(SortPanel *SortPanel) {
        if (SortPanel->objectName().isEmpty())
            SortPanel->setObjectName(QString::fromUtf8("SortPanel"));
        SortPanel->setMouseTracking(true);
        SortPanel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        SortPanel->setAutoFillBackground(true);

        m_frame = new QFrame(SortPanel); {
            m_frame->setStyleSheet("border: 1px solid #A19841;");
            m_frame->setContentsMargins(0,0,0,0);
            m_frame->setMinimumSize(550, 100);
        }

        m_left_widget = new QWidget(SortPanel); {
            m_categories = new QLabel("CAT", SortPanel); {
                m_categories->setFixedHeight(25);
                m_categories->setStyleSheet("color: #82745B;");
            }

            m_by = new QLabel("BY", SortPanel); {
                m_by->setFixedHeight(25);
                m_by->setStyleSheet("color: #82745B;");
            }

            m_layoutV_names = new QVBoxLayout(SortPanel); {
                m_layoutV_names->addWidget(m_categories);
                m_layoutV_names->addWidget(m_by);
            }

            m_left_widget->setLayout(m_layoutV_names);
        }

        m_right_widget = new QWidget(SortPanel); {
            m_cat_lineedit = new QLineEdit(SortPanel); {
                m_cat_lineedit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
                m_cat_lineedit->setFixedHeight(25);
                m_cat_lineedit->setStyleSheet("color: #999; background: #3C3C3C;");
            }

            m_by_lineedit = new QLineEdit(SortPanel); {
                m_by_lineedit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
                m_by_lineedit->setFixedHeight(25);
                m_by_lineedit->setStyleSheet("color: #999; background: #3C3C3C;");
            }

            m_layoutV_inputs = new QVBoxLayout(SortPanel); {
                m_layoutV_inputs->addWidget(m_cat_lineedit);
                m_layoutV_inputs->addWidget(m_by_lineedit);
            }

            m_right_widget->setLayout(m_layoutV_inputs);
            m_right_widget->setStyleSheet("border: none;");
        }

        m_layoutH = new QHBoxLayout(SortPanel); {
            m_layoutH->addWidget(m_left_widget);
            m_layoutH->addWidget(m_right_widget);
            m_layoutH->setContentsMargins(10,10,10,10);
        }

        SortPanel->setFixedSize(550, 100);
        SortPanel->setContentsMargins(0,0,0,0);

        QMetaObject::connectSlotsByName(SortPanel);
    } // setupUi
};

namespace Ui {
class SortPanel: public Ui_SortPanel {};
} // namespace Ui
QT_END_NAMESPACE
#endif // UI_SORTPANEL_H
