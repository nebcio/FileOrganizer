#ifndef UI_GROUPPANEL_H
#define UI_GROUPPANEL_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include "grouppanel.h"

#include <QDebug>

QT_BEGIN_NAMESPACE

class Ui_GroupPanel {
public:
    QVBoxLayout *m_layoutV_names;
    QVBoxLayout *m_layoutV_inputs;
    QHBoxLayout *m_layoutH_right_bott;
    QHBoxLayout *m_layoutH;

    QFrame *m_frame;
    QWidget *m_left_widget;
    QWidget *m_right_widget;
    QWidget *m_right_bott_widget;

    QLabel *m_phrase;   // moze qdate?
    QLabel *m_named;
    QLabel *m_created;
    QLabel *m_modified;
    QLabel *m_other;

    QLineEdit *m_ph_lineedit;
    QLineEdit *m_nm_lineedit;
    QLineEdit *m_cr_lineedit;
    QLineEdit *m_mod_lineedit;
    QLineEdit *m_ot_lineedit;

    QPushButton *m_toFile_button;
    QPushButton *m_toNCat_button;

    void setupUi(GroupPanel *GroupPanel) {
        if (GroupPanel->objectName().isEmpty())
            GroupPanel->setObjectName(QString::fromUtf8("GroupPanel"));
        GroupPanel->setMouseTracking(true);
        GroupPanel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        GroupPanel->setAutoFillBackground(true);

        m_frame = new QFrame(GroupPanel); {
            m_frame->setStyleSheet("border: 1px solid #A19841;");
            m_frame->setContentsMargins(0,0,0,0);
            m_frame->setMinimumSize(550, 200);
        }

        m_left_widget = new QWidget(GroupPanel); {
            m_phrase = new QLabel("PHRASE", GroupPanel); {
                m_phrase->setFixedHeight(25);
                m_phrase->setStyleSheet("color: #82745B;");
            }

            m_named = new QLabel("NAME", GroupPanel); {
                m_named->setFixedHeight(25);
                m_named->setStyleSheet("color: #82745B;");
            }

            m_created = new QLabel("CREATED", GroupPanel); {
                m_created->setFixedHeight(25);
                m_created->setStyleSheet("color: #82745B;");
            }

            m_modified = new QLabel("MODIFIED", GroupPanel); {
                m_modified->setFixedHeight(25);
                m_modified->setStyleSheet("color: #82745B;");
            }

            m_other = new QLabel("OTHER", GroupPanel); {
                m_other->setFixedHeight(25);
                m_other->setStyleSheet("color: #82745B;");
            }


            m_layoutV_names = new QVBoxLayout(GroupPanel); {
                m_layoutV_names->addWidget(m_phrase);
                m_layoutV_names->addWidget(m_named);
                m_layoutV_names->addWidget(m_created);
                m_layoutV_names->addWidget(m_modified);
                m_layoutV_names->addWidget(m_other);
            }

            m_left_widget->setLayout(m_layoutV_names);
        }

        m_right_widget = new QWidget(GroupPanel); {
            m_ph_lineedit = new QLineEdit(GroupPanel); {
                m_ph_lineedit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
                m_ph_lineedit->setFixedHeight(25);
                m_ph_lineedit->setStyleSheet("color: #999; background: #3C3C3C;");
            }

            m_nm_lineedit = new QLineEdit(GroupPanel); {
                m_nm_lineedit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
                m_nm_lineedit->setFixedHeight(25);
                m_nm_lineedit->setStyleSheet("color: #999; background: #3C3C3C;");
            }

            m_cr_lineedit = new QLineEdit(GroupPanel); {
                m_cr_lineedit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
                m_cr_lineedit->setFixedHeight(25);
                m_cr_lineedit->setStyleSheet("color: #999; background: #3C3C3C;");
            }

            m_mod_lineedit = new QLineEdit(GroupPanel); {
                m_mod_lineedit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
                m_mod_lineedit->setFixedHeight(25);
                m_mod_lineedit->setStyleSheet("color: #999; background: #3C3C3C;");
            }

            m_right_bott_widget = new QWidget(GroupPanel); {
                m_toFile_button = new QPushButton("toFile", GroupPanel); {
                    m_toFile_button->setStyleSheet("color: #82745B;");
                    m_toFile_button->setToolTip("to new file");
                }

                m_toNCat_button = new QPushButton("toNCat", GroupPanel); {
                    m_toNCat_button->setStyleSheet("color: #82745B;");
                    m_toNCat_button->setToolTip("to new category");
                }

                m_ot_lineedit = new QLineEdit(GroupPanel); {
                    m_ot_lineedit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
                    m_ot_lineedit->setFixedHeight(25);
                    m_ot_lineedit->setStyleSheet("color: #999; background: #3C3C3C;");
                }

                m_layoutH_right_bott = new QHBoxLayout(GroupPanel); {
                    m_layoutH_right_bott->addWidget(m_ot_lineedit);
                    m_layoutH_right_bott->addWidget(m_toFile_button);
                    m_layoutH_right_bott->addWidget(m_toNCat_button);
                    m_layoutH_right_bott->setSpacing(20);
                    m_layoutH_right_bott->setContentsMargins(0,0,0,0);
                }

                m_right_bott_widget->setLayout(m_layoutH_right_bott);
            }

            m_layoutV_inputs = new QVBoxLayout(GroupPanel); {
                m_layoutV_inputs->addWidget(m_ph_lineedit);
                m_layoutV_inputs->addWidget(m_nm_lineedit);
                m_layoutV_inputs->addWidget(m_cr_lineedit);
                m_layoutV_inputs->addWidget(m_mod_lineedit);
                m_layoutV_inputs->addWidget(m_right_bott_widget);
            }

            m_right_widget->setLayout(m_layoutV_inputs);
            m_right_widget->setStyleSheet("border: none;");
        }

        m_layoutH = new QHBoxLayout(GroupPanel); {
            m_layoutH->addWidget(m_left_widget);
            m_layoutH->addWidget(m_right_widget);
            m_layoutH->setContentsMargins(10,10,10,10);
        }

        GroupPanel->setFixedSize(550, 200);
        GroupPanel->setContentsMargins(0,0,0,0);

        QMetaObject::connectSlotsByName(GroupPanel);
    } // setupUi
};

namespace Ui {
class GroupPanel: public Ui_GroupPanel {};
} // namespace Ui
QT_END_NAMESPACE
#endif // UI_GROUPPANEL_H
