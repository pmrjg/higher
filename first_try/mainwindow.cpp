#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui (new Ui::MainWindow)
{
    ui->setupUi(this);
    multiplierX = 1.0f;
    multiplierY = 1.0f;
    image = QImage(this->size(), QImage::Format_RGB32);
    image.fill(Qt::white);
    drawing = false;
    brushColor = Qt::black;
    brushSize = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tabletPressEvent(QTabletEvent *te){
    switch(te->deviceType()) {
        case QInputDevice::DeviceType::Stylus:
         {
        multiplierX = te->xTilt() * te->pressure() * (1 - te->tangentialPressure()) * 255;
            multiplierY = te->yTilt() * te -> pressure() * (1 - te->tangentialPressure()) * 255;
            drawing = true;
            lastPoint = te->position().toPoint();

        }
        break;
        default: {}}


}

void MainWindow::tabletMoveEvent(QTabletEvent *te){
    switch(te->deviceType()) {
    case QInputDevice::DeviceType::Stylus:
    {
        if(drawing){
            QPainter painter(&image);
            painter.setPen(QPen(brushColor, static_cast<int>(brushSize * (multiplierX + multiplierY) / 2.0f), Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
            painter.drawLine(lastPoint, te->position());
            lastPoint = te->position().toPoint();
            this->update();
        }

    }
    break;
    default: {}
    }


}

void MainWindow::mousePressEvent(QMouseEvent *me){

    if(me->button() == Qt::LeftButton){
        multiplierX = 1.0;
        multiplierY = 1.0;
        drawing = true;
        lastPoint = me->pos();
    }

}

void MainWindow::mouseMoveEvent(QMouseEvent *me){

    if((me->buttons() & Qt::LeftButton) && drawing) {

        QPainter painter(&image);
        painter.setPen(QPen(brushColor, ((int) brushSize * (multiplierX + multiplierY) / 2.0f), Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter.drawLine(lastPoint, me->pos());
        lastPoint = me->pos();
        this->update();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *me){
    if(me->button() == Qt::LeftButton){
        drawing = false;
    }
}

void MainWindow::tabletReleaseEvent(QTabletEvent *te){
    switch(te->deviceType()) {
    case QInputDevice::DeviceType::Stylus:
    {
        drawing = false;
        multiplierX = 1.0f;
        multiplierY = 1.0f;
    }
    break;
    default:{}
    }

}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter canvasPainter(this);
    canvasPainter.drawImage(this->rect(), image, image.rect());
}

void MainWindow::resizeEvent(QResizeEvent *event){

    image = image.scaled(event->size());
    QPainter canvasPainter(this);
    canvasPainter.drawImage(this->rect(), image, image.rect());
}

void MainWindow::on_actionSave_triggered() {
    QString filePath = QFileDialog::getSaveFileName(this, "Save Image", "PNG (*.png;;JPEG (*.jpg *.jpeg);;All files (*.*)");
    if (filePath.isEmpty()) {
        return;
    }

    image.save(filePath);
}

void MainWindow::on_actionClear_triggered() {image.fill(Qt::white);}

void MainWindow::on_action1px_triggered() {brushSize = 1; multiplierX = 1.0f; multiplierY = 1.0f;}

void MainWindow::on_action2px_triggered() {brushSize = 2; multiplierX = 1.0f; multiplierY = 1.0f;}

void MainWindow::on_action3px_triggered() {brushSize = 3; multiplierX = 1.0f; multiplierY = 1.0f;}

void MainWindow::on_action5px_triggered() {brushSize = 5; multiplierX = 1.0f; multiplierY = 1.0f;}

void MainWindow::on_action8px_triggered() {brushSize = 8; multiplierX = 1.0f; multiplierY = 1.0f;}

void MainWindow::on_actionBlack_triggered() {brushColor = Qt::black; multiplierX = 1.0f; multiplierY = 1.0f;}

void MainWindow::on_actionWhite_triggered() {brushColor = Qt::yellow; multiplierX = 1.0f; multiplierY = 1.0f;}

void MainWindow::on_actionPurple_triggered() {brushColor = QColorConstants::Svg::purple; multiplierX = 1.0f; multiplierY = 1.0f;}

void MainWindow::on_actionGreen_triggered() {brushColor = Qt::green; multiplierX = 1.0f; multiplierY = 1.0f;}

void MainWindow::on_actionBlue_triggered() {brushColor = Qt::blue; multiplierX = 1.0f; multiplierY = 1.0f;}
