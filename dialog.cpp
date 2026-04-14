#include "dialog.h"
#include "ui_dialog.h"

// Конструктор
// Constructor
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setAcceptDrops(true);

    setWindowTitle(" ");

    QIcon icon(":/icon/putea.png");
    setWindowIcon(icon);

    mainLanguage="english";

    ButtonMap["add"] = ui->pushButton_add;
    ButtonMap["changeLanguage"] = ui->pushButton_changeLanguage;
    ButtonMap["execute"] = ui->pushButton_execute;
    ButtonMap["open"] = ui->pushButton_open;
    ButtonMap["remove"] = ui->pushButton_remove;
    ButtonMap["save"] = ui->pushButton_save;
}
// Событие, которое посылается виджету, когда операция перетаскивания (drag and drop) входит в его область
// An event that is sent to the widget when a drag and drop operation enters its scope
void Dialog::dragEnterEvent(QDragEnterEvent *e)
{
    if (e->mimeData()->hasUrls()) {
        e->acceptProposedAction();
    }
}

// Событие, посылаемое при завершении операции перетаскивания
// Event sent when the drag operation is completed
void Dialog::dropEvent(QDropEvent *e)
{
    foreach (const QUrl &url, e->mimeData()->urls()) {
        QString fileName = url.toLocalFile();
        qDebug() << "Dropped file:" << fileName;
        // Проверяем, имеет ли файл расширение ".db"
        // Check if the dropped file has a ".db"
        if (fileName.endsWith(".db", Qt::CaseInsensitive)) {
            dbPath=fileName;
            openDataBase();
        } else {
            qDebug() << "Invalid file format. Only '.db' files are supported.";
        }
    }
}

// Деструктор
// Destructor
Dialog::~Dialog()
{
    delete ui;
}

// Обработчик нажатия кнопки "Добавить"
// Handler for clicking the "Add" button
void Dialog::on_pushButton_add_clicked()
{
    if(windowTitle()==" "){
        return;
    }
    int rowCount = ui->tableWidget->rowCount();
    int columnCount = ui->tableWidget->columnCount();
    // Добавляем строку в таблицу
    // Add a new row to the table widget
    ui->tableWidget->insertRow(rowCount);

    // Заполняем новую строку
    // Populate the newly added row with empty items
    for (int col = 0; col < columnCount; ++col) {
        QTableWidgetItem *item = new QTableWidgetItem("");
        ui->tableWidget->setItem(rowCount, col, item);
    }

    updateDataBase();
}

// Обработчик нажатия кнопки "Удалить"
// Handler for clicking the "Delete" button
void Dialog::on_pushButton_remove_clicked()
{
    if(windowTitle()==" "){
        return;
    }
    int selectedRow = ui->tableWidget->currentRow();

    if (selectedRow >= 0) {
        // Удаляем выбранную строку из таблицы
        // Remove the selected row from the table widget
        ui->tableWidget->removeRow(selectedRow);

        updateDataBase();
    }
}

// Обработчик нажатия кнопки "Изменить язык"
// Handler for clicking the "Change language" button
void Dialog::on_pushButton_changeLanguage_clicked()
{
    LanguageDialog dial(this,mainLanguage);
    if(dial.exec()){
        previousLanguage=mainLanguage;
        dial.getLanguage(mainLanguage);
        translateApp();
    }

}

// Функция вызова диалогового окна для открытия файла
// Function of calling a dialog box to open a file
void Dialog::getFileName()
{
    QString dbPath = QFileDialog::getOpenFileName(this, "Open Database", "", "Database (*.db)");

    if (dbPath.isEmpty()) {
        qDebug() << "No database file selected.";
        return;
    }

    this->dbPath=dbPath;

}

