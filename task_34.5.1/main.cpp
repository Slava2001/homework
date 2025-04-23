#include <QApplication>
#include <QPushButton>

int main(int args, char **argv)
{
    QApplication a(args, argv);
    QPushButton button(
        "Hello, world!\nThis is my first button in QT",
        nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}
