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

private:
    QPushButton *selectFileButton;
    QPushButton *sortButton;
    QLabel *filePathLabel;
    QVBoxLayout *layout;
    QWidget *centralWidget;
    
    SortWindow *sortWindow;
    QString selectedFilePath;
};

#endif // MAINWINDOW_H