// Функция открытия БД
// DB opening function
void Dialog::openDataBase()
{
    // Открываем БД
    // Open the selected database file
    if (!dbManager.openDatabase(dbPath)) {
        qDebug() << "Failed to open the database";
        return;
    }


    // Получаем столбцы БД
    // Get the table names from the database
    QStringList tableNames = dbManager.database().tables();

    if (tableNames.isEmpty()) {
        qDebug() << "No tables found in the database.";
        dbManager.closeDatabase();
        return;
    }

    // Очищаем таблицу (интерфейс)
    // Clear any existing data from the table widget
    ui->tableWidget->clear();

    programmaticChange=1;
    ui->comboBox->clear();

    // Заполняем комбобокс именами таблиц
    // Populate the combo box with table names
    ui->comboBox->addItems(tableNames);
    programmaticChange=0;

    // Получаем структуру первой талицы
    // Get the structure of the first table
    QString firstTableName = tableNames.first();

    if (!dbManager.openDatabase(dbPath)) {
        return;
    }

    QSqlRecord tableRecord = dbManager.database().record(firstTableName);

    // Устанавливаем количество столбцов
    // Set the column count based on the number of columns in the table
    int columnCount = tableRecord.count();
    ui->tableWidget->setColumnCount(columnCount);

    // Устанавливаем имена столбцов
    // Set the headers for the columns based on the field names
    QStringList columnHeaders;
    for (int col = 0; col < columnCount; ++col) {
        columnHeaders << tableRecord.fieldName(col);
    }
    ui->tableWidget->setHorizontalHeaderLabels(columnHeaders);

    // Получаем данные из БД для заполнения
    // Retrieve data from the first table using your queryRecords function
    QList<QVariantMap> records = dbManager.queryRecords(firstTableName, columnHeaders, "");

    // Заполняем таблицу полученными данными
    // Populate the table widget with the retrieved data
    ui->tableWidget->setRowCount(records.size());
    for (int row = 0; row < records.size(); ++row) {
        QVariantMap record = records.at(row);
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(record.value(columnHeaders.at(col)).toString());
            ui->tableWidget->setItem(row, col, item);
        }
    }

    QFileInfo fileInfo(dbPath);
    QString fileName = fileInfo.fileName();
    setWindowTitle(fileName);
}

// Обработчик нажатия кнопки "Открыть язык"
// Handler for clicking the "Open language" button
void Dialog::on_pushButton_open_clicked()
{
    dbManager.closeDatabase();

    getFileName();

    openDataBase();
}

// Обработчик нажатия кнопки "Сохранить язык"
// Handler for clicking the "Save language" button
void Dialog::on_pushButton_save_clicked()
{
    updateDataBase();
}

// Функция обновления БД
// DB update function
void Dialog::updateDataBase()
{
    // Открываем БД
    // Open the selected database file
    if (!dbManager.openDatabase(dbPath)) {
        qDebug() << "Failed to open the database";
        return;
    }

    // Получаем нужную таблицу из комбобокса
    // Get the selected table name from the combo box
    QString selectedTableName = ui->comboBox->currentText();

    // Удаляем все записи из выбранной таблицы
    // Delete all records from the selected table in the database
    dbManager.deleteRecord(selectedTableName, "");

    // Получаем количество строк и столбцов из таблицы
    // Get the number of rows and columns in the QTableWidget
    int rowCount = ui->tableWidget->rowCount();
    int columnCount = ui->tableWidget->columnCount();

    for (int row = 0; row < rowCount; ++row) {
        QVariantMap rowData;
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            if (item) {
                QString columnName = ui->tableWidget->horizontalHeaderItem(col)->text();
                QVariant::Type columnType = dbManager.columnType(selectedTableName, columnName);

                if (item->text().isEmpty() && columnType == QVariant::Int) {
                    // Пропусаем вставку пустого значения для столбцов с типом Int
                    // Skip inserting an empty value for integer columns
                    continue;
                }

                QVariant value;
                if (columnType == QVariant::Int) {
                    value = QVariant::fromValue(item->text().toInt());
                } else if (columnType == QVariant::Double) {
                    value = QVariant::fromValue(item->text().toDouble());
                } else {
                    value = QVariant::fromValue(item->text());
                }

                rowData[columnName] = value;
            }
        }

        // Вставляем данные текущей строки в базу данных
        // Insert the current row data into the database
        dbManager.insertRecord(selectedTableName, rowData);
    }
}

