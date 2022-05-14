#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->m_top_bar, SIGNAL(signalExit()), this, SLOT(exitApp()));
    connect(ui->m_top_bar, SIGNAL(signalShowMinimized()), this, SLOT(minimizeApp()));
    connect(ui->m_top_bar, SIGNAL(signalShowMaximized()), this, SLOT(maximizeApp()));
}

MainWindow::~MainWindow() {

}

void MainWindow::exitApp() {
    QCoreApplication::quit();
}

void MainWindow::minimizeApp() {
    showMinimized();
}

void MainWindow::maximizeApp() {
    if(isMaximized()) {
        showNormal();
    }
    else {
        showMaximized();
    }
}

