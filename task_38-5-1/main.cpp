#include <QApplication>
#include <QPushButton>
#include <QPaintEvent>
#include <QPainter>
#include <QMediaPlayer>

class MyButton: public QPushButton {
    Q_OBJECT

public:
    MyButton(QWidget *parent = nullptr):
        QPushButton(parent),
        _img_up(":/btn_up.png"),
        _img_down(":/btn_down.png"),
        _player(this)
    {
        if (_img_up.isNull() || _img_down.isNull()) {
            throw std::runtime_error("Failed to load my button textures");
        }
        QObject::connect(this, &QPushButton::pressed, [&] {
            _player.setMedia(QUrl("qrc:/btn_sound_down.mp3"));
            _player.play();
        });
        QObject::connect(this, &QPushButton::released, [&] {
            _player.setMedia(QUrl("qrc:/btn_sound_up.mp3"));
            _player.play();
        });
    }

    void paintEvent(QPaintEvent *e) override {
        QPainter p(this);
        if (isDown()) {
            p.drawPixmap(e->rect(), _img_down);
        } else {
            p.drawPixmap(e->rect(), _img_up);
        }
    }

    QSize minimumSizeHint() const override {
        return sizeHint();
    }

    QSize sizeHint() const override {
        return QSize(100, 100);
    }

private:
    QPixmap _img_up;
    QPixmap _img_down;
    QMediaPlayer _player;
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MyButton btn;
    btn.show();
    return a.exec();
}

#include "main.moc"
