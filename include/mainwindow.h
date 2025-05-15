#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "generat.h"
#include "addstudentwindow.h"

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
    void openAddStudentWindow();
    void showHelp();

private:
    QPushButton *selectFileButton;
    QPushButton *sortButton;
    QPushButton *poshalka;
    QPushButton *dobavlenie;
    QPushButton *helpButton;
    QPushButton *gener;
    QLabel *filePathLabel;
    QVBoxLayout *layout;
    QWidget *centralWidget;
    
    
    // Окна приложения
    SortWindow *sortWindow;
    Generat *generatWindow;
    AddStudentWindow *addStudentWindow;

    QString selectedFilePath;
    const QString POSHALKA_IMAGE_PATH = "/home/misha/CNPZD/plusi_lr_avt/kitik.jpg";
};

#endif // MAINWINDOW_H