#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class SortWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void selectFile();
    void openSortWindow();
    void showPoshalka();  // Новый слот для кнопки "Посхалко"

private:
    // Виджеты
    QPushButton *selectFileButton;
    QPushButton *sortButton;
    QPushButton *poshalka;
    //QPushButton *gener;
    QLabel *filePathLabel;
    QVBoxLayout *layout;
    QWidget *centralWidget;
    
    // Вспомогательные указатели
    SortWindow *sortWindow;
    
    // Данные
    QString selectedFilePath;
    const QString POSHALKA_IMAGE_PATH = "/home/misha/CNPZD/plusi_lr_avt/kitik.jpg";  // Путь к изображению
};

#endif // MAINWINDOW_H