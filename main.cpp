#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Qt6 Test App");

    QVBoxLayout *layout = new QVBoxLayout(&window);

    QLabel *label = new QLabel("Привет", &window);
    layout->addWidget(label);

    QPushButton *button = new QPushButton("Нажми меня", &window);
    layout->addWidget(button);

    window.setLayout(layout);
    window.show();

    return app.exec();
}