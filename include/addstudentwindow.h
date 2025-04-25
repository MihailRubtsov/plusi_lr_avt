#ifndef ADDSTUDENTWINDOW_H
#define ADDSTUDENTWINDOW_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include "../add_to_file.h"

class AddStudentWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddStudentWindow(QWidget *parent = nullptr);

private slots:
    void addStudentToFile();

private:
    QLineEdit *nameEdit;
    QLineEdit *groupEdit;
    QLineEdit *ballEdit;
    QPushButton *addButton;
};

#endif