// Код диалогового окна для выбора языка пользовательского интерфейса
// Code of the dialog box for selecting the user interface language
#include "languagedialog.h"
#include "ui_languagedialog.h"
// Конструктор диалогового окна
// Dialog Box Constructor
LanguageDialog::LanguageDialog(QWidget *parent, QString currentLanguage) :
    QDialog(parent),
    ui(new Ui::LanguageDialog)
{
    ui->setupUi(this);

    selectedLanguage=currentLanguage;

    setAllLanguages(allLanguages);

    setUpLanguageListView();
}

// Деструктор диалогового окна
// Dialog Box Destructor
LanguageDialog::~LanguageDialog()
{
    delete ui;
}

// Обработчик нажатия кнопки "Далее"
// Handler for clicking the "Next" button
void LanguageDialog::on_pushButton_accept_clicked()
{
    QString language;
    getLanguage(language); // Получаем выбранный язык // Getting the selected language
    if(language.isEmpty()){
        // Ничего не делаем // Doing nothing
    }
    else{
        accept();
    }
}

// Получение выбранного языка
// Getting the selected language
void LanguageDialog::getLanguage(QString &arg)
{
    arg=selectedLanguage;
}

// Установка выбранного языка
// Setting the selected language
void LanguageDialog::setLanguage(QString &arg)
{
    selectedLanguage=arg;
}

// Обработчик нажатия кнопки "Отмена"
// Handler for clicking the "Cancel" button
void LanguageDialog::on_pushButton_cancel_clicked()
{
    reject();
}

// Обработчик изменения текста в поле ввода для поиска языков
// Handler for changing text in the input field to search for languages
void LanguageDialog::on_lineEdit_language_textEdited(const QString &arg1)
{
    QStringList filteredLanguages;

    // Фильтруем доступные языки по тексту поиска
    // Filtering available languages by search text
    foreach (const QString &language, allLanguages) {
        if (language.contains(arg1, Qt::CaseInsensitive)) {
            filteredLanguages.append(language);
        }
    }

    LanguageListModel->setStringList(filteredLanguages);
}

// Установка списка всех доступных языков
// Setting the list of all available languages
void LanguageDialog::setAllLanguages(QList<QString> &Languages)
{
    QList<QString> supportive;

    QString systemLocaleName = QLocale::system().name();

    QMap<QString, QString> localLanguages = {
        {"ru_RU", "Русский"},
        {"en_US", "English"},
        {"es_ES", "Español"},
        {"fr_FR", "Français"},
        {"de_DE", "Deutsch"},
        {"nl_NL", "Nederlands"},
        {"it_IT", "Italiano"},
        {"pt_PT", "Português"},
        {"zh_CN", "中文"},
        {"ja_JP", "日本語"},
        {"ko_KR", "한국어"},
        {"ar_SA", "العربية"},
        {"tr_TR", "Türkçe"},
        {"pl_PL", "Polski"},
        {"mi_NZ", "Māori"}
    };

    if (localLanguages.contains(systemLocaleName)) {
        supportive << localLanguages[systemLocaleName];
    }

    QList<QString> otherLanguages = {
        "English", "Español", "Français", "Deutsch", "Nederlands",
        "Italiano", "Português", "中文", "日本語", "한국어",
        "العربية", "Türkçe", "Polski", "Русский", "Māori"
    };

    for (const QString &language : otherLanguages) {
        if (!supportive.contains(language)) {
            supportive << language;
        }
    }

    Languages.clear();
    Languages=supportive;
}

// Настройка ListView
// ListView Setup
void LanguageDialog::setUpLanguageListView()
{
    LanguageListModel = new QStringListModel(this);

    LanguageListModel->setStringList(allLanguages);

    QFont font;
    font.setPointSize(14);
    ui->listView_language->setFont(font);

    ui->listView_language->setModel(LanguageListModel);
    ui->listView_language->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView_language->setFocusPolicy(Qt::NoFocus);
}

// Обработчик клика по элементу списка языков
// Handler for a click on an item in the list of languages
void LanguageDialog::on_listView_language_clicked(const QModelIndex &index)
{
    QString selectedLanguage = index.data(Qt::DisplayRole).toString();
    this->selectedLanguage=selectedLanguage;
}
