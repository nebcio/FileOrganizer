#include "leftpanel.h"
#include "ui_leftpanel.h"
#include <QDebug>

LeftPanel::LeftPanel(QWidget *parent) : QWidget(parent), ui(new Ui::LeftPanel) {
    ui->setupUi(this);
    connect(ui->m_sort, &QPushButton::clicked, this, &LeftPanel::showSortPanel);
    connect(ui->m_group, &QPushButton::clicked, this, &LeftPanel::showGroupPanel);
}

void LeftPanel::showGroupPanel(){
    emit signalShowGroupPanel(ui->m_group->mapToGlobal(QPoint(0,0)));
}

void LeftPanel::showSortPanel(){
    emit signalShowSortPanel(ui->m_sort->mapToGlobal(QPoint(0,0)));
}
