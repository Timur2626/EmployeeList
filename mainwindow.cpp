#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(7);

    QStringList headers;
    headers << "ФИО"
            << "Отдел"
            << "Должность"
            << "Дата рождения"
            << "Оклад"
            << "Премия"
            << "Дата трудоустройства";

    ui->tableWidget->setHorizontalHeaderLabels(headers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    QString name = QInputDialog::getText(this,"Добавление","ФИО");
    QString department = QInputDialog::getText(this,"Добавление","Отдел");
    QString position = QInputDialog::getText(this,"Добавление","Должность");
    QString birth = QInputDialog::getText(this,"Добавление","Дата рождения");
    QString salary = QInputDialog::getText(this,"Добавление","Оклад");
    QString bonus = QInputDialog::getText(this,"Добавление","Премия");
    QString hire = QInputDialog::getText(this,"Добавление","Дата трудоустройства");

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    ui->tableWidget->setItem(row,0,new QTableWidgetItem(name));
    ui->tableWidget->setItem(row,1,new QTableWidgetItem(department));
    ui->tableWidget->setItem(row,2,new QTableWidgetItem(position));
    ui->tableWidget->setItem(row,3,new QTableWidgetItem(birth));
    ui->tableWidget->setItem(row,4,new QTableWidgetItem(salary));
    ui->tableWidget->setItem(row,5,new QTableWidgetItem(bonus));
    ui->tableWidget->setItem(row,6,new QTableWidgetItem(hire));

    QMessageBox::information(this,"Успех","Сотрудник успешно добавлен!");
}

void MainWindow::on_deleteButton_clicked()
{
    int row = ui->tableWidget->currentRow();

    if(row >= 0)
    {
        ui->tableWidget->removeRow(row);
        QMessageBox::information(this,"Удаление","Сотрудник удалён!");
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Выберите сотрудника!");
    }
}
