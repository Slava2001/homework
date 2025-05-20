#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QTextEdit>
#include <QWebEngineView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->input, &QTextEdit::textChanged, [&](){
        ui->output->setHtml(ui->input->toPlainText());
    });
    ui->input->textChanged();
}

MainWindow::~MainWindow()
{
    delete ui;
}
