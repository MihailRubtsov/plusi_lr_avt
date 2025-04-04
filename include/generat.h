#ifndef GENERAT_H
#define GENERAT_H
#include <QDialog>
#include <QSpinBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class Generat : public QDialog
{
    Q_OBJECT

public:
    explicit Generat(QWidget *parent = nullptr);
    int getStudentCount() const;

private:
    QSpinBox *studentCountSpinBox;
    QPushButton *generateButton;
    QLabel *infoLabel;
};

#endif 