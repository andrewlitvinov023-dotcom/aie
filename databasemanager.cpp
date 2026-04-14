#include "databasemanager.h"

// Конструктор
// Constructor
DataBaseManager::DataBaseManager()
{

}

// Функция открытия БД
// DB opening function
bool DataBaseManager::openDatabase(const QString &dbName)
{
   db.setDatabaseName(dbName);// Устанавалиаем имя // Setting the name

    if(!db.open()) {// Открываем БД // Opening DB
        qDebug()<< "Can't open db, " << db.lastError().text();// Выводим информацию об ошибке // Error's information
        return false;
    }
    else {
        return true;
    }
    return true;
}

// Функция закрытия БД
// DB closing function
void DataBaseManager::closeDatabase()
{
    db.close();
}

// Функция Создания БД
// DB creating function
bool DataBaseManager::createTable(const QString &tableName, const QMap<QString, QString> &columns)
{
    // Запрос для создания БД (если она еще не существует)
    // Request to create a database (if it does not already exist)
    QString query = "CREATE TABLE IF NOT EXISTS '" + tableName + "' (";

    QStringList columnQueries;

    for (const QString &columnName : columns.keys()) {
        QString columnType = columns.value(columnName);
        columnQueries << columnName + " " + columnType;
    }

    query += columnQueries.join(", ") + ");"; // Объединяем строки и добавляем к запросу // Combine the lines and add to the query

    QSqlQuery createQuery;
    if (!createQuery.exec(query)) {
        qDebug() << "Error creating table:" << createQuery.lastError().text();// Выводим информацию об ошибке // Error's information
        return false;
    }
    qDebug() << query;
    return true;
}

// Функция удаления записи
// Record deletion function
bool DataBaseManager::deleteRecord(const QString &tableName, const QString &condition)
{
    QSqlQuery query;

    QString deleteQuery = "DELETE FROM '" + tableName + "'";
    if (!condition.isEmpty()) {
        deleteQuery += " WHERE " + condition;
    }

    query.prepare(deleteQuery);
    // Подготавливает SQL запрос к выполнению. Возвращает true, если запрос подготовлен успешно(правильно), в противном случае возвращает false
    // Prepares the SQL query query for execution. Returns true if the query is prepared successfully, otherwise returns false

    if (query.exec()) {
        qDebug() << "Record(s) deleted successfully";
        return true;
    } else {
        qDebug() << "Error executing delete query:" << query.lastError().text();// Информация о последней ошибке
        return false;
    }

}

// Функция изменения записи
// Record change function
bool DataBaseManager::insertRecord(const QString &tableName, const QVariantMap &data)
{
    if (data.isEmpty()) {
        qDebug() << "Error: No data to insert.";
        return false;
    }

    QSqlQuery query;

    QStringList columnNames;
    QStringList placeholders;

    for (const QString &columnName : data.keys()) {
        columnNames << columnName;
        placeholders << ":" + columnName;
    }

    QString insertQuery = "INSERT INTO '" + tableName + "' (" + columnNames.join(", ") + ") VALUES (:" + columnNames.join(", :") + ")";

    query.prepare(insertQuery);
    // Подготавливает SQL запрос к выполнению. Возвращает true, если запрос подготовлен успешно(правильно), в противном случае возвращает false
    // Prepares the SQL query query for execution. Returns true if the query is prepared successfully, otherwise returns false

    for (const QString &columnName : data.keys()) {
        query.bindValue(":" + columnName, data.value(columnName));
    }

    if (query.exec()) {
        qDebug() << "Record inserted successfully";
        return true;
    } else {
        qDebug() << "Error executing insert query:" << query.lastError().text();
        qDebug() << "Query:" << insertQuery;
        qDebug() << "Bindings:" << query.boundValues();
        return false;
    }

}

// Функция сбрасывания счетчика у столбцов с данной функцией
// Counter reset function for columns with this function
void resetAutoIncrement(QSqlDatabase &database, const QString &tableName)
{
    // Можно пропустить чтение данной функции
    // Nothing to see here   ">_<"
}

// Функция выполнения запроса
// Query execution function
QList<QVariantMap> DataBaseManager::queryRecords(const QString &tableName, const QStringList &columnNames, const QString &condition)
{
    QList<QVariantMap> records;

    QString query = "SELECT " + columnNames.join(", ") + " FROM '" + tableName + "'";
    if (!condition.isEmpty()) {
        query += " WHERE " + condition;
    }

    QSqlQuery selectQuery(query);

    if (selectQuery.exec()) {
        while (selectQuery.next()) {
            QVariantMap record;
            for (const QString &columnName : columnNames) {
                record[columnName] = selectQuery.value(columnName);
            }
            records.append(record);
        }
    } else {
        qDebug() << "Error executing select query:" << selectQuery.lastError().text();
    }

    return records;
}

// Функция обновления записи
// Record update function
bool DataBaseManager::updateRecord(const QString &tableName, const QVariantMap &data, const QString &condition)
{
    if (data.isEmpty()) {
        qDebug() << "Error: No data to update.";
        return false;
    }

    QSqlQuery query;

    QString updateQuery = "UPDATE '" + tableName + "' SET ";

    QStringList updateColumns;
    for (const QString &columnName : data.keys()) {
        updateColumns << columnName + " = :" + columnName;
    }
    updateQuery += updateColumns.join(", ");

    if (!condition.isEmpty()) {
        updateQuery += " WHERE " + condition;
    }

    query.prepare(updateQuery);

    for (const QString &columnName : data.keys()) {
        query.bindValue(":" + columnName, data.value(columnName));
    }

    if (query.exec()) {
        qDebug() << "Record(s) updated successfully";
        return true;
    } else {
        qDebug() << "Error executing update query:" << query.lastError().text();
        return false;
    }
}

// Функция возвращает текущюю БД
// The function returns the current database
QSqlDatabase& DataBaseManager::database()
{
    return db;
}

// Функция определения типа колонки
// Column type detection function
QVariant::Type DataBaseManager::columnType(const QString &tableName, const QString &columnName)
{
    QVariant::Type columnType = QVariant::Invalid;

    QSqlRecord tableRecord = database().record(tableName);
    int columnIndex = tableRecord.indexOf(columnName);

    if (columnIndex >= 0) {
        columnType = tableRecord.field(columnIndex).type();
    }

    return columnType;
}
