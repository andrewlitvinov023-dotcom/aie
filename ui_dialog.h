/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_save;
    QTableWidget *tableWidget;
    QPushButton *pushButton_open;
    QPushButton *pushButton_execute;
    QLineEdit *lineEdit_query;
    QPushButton *pushButton_changeLanguage;
    QPushButton *pushButton_add;
    QComboBox *comboBox;
    QPushButton *pushButton_remove;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(460, 460);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        Dialog->setFont(font);
        Dialog->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: white;\n"
"    border: 2px solid lightblue;\n"
"    border-radius: 10px;\n"
"    padding: 5px 10px;\n"
"    color: black;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: lightblue;\n"
"    color: white;\n"
"}\n"
"QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid lightblue;\n"
"    border-radius: 5px;\n"
"    padding: 3px;\n"
"    color: black;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border-color: blue;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: white;\n"
"}\n"
"\n"
"\n"
"\n"
"/* \320\241\321\202\320\270\320\273\320\270 \320\264\320\273\321\217 QComboBox */\n"
"QComboBox {\n"
"    background-color: #fff;\n"
"    border: 2px solid lightblue;\n"
"    border-radius: 5px;\n"
"    padding: 3px;\n"
"    color: #333; \n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border-color: blue; \n"
"}\n"
"QComboBox QListView {\n"
"    background-color: white;   \n"
"    outline: 0;     \n"
"    color: white;\n"
"    selection-background-color: light"
                        "blue; \n"
"}\n"
"\n"
"\n"
"/* \320\241\321\202\320\270\320\273\320\270 \320\264\320\273\321\217 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"QComboBox QAbstractItemView\n"
" {\n"
"    background-color: #fff;\n"
"    border: 1px solid #B5B8B1; \n"
"    color: #333; \n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item \n"
"{\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item:selected \n"
"{\n"
"    background-color: #b0d4ff;\n"
"    color: #333;\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: center right;\n"
"    width: 20px;\n"
"    height: 25px;\n"
"    border: none;\n"
"    image: url(:/arrow/arrow.png); /* \320\237\321\203\321\202\321\214 \320\272 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\216 \321\201\321\202\321\200\320\265\320\273\320\272\320\270 */\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    wid"
                        "th: 0;\n"
