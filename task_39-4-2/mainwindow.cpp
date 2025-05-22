#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->input, &QLineEdit::textChanged, [&](const QString &str) {
        QRegularExpression expr("^\\+\\d{11}$");
        if (expr.match(str).hasMatch()) {
            ui->output->setText("Ok");
            ui->output->setStyleSheet("QLabel { color : green; }");
        } else {
            ui->output->setText("Not Ok");
            ui->output->setStyleSheet("QLabel {color : red;}");
        }
    });
    ui->input->textChanged("");
}

MainWindow::~MainWindow()
{
    delete ui;
}
