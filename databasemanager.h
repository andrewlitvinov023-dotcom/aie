#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QtSql>
#include <QVariantMap>

class DataBaseManager
{
public:
    DataBaseManager();

    bool openDatabase(const QString &dbName);

    void closeDatabase();

    bool createTable(const QString &tableName, const QMap<QString, QString> &columns);

    bool insertRecord(const QString &tableName, const QVariantMap &data);

    bool updateRecord(const QString &tableName, const QVariantMap &data, const QString &condition);

    bool deleteRecord(const QString &tableName, const QString &condition);

    QList<QVariantMap> queryRecords(const QString &tableName, const QStringList &columnNames, const QString &condition);

     QSqlDatabase& database();

     QVariant::Type columnType(const QString &tableName, const QString &columnName);
private:
     QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // БД SQLite // DB SQLite

};

#endif // DATABASEMANAGER_H