// Обработчик нажатия кнопки "Исполнить"
// Handler for clicking the "Execute" button
void Dialog::on_pushButton_execute_clicked()
{
    ui->tableWidget->show();
    QString sqlQuery = ui->lineEdit_query->text();

    // Проверяем введенный запрос
    // Check if the user entered a valid SQL query
    if (sqlQuery.trimmed().isEmpty()) {
        qDebug() << "Error: Empty query.";
        return;
    }

    // Открываем БД
    // Open the selected database file
    if (!dbManager.openDatabase(dbPath)) {
        qDebug() << "Failed to open the database";
        return;
    }

    // Шаблон ищет фразу "FROM", за которой следует пробел и одиночная кавычка,
    // а после этого идет название таблицы, состоящее из буквенно-цифровых символов.
    // Это позволяет извлечь название таблицы из SQL-запроса, который содержит подстроку вида FROM 'таблица'.
    QRegularExpression tableRegex("FROM\\s+'(\\w+)'", QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionMatch match = tableRegex.match(sqlQuery);
    QString tableName = match.hasMatch() ? match.captured(1) : "Unknown Table";

    qDebug() << "Executing query for table:" << tableName;
    int index = ui->comboBox->findText(tableName);
    if (index != -1) {
        ui->comboBox->setCurrentIndex(index);
    } else {
        qDebug() << "Table name not found in combo box.";
    }
    // Выполняем запрос введенный пользователем
    // Execute the user-entered SQL query
    QSqlQuery query(sqlQuery);

    if (query.exec()) {
        QSqlRecord queryRecord = query.record();
        QStringList tableColumns;
        for (int col = 0; col < queryRecord.count(); ++col) {
            tableColumns << queryRecord.fieldName(col);
        }
        int row_count = 0;
        while (query.next())
            row_count++;
        qDebug() << row_count;

        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(row_count);
        ui->tableWidget->setColumnCount(queryRecord.count());
        ui->tableWidget->setHorizontalHeaderLabels(tableColumns);

        // Возвращаемся обратно в начало к первой записи
        // Reset the query back to the first record
        query.first();

        int row = 0;
        do {
            int col = 0;
            for (const QString &columnName : qAsConst(tableColumns)) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(columnName).toString());
                ui->tableWidget->setItem(row, col++, item);
            }
            ++row;
        } while (query.next());
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
    }
}

// Обработчик изменения индекса комбобокса
// Handler for changing the combobox index
void Dialog::on_comboBox_currentIndexChanged(int index)
{
    if (programmaticChange) {
        // Изменение было вызвано программно
        // The change was caused programmatically
        programmaticChange = false; // Сбрасываем флаг // Resetting the flag
        return;
    }
    // Очищаем таблицу
    // Clear any existing data from the table widget
    ui->tableWidget->clear();

    if (!dbManager.openDatabase(dbPath)) {
        qDebug() << "Failed to open the database";
        return;
    }

    QStringList tableNames = dbManager.database().tables();

    // Получаем имя таблицы из комбобокса
    // Get the selected table name from the combo box
    QString selectedTableName = ui->comboBox->currentText();

    // Получаем структуры текущей таблицы
    // Get the structure of the selected table
    QSqlRecord tableRecord = dbManager.database().record(selectedTableName);

    // Устанавливаем количество столбцов на основе количества столбцов в таблице
    // Set the column count based on the number of columns in the table
    int columnCount = tableRecord.count();
    ui->tableWidget->setColumnCount(columnCount);

    // Устанавливаем заголовки для столбцов на основе имен полей
    // Set the headers for the columns based on the field names
    QStringList columnHeaders;
    for (int col = 0; col < columnCount; ++col) {
        columnHeaders << tableRecord.fieldName(col);
    }
    ui->tableWidget->setHorizontalHeaderLabels(columnHeaders);

    // Извлекаем данные из выбранной таблицы
    // Retrieve data from the selected table using your queryRecords function
    QList<QVariantMap> records = dbManager.queryRecords(selectedTableName, columnHeaders, "");

    // Заполняем таблицу полученными данными
    // Populate the table widget with the retrieved data
    ui->tableWidget->setRowCount(records.size());
    for (int row = 0; row < records.size(); ++row) {
        QVariantMap record = records.at(row);
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(record.value(columnHeaders.at(col)).toString());
            ui->tableWidget->setItem(row, col, item);
        }
    }
}

