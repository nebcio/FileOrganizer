#ifndef UI_LEFTPANEL_H
#define UI_LEFTPANEL_H

#include <QWidget>
#include <QtGui/QIcon>
#include <QPushButton>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include "leftpanel.h"

QT_BEGIN_NAMESPACE
class Ui_LeftPanel {
public:

    QWidget *m_top_widget;
    QWidget *m_central_widget;
    QWidget *m_bottom_widget;

    QVBoxLayout *m_layout_vlp;
    QGridLayout *m_top_layout_g;
    QVBoxLayout *m_central_layout_v;
    QHBoxLayout *m_bottom_layout_h;

    QPushButton *m_new_kat_button;
    QPushButton *m_collapse_kat_button;
    QPushButton *m_new_file_button;
    QTreeWidget *m_kat_tree;
    QPushButton *m_sort;
    QPushButton *m_group;

    void setupUi(LeftPanel *LeftPanel) {
        if (LeftPanel->objectName().isEmpty())
            LeftPanel->setObjectName(QString::fromUtf8("LeftPanel"));
        //LeftPanel->setMouseTracking(true);
        LeftPanel->setAutoFillBackground(true);

        m_top_widget = new QWidget(LeftPanel); {
            m_new_kat_button = new QPushButton(LeftPanel); {
                m_new_kat_button->setIcon(QIcon(":/y_triangle.png"));
                m_new_kat_button->setIconSize(QSize(25, 25));
                m_new_kat_button->setToolTip("New category");
                m_new_kat_button->setFixedSize(30, 30);
            }

            m_collapse_kat_button = new QPushButton(LeftPanel); {
                m_collapse_kat_button->setIcon(QIcon(":/y_triangle.png"));
                m_collapse_kat_button->setIconSize(QSize(25, 25));
                m_collapse_kat_button->setToolTip("Collapse category");
                m_collapse_kat_button->setFixedSize(30, 30);
            }

            m_new_file_button = new QPushButton(LeftPanel); {
                m_new_file_button->setIcon(QIcon(":/b_triangle.png"));
                m_new_file_button->setIconSize(QSize(25, 25));
                m_new_file_button->setToolTip("New file");
                m_new_file_button->setFixedSize(30, 30);
            }

            m_top_layout_g = new QGridLayout(LeftPanel); {
                m_top_layout_g->addWidget(m_new_kat_button, 0, 0, 0, 0);
                m_top_layout_g->addWidget(m_collapse_kat_button, 0, 1, 0, 0);
                m_top_layout_g->addWidget(m_new_file_button, 0, 5, 0, 0);
                m_top_layout_g->setSpacing(0);
                m_top_layout_g->setContentsMargins(4,4,4,4);
            }

            m_top_widget->setLayout(m_top_layout_g);
        }

        m_central_widget = new QWidget(LeftPanel); {

            m_kat_tree = new QTreeWidget(LeftPanel); {
                m_kat_tree->setFixedWidth(250);
                m_kat_tree->setHeaderHidden(true);
                m_kat_tree->setDragEnabled(true);
                m_kat_tree->setAcceptDrops(true);
                m_kat_tree->setStyleSheet("color: #A19841; border: none; QTreeWidget::item { margin: 0px 5px 0px 5px; }");
                //m_kat_tree->setColumnCount(1);

                for (int i = 0; i < 5; ++i) {
                    QTreeWidgetItem* item = new QTreeWidgetItem(static_cast<QTreeWidget *>(nullptr), QStringList(QString("KAT %1").arg(i)));
                    item->addChild(new QTreeWidgetItem(static_cast<QTreeWidget *>(nullptr), QStringList(QString("File %1").arg(i))));
                    m_kat_tree->addTopLevelItem(item);
                    item->setExpanded(true);
                }
                for (int i = 1; i < 4; ++i)
                    m_kat_tree->topLevelItem(2)->addChild(new QTreeWidgetItem(m_kat_tree, QStringList(QString("File %1").arg(i))));
            }

            m_central_layout_v = new QVBoxLayout(LeftPanel); {
                m_central_layout_v->addWidget(m_kat_tree);
                m_central_layout_v->setSpacing(0);
                m_central_layout_v->setContentsMargins(0,0,0,0);
            }

            m_central_widget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
            m_central_widget->setFixedWidth(250);
            m_central_widget->setLayout(m_central_layout_v);
        }

        m_bottom_widget = new QWidget(LeftPanel); {

            m_sort = new QPushButton("SORT", LeftPanel); {
                m_sort->setFixedSize(125, 50);
                m_sort->setStyleSheet("color: #aba038;");
                m_sort->setToolTip("Sort");
            }

            m_group = new QPushButton("GROUP", LeftPanel); {
                m_group->setFixedSize(125, 50);
                m_group->setStyleSheet("color: #aba038;");
                m_group->setToolTip("Group files");
            }

            m_bottom_layout_h = new QHBoxLayout(LeftPanel); {
                m_bottom_layout_h->addWidget(m_sort);
                m_bottom_layout_h->addWidget(m_group);
                m_bottom_layout_h->setContentsMargins(0,0,0,0);
            }

            m_bottom_widget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            m_bottom_widget->setFixedWidth(250);
            m_bottom_widget->setLayout(m_bottom_layout_h);
        }

        m_layout_vlp = new QVBoxLayout(LeftPanel); {
            m_layout_vlp->addWidget(m_top_widget);
            m_layout_vlp->addWidget(m_central_widget);
            m_layout_vlp->addWidget(m_bottom_widget);
            m_layout_vlp->setSpacing(1);
            m_layout_vlp->setContentsMargins(0, 0, 0, 0);
        }

        LeftPanel->setLayout(m_layout_vlp);
        QMetaObject::connectSlotsByName(LeftPanel);
    } // setupUi

};

namespace Ui {
class LeftPanel: public Ui_LeftPanel {};
} // namespace Ui
QT_END_NAMESPACE
#endif // UI_LEFTPANEL_H
