#ifndef DIALOG_H
#define DIALOG_H

#include <QDebug>
#include <QDialog>
#include <QListWidget>

#include <languagedialog.h>
#include <databasemanager.h>

#include <QtSql>

#include <QDragEnterEvent>
#include <QDropEvent>

#include "QInputDialog"
#include "QFileDialog"
#include "QTextLayout"

#include "QMessageBox"
#include <QObject>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT
protected:
    // Функции отслеживания "Перетасивания файлов из вне"
    // Tracking functions for "Dragging files from outside"
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    QString getTranslatedColumnName(const QString &mainLanguage);

    QString getTranslation(QString text, QString originalLanguage, QString targetLanguage);


private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_remove_clicked();

    void on_pushButton_changeLanguage_clicked();

    void on_pushButton_open_clicked();

    void on_pushButton_save_clicked();

    void updateDataBase();

    void openDataBase();

    void on_pushButton_execute_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_lineEdit_query_textEdited(const QString &arg1);

    void getFileName();

    void translateApp();

private:
    Ui::Dialog *ui;

    bool programmaticChange; // Перменная определения програмированного изменения комбобокса // Variable for determining the programmed change of the combobox

    QString mainLanguage; // Язык на который переведена программа // The language the program has been translated into

    QString previousLanguage; // Язык на которые была переведена программа // The language into which the program was translated

    QString dbPath; // Путь к текущей БД // Path to the current database

    DataBaseManager dbManager; // Менеджер для управления БД // Manager for database management

    QMap<QString, QPushButton*> ButtonMap; // Словарь для хранения "Кнопок" // Dictionary for storing "Buttons"

};
#endif // DIALOG_H
