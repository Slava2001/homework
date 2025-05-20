#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QPushButton>
#include <QFileDialog>
#include <QSlider>
#include <QImage>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsBlurEffect>
#include <QPainter>

QImage blurImage(QImage src, unsigned radius) {
    if (src.isNull()) {
        return QImage();
    }
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(src));
    auto *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(radius);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(src.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(), QRectF(0, 0, src.width(), src.height()));
    return result;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
    QObject::connect(_ui->open_btn, &QPushButton::clicked, [&]{
        QString path = QFileDialog::getOpenFileName(nullptr, "Open image", "", "Images (*.png *.jpg *.jpeg *.bmp)");
        if (!path.isEmpty()) {
            _img = QImage(path, nullptr);
            _ui->blur_coef->setValue(0);
            _ui->blur_coef->valueChanged(0);
        }
    });
    QObject::connect(_ui->blur_coef, &QSlider::valueChanged, [&](int val) {
        QImage img = blurImage(_img, val);
        if (img.isNull()) {
            return;
        }
        QPixmap pixmap = QPixmap::fromImage(img);
        pixmap = pixmap.scaled(_ui->img->width(), _ui->img->height(), Qt::KeepAspectRatio);
        _ui->img->setPixmap(pixmap);
    });
}

MainWindow::~MainWindow() {
    delete _ui;
}
