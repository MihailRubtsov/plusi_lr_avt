#ifndef SORTWINDOW_H
#define SORTWINDOW_H

#include <QDialog>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class SortWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SortWindow(QWidget *parent = nullptr);
    ~SortWindow();
    
    void setFilePath(const QString &path);

private slots:
    void executeSort();

private:
    QComboBox *sortTypeCombo;
    QComboBox *dataTypeCombo;
    QComboBox *sortOrderCombo;
    QPushButton *sortButton;
    QLabel *fileLabel;
    
    QString filePath;
};

#endif // SORTWINDOW_H