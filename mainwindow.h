#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include <QMessageBox>
#include <QLabel>
#include <QFile>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pbOpen_clicked();

private:
    Ui::MainWindow *ui;

    void Mat2QImage(cv::Mat iSrc, QImage& iDst );
    void showImage(cv::Mat imgMat, QLabel *lb);
};

#endif // MAINWINDOW_H
