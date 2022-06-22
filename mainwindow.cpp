#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    // set flags which will override what Qt does, especially with the Qt::FramelessWindowHint which essentially disables WS_SIZEBOX/WS_THICKFRAME
    SetWindowLongPtr(HWND(winId()), GWL_STYLE, WS_POPUPWINDOW | WS_CAPTION | WS_SIZEBOX | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_CLIPCHILDREN);
    connect(ui->m_top_bar, SIGNAL(signalExit()), this, SLOT(exitApp()));
    connect(ui->m_top_bar, SIGNAL(signalShowMinimized()), this, SLOT(minimizeApp()));
    connect(ui->m_top_bar, SIGNAL(signalShowMaximized()), this, SLOT(maximizeApp()));

    connect(ui->m_left_panel, SIGNAL(signalShowSortPanel(QPoint)), this, SLOT(showSortPanel(QPoint)));
    connect(ui->m_left_panel, SIGNAL(signalShowGroupPanel(QPoint)), this, SLOT(showGroupPanel(QPoint)));
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
        if (!ui->m_sortpanel->isHidden()) ui->m_sortpanel->setHidden(true);
        if (!ui->m_grouppanel->isHidden()) ui->m_grouppanel->setHidden(true);
    }
    else {
        showMaximized();
        if (!ui->m_sortpanel->isHidden()) ui->m_sortpanel->setHidden(true);
        if (!ui->m_grouppanel->isHidden()) ui->m_grouppanel->setHidden(true);
    }
}

