#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QFrame>
#include <QtGui/QIcon>
#include <QScreen>
#include <QGraphicsDropShadowEffect>
#include "topbar.h"
#include "leftpanel.h"
#include "contentsegment.h"
#include "sortpanel.h"
#include "grouppanel.h"
#include "mainwindow.h"

#include <QDebug>

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
public:
    QWidget *centralwidget;
    QVBoxLayout *layout_v;
    QWidget *m_bottom_widget;
    QHBoxLayout *layout_h;

    TopBar *m_top_bar;
    QFrame *m_top_bar_bottom_line; // xD

    LeftPanel *m_left_panel;
    ContentSegment *m_content_segment;

        SortPanel *m_sortpanel;
        GroupPanel *m_grouppanel;

    void setupUi(MainWindow *MainWindow) {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        //MainWindow->setWindowState(Qt::WindowMaximized);
        //MainWindow->setGeometry(0, 0, MainWindow->screen()->availableGeometry().width(), MainWindow->screen()->availableGeometry().height());
        MainWindow->setMinimumSize(QSize(550, 550));
        MainWindow->setMouseTracking(true);

        centralwidget = new QWidget(MainWindow); {
            centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
            centralwidget->setStyleSheet("background-color: #101010;");

            m_top_bar = new TopBar(MainWindow); {
                m_top_bar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
                m_top_bar->setStyleSheet("background-color: #0f0f0f;"); // border-bottom: 1px solid ;
                m_top_bar->setContentsMargins(0,0,0,0);
            }

            m_top_bar_bottom_line = new QFrame(centralwidget); {
                m_top_bar_bottom_line->setFrameShape(QFrame::HLine);
                m_top_bar_bottom_line->setStyleSheet("color: #766b43;");
                m_top_bar_bottom_line->setContentsMargins(0,0,0,0);
            }

            m_bottom_widget = new QWidget(centralwidget); {
                m_left_panel = new LeftPanel(centralwidget); {
                    m_left_panel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
                    m_left_panel->setFixedWidth(250);
                    m_left_panel->setStyleSheet("background-color: #0a0a0a;");
                }
                m_content_segment = new ContentSegment(centralwidget); {
                    m_content_segment->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                }
                layout_h = new QHBoxLayout(centralwidget); {
                    layout_h->setContentsMargins(0, 0, 0, 0);
                    layout_h->setSpacing(1);
                    layout_h->addWidget(m_left_panel);
                    layout_h->addWidget(m_content_segment);
                }

                m_bottom_widget->setLayout(layout_h);
            }

            m_sortpanel = new SortPanel(centralwidget); {
                m_sortpanel->setStyleSheet("background-color: #0f0f0f;");
                m_sortpanel->setGeometry(0, MainWindow->screen()->availableGeometry().height() - 50 - m_sortpanel->height(), m_sortpanel->width(), m_sortpanel->height());
                m_sortpanel->setHidden(true);
            }

            m_grouppanel = new GroupPanel(centralwidget); {
                m_grouppanel->setStyleSheet("background-color: #0f0f0f;");
                m_grouppanel->setGeometry(0, MainWindow->screen()->availableGeometry().height() - 50 - m_grouppanel->height(), m_grouppanel->width(), m_grouppanel->height());
                m_grouppanel->setHidden(true);
                qDebug() << MainWindow->screen()->availableGeometry();
            }

            layout_v = new QVBoxLayout(centralwidget); {
                layout_v->setSpacing(1);
                layout_v->setObjectName(QString::fromUtf8("layout_v"));
                layout_v->setContentsMargins(0, 0, 0, 0);

                layout_v->addWidget(m_top_bar);
                layout_v->addWidget(m_top_bar_bottom_line);
                layout_v->addWidget(m_bottom_widget);
                //layout_v->addWidget(m_centrum);
            }

            centralwidget->setContentsMargins(0,0,0,0);}

        //MainWindow->setContentsMargins(10, 10, 10, 10);
        MainWindow->setCentralWidget(centralwidget);
        MainWindow->setWindowFlags(Qt::FramelessWindowHint);
        MainWindow->setAttribute(Qt::WA_DeleteOnClose, true);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi


};

namespace Ui {
class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
