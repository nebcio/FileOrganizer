#ifndef UI_OPTIONSPANEL_H
#define UI_OPTIONSPANEL_H

#include <QtWidgets/QWidget>
#include <QLabel>
#include <QtGui/QIcon>
#include <QPixmap>
#include <QGridLayout>
#include <QPushButton>
//#include <QtWidgets/QVBoxLayout>
#include "optionspanel.h"

QT_BEGIN_NAMESPACE
class Ui_OptionsPanel {
public:

    QGridLayout *layout_g;
    // font size
    // wyswietlanie strony (1 lub 2 na raz, czy ciagiem czy rozdzielac)
    // kolor czcionki
    // kolor strony
    // bold / italic / underline
    // wyrownywanie

    QLabel *m_separator; // (opcje do eksportu/importu
    QLabel *m_import;
    QLabel *m_export;

    void setupUi(OptionsPanel *OptionsPanel) {
        if (OptionsPanel->objectName().isEmpty())
            OptionsPanel->setObjectName(QString::fromUtf8("OptionsPanel"));
        OptionsPanel->setMouseTracking(true);
        OptionsPanel->setAutoFillBackground(true);

        m_separator = new QLabel("SEPARATOR", OptionsPanel); {
            m_separator->setStyleSheet("color: #988835;");
            m_separator->setFixedHeight(50);
            m_separator->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        }

        m_import = new QLabel("IMPORT", OptionsPanel); {
            m_import->setStyleSheet("color: #988835;");
            m_import->setFixedHeight(50);
            m_import->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        }

        m_export = new QLabel("EXPORT", OptionsPanel); {
            m_export->setStyleSheet("color: #988835;");
            m_export->setFixedHeight(50);
            m_export->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        }

        layout_g = new QGridLayout(OptionsPanel); {
            layout_g->addWidget(m_export, 0, 5);
            layout_g->addWidget(m_import, 0, 6);
            layout_g->addWidget(m_separator, 0, 7);
            layout_g->setSpacing(0);
            layout_g->setContentsMargins(0,0,0,0);
        }

        OptionsPanel->setLayout(layout_g);
        QMetaObject::connectSlotsByName(OptionsPanel);
    } // setupUi


};

namespace Ui {
    class OptionsPanel: public Ui_OptionsPanel {};
} // namespace Ui
QT_END_NAMESPACE
#endif // UI_OPTIONSPANEL_H
