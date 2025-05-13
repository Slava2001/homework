#include <QApplication>
#include <QVBoxLayout>
#include <QSlider>
#include <QPainter>
#include <QFile>

class Indicator: public QWidget {
private:
    int _min;
    int _max;
    int _val;
    std::vector<QPixmap> _imgs;
    unsigned _current_img_index;

public:
    Indicator(QWidget *w, int min, int max, std::vector<const char*> img_paths):
        QWidget(w),
        _min(min),
        _max(max) {
        for (auto path: img_paths) {
            QPixmap img(path);
            if (img.isNull()) {
                throw std::runtime_error("Failed to load resourse");
            }
            _imgs.push_back(img);
        }
        setValue(min);
    }

    QSize minimumSizeHint() const override {
        return QSize(100, 100);
    }

    void paintEvent(QPaintEvent *) override {
        QPainter p(this);
        p.drawPixmap(this->rect(), _imgs[_current_img_index]);
    }

    void setValue(int value) {
        _val = (value < _min)? (_min): (value > _max? _max: value);
        _current_img_index = _val * _imgs.size() /  (_max - _min);
        if (_current_img_index >= _imgs.size()) {
            // occurs when _val == _max
            _current_img_index = _imgs.size() - 1;
        }
        update();
    }
};

#define WINDOW_WIDTH 200
#define WINDOW_HEIGHT 220

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget window;
    window.setWindowTitle("task_36.4.1");
    window.setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    QSlider slider(&window);
    slider.setOrientation(Qt::Horizontal);

    Indicator indicator(
        &window,
        slider.minimum(),
        slider.maximum(),
        {
            ":/indicator/green.png",
            ":/indicator/yellow.png",
            ":/indicator/red.png"
        }
    );

    QObject::connect(&slider, &QSlider::valueChanged, [&indicator](int newValue) {
        indicator.setValue(newValue);
    });

    QVBoxLayout layout;
    layout.addWidget(&indicator);
    layout.addWidget(&slider);
    window.setLayout(&layout);

    window.show();
    return a.exec();
}
