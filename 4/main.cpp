#include "mainwindow.h"
//#include "map.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QSqlError>
#include <QDebug>
#include <iostream>
//#include "airport.h"
#include <fstream>
#include <vector>
using namespace std;

/* void AirportWriteCsvToDatabase(const QString& csvFilePath, const QString& databaseFilePath)
{
    // Open the CSV file
    QFile csvFile(csvFilePath);
    if (!csvFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open CSV file:" << csvFile.errorString();
        return;
    }

    // Open the database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(databaseFilePath);
    if (!db.open()) {
        qWarning() << "Failed to open database:" << db.lastError().text();
        return;
    }

    // Create the table
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS airports (id INTEGER PRIMARY KEY, IATA TEXT, name TEXT, city TEXT, country TEXT, latitude FLOAT, longitude FLOAT)")) {
        qWarning() << "Failed to create table:" << query.lastError().text();
        return;
    }

    // Read the CSV file line by line and insert the data into the database
    while (!csvFile.atEnd()) {
        QString line = csvFile.readLine().trimmed();
    }
    db.close();
    csvFile.close();
}
*/

int main(int argc, char *argv[])
{
   /* QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName("airports.db");
       if (!db.open()) {
           cerr << "Database wasn't opened" << endl;
           return -1;
       }
       QSqlQuery query(db);
       query.exec("CREATE TABLE IF NOT EXISTS airports (id INTEGER PRIMARY KEY, IATA TEXT, name TEXT, city TEXT, country TEXT, latitude FLOAT, longitude FLOAT)");
       ifstream in("\home\milan\ProjectC\build-Window-Desktop-Debug\apinfo.ru.csv");
       string b;
       getline(in, b);
       getline(in, b);
       //AirportWriteToDB(str2airport(b), db);
       QSqlQuery query1(db);
       query1.exec("SELECT * FROM airports A WHERE A.id = 1");
       query1.next();
       cout <<  query1.value(0).toString().toStdString() << endl;
       */
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Find an airport");
    w.show();
    return a.exec();
}
