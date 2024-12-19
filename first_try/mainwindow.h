#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void on_actionSave_triggered();

    void on_actionBlue_triggered();

    void on_actionClear_triggered();

    void on_action1px_triggered();

    void on_action2px_triggered();

    void on_action3px_triggered();

    void on_action5px_triggered();

    void on_action8px_triggered();

    void on_actionBlack_triggered();

    void on_actionWhite_triggered();

    void on_actionPurple_triggered();

    void on_actionGreen_triggered();
private:
    Ui::MainWindow *ui;
    QImage image;
    bool drawing;
    QPoint lastPoint;
    int brushSize;
    QColor brushColor;
    float multiplierX;
    float multiplierY;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void tabletPressEvent(QTabletEvent *te);
    virtual void mousePressEvent(QMouseEvent *me);
    virtual void tabletMoveEvent(QTabletEvent *te);
    virtual void mouseMoveEvent(QMouseEvent *me);
    virtual void tabletReleaseEvent(QTabletEvent *te);
    virtual void mouseReleaseEvent(QMouseEvent *me);
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
};
#endif // MAINWINDOW_H
