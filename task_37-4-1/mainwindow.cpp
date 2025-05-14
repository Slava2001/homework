#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cstdlib>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    double_validator(QRegExp("[+-]?\\d*[\\.,]?\\d+"), this)
{
    ui->setupUi(this);
    ui->input_a->setValidator(&double_validator);
    ui->input_b->setValidator(&double_validator);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::calc(std::function<double(double, double)> f) {
    bool ok = false;
    double a = ui->input_a->text().toDouble(&ok);
    if (!ok) {
        ui->output->setText(QString("ERROR: The first operand is not a number!"));
        return;
    }
    double b = ui->input_b->text().toDouble(&ok);
    if (!ok) {
        ui->output->setText(QString("ERROR: The second operand is not a number!"));
        return;
    }
    ui->output->setText(QString::number(f(a, b), 'g', 20));
}

void MainWindow::calc_sum() {
    calc([](double a, double b){ return a + b; });
}

void MainWindow::calc_sub() {
    calc([](double a, double b){ return a - b; });
}

void MainWindow::calc_mul() {
    calc([](double a, double b){ return a * b; });
}

void MainWindow::calc_div() {
    calc([](double a, double b){ return a / b; });
}

void MainWindow::clear() {
    ui->input_a->clear();
    ui->input_b->clear();
    ui->output->clear();
}
