#ifndef UI_TOPBAR_H
#define UI_TOPBAR_H

#include <QWidget>
#include <QLabel>
#include <QIcon>
#include <QPushButton>
//#include <QHBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QGraphicsDropShadowEffect>
#include <QPixmap>
#include "optionspanel.h"
#include "topbar.h"

#include <QDebug>

QT_BEGIN_NAMESPACE

class Ui_TopBar {
public:
    QHBoxLayout *left_layout_h;
    QWidget *m_left_widget;
    QLabel *m_title;
    QPushButton *m_setting_button;
    QPushButton *m_help_button;

    OptionsPanel *m_option_widget;

    QHBoxLayout *right_layout_h;
    QWidget *m_right_widget;
    QPushButton *m_exit_button;
    QPushButton *m_min_button;
    QPushButton *m_full_button;

    QHBoxLayout *layout_h;

    QPoint m_restorePos;    // maximize and minimize variables;
    QSize m_restoreSize;

    bool parent_moving;
    QPoint m_startMovePos;

    void setupUi(TopBar *TopBar) {
        if (TopBar->objectName().isEmpty())
            TopBar->setObjectName(QString::fromUtf8("TopBar"));
        //TopBar->setMouseTracking(true);
        TopBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        TopBar->setAutoFillBackground(true);

        //left
        m_left_widget = new QWidget(TopBar); {
            m_title = new QLabel("FO", TopBar);{
                m_title->setProperty("type", "title");
                m_title->setStyleSheet("color: #988835; text-align: right;");
                m_title->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            }

            m_help_button = new QPushButton("?", TopBar); {
                m_help_button->setObjectName("help_button");
                m_help_button->setFixedSize(QSize(30, 30));
                m_help_button->setStyleSheet("background-color: #7a7245; border-radius: 15px;");
            }

            m_setting_button = new QPushButton(TopBar);{
                m_setting_button->setObjectName("setting_button");
                m_setting_button->setFixedSize(QSize(30, 30));
                m_setting_button->setText("S");
                m_setting_button->setStyleSheet("background-color: #7a7245; border-radius: 15px;");
            }

            left_layout_h = new QHBoxLayout(); {
                //left_layout_h->insertStretch(1, 500); // co to xDDD co jak laczenie chyba
                left_layout_h->setSpacing(5);
                left_layout_h->setContentsMargins(10,0,5,0);
                left_layout_h->addWidget(m_title);
                left_layout_h->addWidget(m_help_button);
                left_layout_h->addWidget(m_setting_button);}

            m_left_widget->setLayout(left_layout_h);
            m_left_widget->setFixedHeight(50);
            m_left_widget->setFixedWidth(250);
            m_left_widget->setContentsMargins(0,0,0,0);
            m_left_widget->setStyleSheet("background-color: #0f0f0f;");

            QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect; {
                effect->setBlurRadius(5);
                effect->setXOffset(0);
                effect->setYOffset(0);
                effect->setColor(Qt::black);
                m_left_widget->setGraphicsEffect(effect); }
        }

        // central
        m_option_widget = new OptionsPanel(TopBar);{
            m_option_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
            m_option_widget->setFixedHeight(50);
        }

        // right
        m_right_widget = new QWidget(TopBar); {
            m_min_button = new QPushButton(TopBar); {
                m_min_button->setObjectName("min_button");
                m_min_button->setFixedSize(QSize(30, 30));
                m_min_button->setText("_");
                m_min_button->setToolTip("Hide window");
                m_min_button->setStyleSheet("background-color: #7a7245; border-radius: 15px;");}

            m_full_button = new QPushButton(TopBar); {
                m_full_button->setObjectName("full_button");
                m_full_button->setFixedSize(QSize(30, 30));
                m_full_button->setIcon(QIcon(":/max.png"));
                m_full_button->setIconSize(QSize(10, 10));
                m_full_button->setToolTip("Maximize");
                m_full_button->setStyleSheet("background-color: #7a7245; border-radius: 15px;");}

            m_exit_button = new QPushButton(TopBar);{
                m_exit_button->setObjectName("exit_button");
                m_exit_button->setFixedSize(QSize(30, 30));
                m_exit_button->setText("X");
                m_exit_button->setStyleSheet("background-color: #7a7245; border-radius: 15px;");
                m_exit_button->setToolTip("Exit");}

            right_layout_h = new QHBoxLayout(TopBar); {
                right_layout_h->addWidget(m_min_button);
                right_layout_h->addWidget(m_full_button);
                right_layout_h->addWidget(m_exit_button);
                right_layout_h->setSpacing(0);
                right_layout_h->setContentsMargins(0,0,0,0);}

            m_right_widget->setLayout(right_layout_h);
            m_right_widget->setFixedHeight(50);
            m_right_widget->setFixedWidth(110);
            m_right_widget->setContentsMargins(0,0,0,0);
            m_right_widget->setStyleSheet("background-color: #0f0f0f;");
        }

        layout_h = new QHBoxLayout(TopBar); {
            layout_h->addWidget(m_left_widget);
            layout_h->addWidget(m_option_widget);
            layout_h->addWidget(m_right_widget);
            layout_h->setSpacing(0);
            layout_h->setContentsMargins(0,0,0,0);
        }

        TopBar->setContentsMargins(0,0,0,0);
        //TopBar->setAttribute(Qt::WA_DeleteOnClose, true);

        QMetaObject::connectSlotsByName(TopBar);
    } // setupUi


};

namespace Ui {
class TopBar: public Ui_TopBar {};
} // namespace Ui
QT_END_NAMESPACE
#endif // UI_TOPBAR_H
