#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Mat2QImage(cv::Mat iSrc, QImage &iDst)
{
    QImage::Format f;
    static cv::Mat src;

    iSrc.copyTo(src);

    // if color image
    if (src.channels() == 3)
    {
        // convert BGR -> RGB
        cv::cvtColor(src,src,CV_BGR2RGB);
        f = QImage::Format_RGB888;
    }
    else if (src.channels() == 1)
    {
        // Siyah Beyaz ise sadece formatı değiştir
        f = QImage::Format_Indexed8;
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Channels count is incompatible");
        msgBox.exec();
        return;

    }

    iDst = QImage((const unsigned char*)(src.data),
            src.cols,
            src.rows,
            src.step,
            f);

    qDebug("Format OK");
}

void MainWindow::showImage(cv::Mat imgMat, QLabel *lb)
{
    QImage img;

    Mat2QImage(imgMat, img);

    lb->setPixmap(QPixmap::fromImage(img).scaled(lb->size(), Qt::KeepAspectRatio));
}

void MainWindow::on_pbOpen_clicked()
{
    cv::Mat img = cv::imread(QFile::encodeName(ui->leFile->text()).data());

    qDebug("%d", img.rows);
    qDebug("%d", img.cols);

    showImage(img, ui->tlImage);

}
