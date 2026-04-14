#ifndef LANGUAGEDIALOG_H
#define LANGUAGEDIALOG_H

#include <QDialog>
#include <QStringListModel>
#include <QLocale>
#include <QTranslator>

#include "dialog.h"
#include "databasemanager.h"

namespace Ui {
class LanguageDialog;
}

class LanguageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LanguageDialog(QWidget *parent = nullptr, QString currentLanguage="English");
    ~LanguageDialog();

    void getLanguage(QString &arg);

    void setLanguage(QString &arg);

private slots:
    void on_pushButton_accept_clicked();

    void on_pushButton_cancel_clicked();

    void on_lineEdit_language_textEdited(const QString &arg1);

    void setUpLanguageListView();

    void setAllLanguages(QList<QString> &Languages);

    void on_listView_language_clicked(const QModelIndex &index);

private:
    Ui::LanguageDialog *ui;

    QStringListModel *LanguageListModel;

    QList<QString> allLanguages; // Языки доступные для перевода

    QString selectedLanguage; // Текущий язык

    QLocale currentLocale; // Текущая локация пользователя
};

#endif // LANGUAGEDIALOG_H