// Устанавливает форматирование текста в поле ввода lineEdit
// на основе списка форматов formats.
// Sets the text formatting in the qlineedit input field
// based on the formats list.
static void setLineEditTextFormat(QLineEdit* lineEdit, const QList<QTextLayout::FormatRange>& formats)
{
    if(!lineEdit)
        return; // Если указатель на поле ввода пустой, выходим из функции // If the pointer to the input field is empty, exit the function

    QList<QInputMethodEvent::Attribute> attributes; // Создаем список атрибутов для события ввода метода // Creating a list of attributes for the method input event
    foreach(const QTextLayout::FormatRange& fr, formats)
    {
        // Тип атрибута - форматирование текста // Attribute type - text formatting
        QInputMethodEvent::AttributeType type = QInputMethodEvent::TextFormat;
        // Начальная позиция форматирования относительно позиции курсора // The initial formatting position relative to the cursor position
        int start = fr.start - lineEdit->cursorPosition();
        // Длина форматирования // Formatting length
        int length = fr.length;
        // Значение формата // Format value
        QVariant value = fr.format;
        attributes.append(QInputMethodEvent::Attribute(type, start, length, value)); // Добавляем атрибут в список // Adding an attribute to the list
    }
    QInputMethodEvent event(QString(), attributes);  // Создаем событие ввода метода с заданными атрибутами // Creating a method input event with the specified attributes
    QCoreApplication::sendEvent(lineEdit, &event);  // Отправляем событие ввода метода полю ввода // Sending the method input event to the input field
}

// Очищает форматирование текста в поле ввода lineEdit.
// Clears the formatting of the text in the qlineedit input field.
static void clearLineEditTextFormat(QLineEdit* lineEdit)
{
    setLineEditTextFormat(lineEdit, QList<QTextLayout::FormatRange>());
    // Вызываем setLineEditTextFormat с пустым списком форматов
    // Calling setLineEditTextFormat with an empty list of formats
}

