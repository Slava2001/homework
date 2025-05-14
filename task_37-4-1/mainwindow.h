#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegExpValidator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void calc_sum();
    void calc_sub();
    void calc_mul();
    void calc_div();
    void clear();

private:
    Ui::MainWindow *ui;
    QRegExpValidator double_validator;

    void calc(std::function<double(double, double)> f);
};
#endif // MAINWINDOW_H
