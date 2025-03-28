#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QWidget(parent) {
        // Создаем вертикальный layout
        QVBoxLayout *layout = new QVBoxLayout(this);

        // Создаем кнопку для выбора файла
        QPushButton *selectFileButton = new QPushButton("Выбрать файл", this);
        layout->addWidget(selectFileButton);

        // Создаем кнопку для подтверждения выбора
        QPushButton *confirmButton = new QPushButton("Подтвердить", this);
        layout->addWidget(confirmButton);

        // Подключаем сигналы к слотам
        connect(selectFileButton, &QPushButton::clicked, this, &MainWindow::selectFile);
        connect(confirmButton, &QPushButton::clicked, this, &MainWindow::confirmSelection);

        // Устанавливаем layout для окна
        setLayout(layout);
    }

private slots:
    void selectFile() {
        // Открываем диалог выбора файла
        QString fileName = QFileDialog::getOpenFileName(this, "Выберите файл", "", "All Files (*.*)");
        if (!fileName.isEmpty()) {
            selectedFile = fileName;
            QMessageBox::information(this, "Файл выбран", "Вы выбрали файл: " + fileName);
        }
    }

    void confirmSelection() {
        if (!selectedFile.isEmpty()) {
            QMessageBox::information(this, "Подтверждение", "Вы подтвердили выбор файла: " + selectedFile);
        } else {
            QMessageBox::warning(this, "Ошибка", "Файл не выбран!");
        }
    }

private:
    QString selectedFile;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}

#include "main.moc" // Добавьте эту строку