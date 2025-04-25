#include "addstudentwindow.h"

AddStudentWindow::AddStudentWindow(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Добавление студента");
    resize(300, 200);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *nameLabel = new QLabel("Имя студента:", this);
    nameEdit = new QLineEdit(this);
    QLabel *groupLabel = new QLabel("Группа:", this);
    groupEdit = new QLineEdit(this);
    QLabel *ballLabel = new QLabel("Средний балл:", this);
    ballEdit = new QLineEdit(this);
    addButton = new QPushButton("Добавить", this);

    layout->addWidget(nameLabel);
    layout->addWidget(nameEdit);
    layout->addWidget(groupLabel);
    layout->addWidget(groupEdit);
    layout->addWidget(ballLabel);
    layout->addWidget(ballEdit);
    layout->addWidget(addButton);

    connect(addButton, &QPushButton::clicked, this, &AddStudentWindow::addStudentToFile);

    setLayout(layout);
}

void AddStudentWindow::addStudentToFile()
{
    QString name = nameEdit->text().trimmed();
    QString group = groupEdit->text().trimmed();
    QString ball = ballEdit->text().trimmed();

    // if (name.isEmpty() || group.isEmpty() || ball.isEmpty()) {
    //     QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены!");
    //     return;
    // }

    // bool ok;
    // float ballValue = ball.toFloat(&ok);
    // if (!ok) {
    //     QMessageBox::warning(this, "Ошибка", "Средний балл должен быть числом!");
    //     return;
    // }

    add_to_file(name.toStdString(), group.toStdString(), ball.toStdString());
    // QMessageBox::information(this, "Успех", "Студент успешно добавлен!");

    // Очищаем поля после успешного добавления
    nameEdit->clear();
    groupEdit->clear();
    ballEdit->clear();
}