// Обработчик изменений в lineEdit
// lineEdit Change Handler
void Dialog::on_lineEdit_query_textEdited(const QString &arg1)
{
    QLineEdit* lineEdit = ui->lineEdit_query;

    QList<QTextLayout::FormatRange> formats;

    QStringList wordsToHighlight = {
        "SELECT", "FROM", "WHERE", "UPDATE", "VALUES",
        "INSERT", "INTO", "SET", "DELETE",  "LIMIT" ,
        "ALTER", "DROP", "INDEX", "PRAGMA", "RENAME",
    };

    // Применить форматирование к целым вхождениям слов в последнем (без учета регистра)
    // Apply formatting to whole word occurrences of words in the list (case-insensitive)
    QTextCharFormat keywordFormat;
    keywordFormat.setForeground(Qt::darkMagenta);

    foreach (const QString &word, wordsToHighlight) {
        int currentIndex = 0;
        while ((currentIndex = arg1.indexOf(word, currentIndex, Qt::CaseInsensitive)) != -1) {
            // Check if the word is a whole word
            bool isWholeWord = true;
            if (currentIndex > 0 && arg1[currentIndex - 1].isLetterOrNumber()) {
                isWholeWord = false;
            }
            if (currentIndex + word.length() < arg1.length() && arg1[currentIndex + word.length()].isLetterOrNumber()) {
                isWholeWord = false;
            }

            if (isWholeWord) {
                QTextLayout::FormatRange fr_word;
                fr_word.start = currentIndex;
                fr_word.length = word.length();
                fr_word.format = keywordFormat;
                formats.append(fr_word);
            }

            currentIndex += word.length(); // Move to the next position after the current occurrence
        }
    }

    // Apply formatting to numbers
    QTextCharFormat numberFormat;
    numberFormat.setForeground(Qt::blue);

    QRegExp numberRegExp("\\b\\d+\\b");
    int pos = numberRegExp.indexIn(arg1);
    while (pos != -1) {
        QTextLayout::FormatRange fr_number;
        fr_number.start = pos;
        fr_number.length = numberRegExp.matchedLength();
        fr_number.format = numberFormat;
        formats.append(fr_number);

        pos = numberRegExp.indexIn(arg1, pos + numberRegExp.matchedLength());
    }

    // Применить форматирование к значениям, заключенным в кавычки
    // Apply formatting to values within quotes
    QTextCharFormat valueFormat;
    valueFormat.setForeground(Qt::darkGreen);

    QRegExp valueRegExp("'([^']*)'");
    pos = valueRegExp.indexIn(arg1);
    while (pos != -1) {
        QTextLayout::FormatRange fr_value;
        fr_value.start = pos;
        fr_value.length = valueRegExp.matchedLength();
        fr_value.format = valueFormat;
        formats.append(fr_value);

        pos = valueRegExp.indexIn(arg1, pos + valueRegExp.matchedLength());
    }

    setLineEditTextFormat(lineEdit, formats);

}

// Функция получения перевода
// Transfer receipt function
QString Dialog::getTranslation(QString text, QString originalLanguage, QString targetLanguage)
{
    if (!dbManager.openDatabase("language.db")) {
        qDebug() << "Failed to open the database";
        return "";
    }
    QSqlQuery query;
    QString selectQuery = "SELECT " + targetLanguage + " FROM languages WHERE " + originalLanguage + " = '" + text + "'";
    if (query.exec(selectQuery)) {
        while (query.next()) {
            QString languageValue = query.value(0).toString();
            return languageValue;
        }
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
    }
    dbManager.closeDatabase();
    return "";
}

// Функция сопоставления языков
// Language matching function
QString Dialog::getTranslatedColumnName(const QString &mainLanguage)
{
    QMap<QString, QString> columnToLanguageMap = {
        {"English", "english"}, {"Español", "spanish"}, {"Français", "french"},
        {"Deutsch", "german"}, {"Nederlands", "dutch"}, {"Italiano", "italian"},
        {"Português", "portuguese"}, {"中文", "chinese"}, {"日本語", "japanese"},
        {"한국어", "korean"}, {"العربية", "arabic"}, {"Türkçe", "turkish"},
        {"Polski", "polish"}, {"Русский", "russian"}, {"Māori", "maori"}
    };

    if (columnToLanguageMap.contains(mainLanguage)) {
        return columnToLanguageMap[mainLanguage];
    }

    // Возвращаем значение по умолчанию, если выбранный язык не найден
    // Return the default value if the selected language is not found
    return "english";
}

// Функция перевода приложения
// Application translation function
void Dialog::translateApp()
{
    QString originalLanguage_translated= getTranslatedColumnName(previousLanguage);
    QString targetLanguage_translated = getTranslatedColumnName(mainLanguage);
    for (const QString &buttonName : ButtonMap.keys()) {
        QPushButton *button = ButtonMap.value(buttonName);
        button->setText(getTranslation(button->text(), originalLanguage_translated, targetLanguage_translated));
    }
}