void MainWindow::showSortPanel(QPoint pos) {
    ui->m_sortpanel->move(0, pos.y() - this->pos().y() - ui->m_sortpanel->height());
    if (ui->m_sortpanel->isHidden()) ui->m_sortpanel->setHidden(false);
    else ui->m_sortpanel->setHidden(true);
}
void MainWindow::showGroupPanel(QPoint pos) {
    ui->m_grouppanel->move(0, pos.y() - this->pos().y() - ui->m_grouppanel->height());
    if (ui->m_grouppanel->isHidden()) ui->m_grouppanel->setHidden(false);
    else ui->m_grouppanel->setHidden(true);
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    /* Responsible for start resizing */

    if (event->buttons() == Qt::LeftButton){
        if (event->pos().x() < 10 || event->pos().x() > width() - 10 ||
            event->pos().y() < 10 || event->pos().y() > height() - 10) {
            start_x = event->pos().x();
            start_y = event->pos().y();
            start_pos = event->globalPos();
            resizing = true;
        }
    }
}
bool MainWindow::eventFilter(QObject *obj, QEvent *e) {
    /* Changing shape of cursor on boundaries */

    if (e->type() == QEvent::MouseMove) {
        QMouseEvent* event = static_cast<QMouseEvent*>(e);

        const auto main_pos = pos();
        const auto cur_pos = event->globalPos() - main_pos;

        if (/*(cur_pos.x() < 10 && cur_pos.y() < 10) || // fdiag ->*/
                (cur_pos.x() > width() - 10 && cur_pos.y() > height() - 10)) {
            setCursor(Qt::SizeFDiagCursor);
        }
        /*else if ((cur_pos.x() < 10 && cur_pos.y() > height() - 10) || // bdiag <-
                 (cur_pos.y() < 10 && cur_pos.x() > width() - 10)) {
            setCursor(Qt::SizeBDiagCursor);
        }*/
        else if (/*cur_pos.x() < 10 || */cur_pos.x() > width() - 10 && cur_pos.y() > ui->m_top_bar->size().height()) { // horyzontal
            setCursor(Qt::SizeHorCursor);
        }
        else if (/*cur_pos.y() < 10 || */cur_pos.y() > height() - 10) { // vertical
            setCursor(Qt::SizeVerCursor);
        }
        else { setCursor(Qt::ArrowCursor);}
    }
    return false;
}
void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    /* Resizing */
    if (resizing) {
        if (start_x < 10 && start_y < 10){                              // top-left
            const int new_width = width() - event->globalX() + pos().x();
            const int new_height = height() - event->globalY() + pos().y();

            // changing width
            if (new_width < minimumSize().width()){
                setGeometry(pos().x(), pos().y(), minimumSize().width(), height());
            }
            else if (new_width > maximumSize().width()) {
                setGeometry(pos().x(), pos().y(), maximumSize().width(), height());
            }
            else {
                setGeometry(event->globalX(), pos().y(), new_width, height());
            }

            // changing height
            if (new_height < minimumSize().height()){
                setGeometry(pos().x(), pos().y(), width(), minimumSize().height());
            }
            else if (new_height > maximumSize().height()) {
                setGeometry(pos().x(), pos().y(), width(), maximumSize().height());
            }
            else {
                setGeometry(pos().x(), event->globalY(), width(), new_height);
            }
        }
        else if (start_x < 10 && start_y > height() - 10) {             // bottom-left
            const int new_width = width() - event->globalX() + pos().x();
            const int new_height = height() + event->globalY() - start_pos.y();
            const int delta_y = height() - start_y;

            // changing width
            if (new_width < minimumSize().width()){
                setGeometry(pos().x(), pos().y(), minimumSize().width(), height());
            }
            else if (new_width > maximumSize().width()) {
                setGeometry(pos().x(), pos().y(), maximumSize().width(), height());
            }
            else {
                setGeometry(event->globalX(), pos().y(), new_width, height());
            }

            // changing height
            if (new_height < minimumSize().height()){
                setGeometry(pos().x(), pos().y(), width(), minimumSize().height());
            }
            else if (new_height > maximumSize().height()) {
                setGeometry(pos().x(), pos().y(), width(), maximumSize().height());
            }
            else {
                setGeometry(pos().x(), pos().y(), width(), new_height);
            }

            // update new pos to variables
            start_y = height() - delta_y;
            start_pos.setY(event->globalY());
        }
        else if (start_x > width() - 10 && start_y < 10) {              // top-right
            int new_width = width() + event->globalX() - start_pos.x();
            int new_height = height() - event->globalY() + pos().y();
            int delta_x = width() - start_x;

            // changing width
            if (new_width < minimumSize().width()){
                setGeometry(pos().x(), pos().y(), minimumSize().width(), height());
            }
            else if (new_width > maximumSize().width()) {
                setGeometry(pos().x(), pos().y(), maximumSize().width(), height());
            }
            else {
                setGeometry(pos().x(), pos().y(), new_width, height());
            }

            // update new pos to variables
            start_x = width() - delta_x;
            start_pos.setX(event->globalX());

            // changing height
            if (new_height < minimumSize().height()){
                setGeometry(pos().x(), pos().y(), width(), minimumSize().height());
            }
            else if (new_height > maximumSize().height()) {
                setGeometry(pos().x(), pos().y(), width(), maximumSize().height());
            }
            else {
                setGeometry(pos().x(), event->globalY(), width(), new_height);
            }

        }
        else if (start_x > width() - 10 && start_y > height() - 10){    // bottom-right
            const int new_width = width() + event->globalX() - start_pos.x();
            const int new_height = height() + event->globalY() - start_pos.y();
            const int delta_x = width() - start_x, delta_y = height() - start_y;

            // changing width and height
            setGeometry(pos().x(), pos().y(), new_width, new_height);

            // update new pos to variables
            start_x = width() - delta_x;
            start_y = height() - delta_y;
            start_pos = event->globalPos();
        }
        else if (start_x > width() - 10) {                              // right
            const int new_width = width() + event->globalX() - start_pos.x();
            const int delta_x = width() - start_x;

            // changing width
            if (new_width < minimumSize().width()){
                setGeometry(pos().x(), pos().y(), minimumSize().width(), height());
            }
            else if (new_width > maximumSize().width()) {
                setGeometry(pos().x(), pos().y(), maximumSize().width(), height());
            }
            else {
                setGeometry(pos().x(), pos().y(), new_width, height());
            }

            // update new pos to variables
            start_x = width() - delta_x;
            start_pos.setX(event->globalX());
        }
        else if (start_y > height() - 10) {                             // bottom
            const int new_height = height() + event->globalY() - start_pos.y();
            const int delta_y = height() - start_y;

            // changing height
            if (new_height < minimumSize().height()){
                setGeometry(pos().x(), pos().y(), width(), minimumSize().height());
            }
            else if (new_height > maximumSize().height()) {
                setGeometry(pos().x(), pos().y(), width(), maximumSize().height());
            }
            else {
                setGeometry(pos().x(), pos().y(), width(), new_height);
            }

            // update new pos to variables
            start_y = height() - delta_y;
            start_pos.setY(event->globalY());
        }
        else if (start_x < 10) {                                        // left
            const int new_width = width() - event->globalX() + pos().x();

            // changing width
            if (new_width < minimumSize().width()){
                setGeometry(pos().x(), pos().y(), minimumSize().width(), height());
            }
            else if (new_width > maximumSize().width()) {
                setGeometry(pos().x(), pos().y(), maximumSize().width(), height());
            }
            else {
                setGeometry(event->globalX(), pos().y(), new_width, height());
            }
        }
        else if (start_y < 10) {                                        // top
            const int new_height = height() - event->globalY() + pos().y();

            // changing height
            if (new_height < minimumSize().height()){
                setGeometry(pos().x(), pos().y(), width(), minimumSize().height());
            }
            else if (new_height > maximumSize().height()) {
                setGeometry(pos().x(), pos().y(), width(), maximumSize().height());
            }
            else {
                setGeometry(pos().x(), event->globalY(), width(), new_height);
            }
        }
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    /* End of resizing, save config */
    resizing = false;
}

