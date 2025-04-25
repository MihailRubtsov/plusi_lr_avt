#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "generat.h"

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
    void showPoshalka();
    void open_generator();

private:
    QPushButton *selectFileButton;
    QPushButton *sortButton;
    QPushButton *poshalka;
    QPushButton *dobavlenie;
    QPushButton *gener;
    QLabel *filePathLabel;
    QVBoxLayout *layout;
    QWidget *centralWidget;
    SortWindow *sortWindow;
    Generat *generatWindow;

    QString selectedFilePath;
    const QString POSHALKA_IMAGE_PATH = "/home/misha/CNPZD/plusi_lr_avt/kitik.jpg";
};

#endif 