"    height: 0;\n"
"}\n"
"\n"
"QComboBox::up-arrow,\n"
"QComboBox::down-arrow:on {\n"
"    width: 20px;\n"
"    height: 25px;\n"
"    border: none;\n"
"}\n"
"\n"
"QComboBox::up-arrow:on {\n"
"    image: url(:/arrow/arrowUP.png); /* \320\237\321\203\321\202\321\214 \320\272 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\216 \321\201\321\202\321\200\320\265\320\273\320\272\320\270 \320\262 \320\260\320\272\321\202\320\270\320\262\320\275\320\276\320\274 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"QScrollBar:vertical {\n"
"    border: 0px solid #999999;\n"
"    background: white;\n"
"    width: 10px;\n"
"    margin: 0px 0px 0px 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    min-height: 0px;\n"
"    border: 0px solid red;\n"
"    border-radius: 5px;\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:1, fx:0.5, fy:0.5,\n"
"                                stop"
                        ":0 rgba(0, 120, 255, 255),\n"
"                                stop:1 rgba(0, 200, 255, 255));\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"    height: 0px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    border: 0px solid #999999;\n"
"    background: white;\n"
"    height: 10px;\n"
"    margin: 0px 0px 0px 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    min-width: 0px;\n"
"    border: 0px solid red;\n"
"    border-radius: 5px;\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:1, fx:0.5, fy:0.5,\n"
"                                stop:0 rgba(0, 120, 255, 255),\n"
"                                stop:1 rgba(0, 200, 255, 255));\n"
"\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"    width: 0px;\n"
"    subcontrol-position: right;\n"
"    subcontrol-origin: margin;\n"
"}\n"
""
                        "\n"
"QScrollBar::sub-line:horizontal {\n"
"    width: 0px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}\n"
""));
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_save = new QPushButton(Dialog);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(10);
        pushButton_save->setFont(font1);

        gridLayout->addWidget(pushButton_save, 1, 2, 1, 1);

        tableWidget = new QTableWidget(Dialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(10);
        tableWidget->setFont(font2);
        tableWidget->setFocusPolicy(Qt::NoFocus);
        tableWidget->setStyleSheet(QString::fromUtf8("/* \320\241\321\202\320\270\320\273\320\270 \320\264\320\273\321\217 QTableWidget */\n"
"QTableWidget {\n"
"    background-color: white; /* \320\241\320\262\320\265\321\202\320\273\321\213\320\271 \321\204\320\276\320\275 */\n"
"    border: 1px solid #d0d0d0; \n"
"    border-radius: 5px;\n"
"    color: #333; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    gridline-color: #d0d0d0; /* \320\246\320\262\320\265\321\202 \321\201\320\265\321\202\320\272\320\270 \321\202\320\260\320\261\320\273\320\270\321\206\321\213 */\n"
"}\n"
"\n"
"QTableWidget QHeaderView::section {\n"
"    background-color: white; \n"
"    border: none;\n"
"    padding: 5px;\n"
"    color: #555; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\276\320\262 */\n"
"}\n"
"\n"
"QTableWidget:item:selected {\n"
"    background-color: lightblue; /* \320\230\320\267\320\274\320\265\320\275\320\265\320\275"
                        "\320\270\320\265 \321\206\320\262\320\265\321\202\320\260 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\271 \321\217\321\207\320\265\320\271\320\272\320\270 */\n"
"}\n"
"\n"
""));
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        gridLayout->addWidget(tableWidget, 4, 0, 1, 4);

        pushButton_open = new QPushButton(Dialog);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));
        pushButton_open->setMinimumSize(QSize(0, 40));
        QFont font3;
        font3.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font3.setPointSize(14);
        pushButton_open->setFont(font3);

        gridLayout->addWidget(pushButton_open, 0, 0, 1, 4);

        pushButton_execute = new QPushButton(Dialog);
        pushButton_execute->setObjectName(QString::fromUtf8("pushButton_execute"));
        pushButton_execute->setFont(font);

        gridLayout->addWidget(pushButton_execute, 3, 3, 1, 1);

        lineEdit_query = new QLineEdit(Dialog);
        lineEdit_query->setObjectName(QString::fromUtf8("lineEdit_query"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(12);
        lineEdit_query->setFont(font4);

        gridLayout->addWidget(lineEdit_query, 3, 0, 1, 3);

        pushButton_changeLanguage = new QPushButton(Dialog);
        pushButton_changeLanguage->setObjectName(QString::fromUtf8("pushButton_changeLanguage"));
        pushButton_changeLanguage->setFont(font1);

        gridLayout->addWidget(pushButton_changeLanguage, 1, 3, 1, 1);

        pushButton_add = new QPushButton(Dialog);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setEnabled(true);
        pushButton_add->setFont(font1);

        gridLayout->addWidget(pushButton_add, 1, 0, 1, 1);

        comboBox = new QComboBox(Dialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setFont(font4);
        comboBox->setFocusPolicy(Qt::TabFocus);
        comboBox->setStyleSheet(QString::fromUtf8(""));
        comboBox->setEditable(false);
        comboBox->setDuplicatesEnabled(false);
        comboBox->setFrame(true);

        gridLayout->addWidget(comboBox, 2, 0, 1, 4);

        pushButton_remove = new QPushButton(Dialog);
        pushButton_remove->setObjectName(QString::fromUtf8("pushButton_remove"));
        pushButton_remove->setFont(font1);

        gridLayout->addWidget(pushButton_remove, 1, 1, 1, 1);

        QWidget::setTabOrder(comboBox, pushButton_remove);
        QWidget::setTabOrder(pushButton_remove, pushButton_add);
        QWidget::setTabOrder(pushButton_add, pushButton_changeLanguage);
        QWidget::setTabOrder(pushButton_changeLanguage, pushButton_save);
        QWidget::setTabOrder(pushButton_save, lineEdit_query);
        QWidget::setTabOrder(lineEdit_query, pushButton_execute);
        QWidget::setTabOrder(pushButton_execute, pushButton_open);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        pushButton_save->setText(QApplication::translate("Dialog", "Save changes", nullptr));
        pushButton_open->setText(QApplication::translate("Dialog", "Drop file or click to open Data Base", nullptr));
        pushButton_execute->setText(QApplication::translate("Dialog", "Execute", nullptr));
        pushButton_changeLanguage->setText(QApplication::translate("Dialog", "Change language", nullptr));
        pushButton_add->setText(QApplication::translate("Dialog", "Add", nullptr));
        pushButton_remove->setText(QApplication::translate("Dialog", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
