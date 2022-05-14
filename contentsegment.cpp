#include "contentsegment.h"
#include "ui_contentsegment.h"

ContentSegment::ContentSegment(QWidget *parent) : QWidget(parent), ui(new Ui::ContentSegment) {
    ui->setupUi(this);
}
