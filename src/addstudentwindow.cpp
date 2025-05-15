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

void AddStudentWindow::addStudentToFile() // функция добавления студента в сам файл
{
    QString name = nameEdit->text().trimmed();
    QString group = groupEdit->text().trimmed();
    QString ball = ballEdit->text().trimmed(); // trimmed удаляет пробелы в начале и конце на всякий случай
    bool prov_ball;
    ball.toDouble(&prov_ball); // эта строка дает понять в этой строке только числа или еще есть другие символы

    if (prov_ball == false){
        QMessageBox::warning(this, "Ошибка", "Средний балл должен быть числом!"); // само окно с ошибкой
        return;
    }

    add_to_file(name.toStdString(), group.toStdString(), ball.toStdString()); // функция добавления в файл
    nameEdit->clear();
    groupEdit->clear();
    ballEdit->clear();
}