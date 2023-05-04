#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "map.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    csvModel = new QStandardItemModel(this);
    csvModel->setColumnCount(6);
    csvModel->setHorizontalHeaderLabels(QStringList() <<"Airport");
    //Map *map_1;
    Map *map_1=new Map(ui->openGLWidget);

    ui->tableView->setModel(csvModel);
   ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(2, true);
    ui->tableView->setColumnHidden(3, true);
    ui->tableView->setColumnHidden(4, true);
    ui->tableView->setColumnHidden(5, true);
    QFile file("\home\milan\ProjectC\build-Window-Desktop-Debug\apinfo.ru.csv");
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
            qDebug() << "File not exists";}
    else
    {
            QTextStream in(&file);
            while (!in.atEnd())
            {
                QString line = in.readLine();
                QList<QStandardItem *> standardItemsList;
                for (QString item : line.split("|")) {
                    standardItemsList.append(new QStandardItem(item));
                }
                csvModel->insertRow(csvModel->rowCount(), standardItemsList);
            }
            file.close();
        }
}
MainWindow::~MainWindow()
{
    delete ui;
    delete csvModel;
}

