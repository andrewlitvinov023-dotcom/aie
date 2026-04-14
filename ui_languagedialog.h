/********************************************************************************
** Form generated from reading UI file 'languagedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LANGUAGEDIALOG_H
#define UI_LANGUAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LanguageDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_language;
    QPushButton *pushButton_accept;
    QPushButton *pushButton_cancel;
    QListView *listView_language;
    QLineEdit *lineEdit_language;

    void setupUi(QDialog *LanguageDialog)
    {
        if (LanguageDialog->objectName().isEmpty())
            LanguageDialog->setObjectName(QString::fromUtf8("LanguageDialog"));
        LanguageDialog->resize(240, 480);
        LanguageDialog->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"QListView {\n"
"    background-color: white; /* \320\241\320\262\320\265\321\202\320\273\321\213\320\271 \321\204\320\276\320\275 */\n"
"    border: 1px solid #d0d0d0; \n"
"    border-radius: 5px;\n"
"    color: #333; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    gridline-color: #d0d0d0; /* \320\246\320\262\320\265\321\202 \321\201\320\265\321\202\320\272\320\270 \321\202\320\260\320\261\320\273\320\270\321\206\321\213 */\n"
"}\n"
"QListView::item {\n"
"    height: 40px; /* \320\222\321\213\321\201\320\276\321\202\320\260 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260 */\n"
"    border: 1px solid lightgray; /* \320\236\320\261\320\262\320\276\320\264\320\272\320"
                        "\260 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260 */\n"
"    font-size: 14px; /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"}\n"
"\n"
"QListView::item:hover {\n"
"    background: lightgray; /* \320\246\320\262\320\265\321\202 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QListView::item:selected {\n"
"    background: lightblue; /* \320\246\320\262\320\265\321\202 \320\277\321\200\320\270 \320\262\321\213\320\261\320\276\321\200\320\265 */\n"
"    color: white; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\321\200\320\270 \320\262\321\213\320\261\320\276\321\200\320\265 */\n"
"    border: none; /* \320\243\320\261\321\200"
                        "\320\260\321\202\321\214 \320\276\320\261\320\262\320\276\320\264\320\272\321\203 */\n"
"    outline: none; /* \320\243\320\261\321\200\320\260\321\202\321\214 \320\262\320\275\320\265\321\210\320\275\320\270\320\271 \320\272\320\276\320\275\321\202\321\203\321\200 (outline) */\n"
"}\n"
"\n"
"QListView::item:selected {\n"
"    background: lightblue; /* \320\246\320\262\320\265\321\202 \320\277\321\200\320\270 \320\262\321\213\320\261\320\276\321\200\320\265 */\n"
"    color: white; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\321\200\320\270 \320\262\321\213\320\261\320\276\321\200\320\265 */\n"
"    border: none; /* \320\243\320\261\321\200\320\260\321\202\321\214 \320\276\320\261\320\262\320\276\320\264\320\272\321\203 */\n"
"    outline: none; /* \320\243\320\261\321\200\320\260\321\202\321\214 \320\262\320\275\320\265\321\210\320\275\320\270\320\271 \320\272\320\276\320\275\321\202\321\203\321\200 (outline) */\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    wid"
                        "th: 10px; /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\262\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\320\276\320\271 \320\277\320\276\320\273\320\276\321\201\321\213 \320\277\321\200\320\276\320\272\321\200\321\203\321\202\320\272\320\270 */\n"
"    background: white; /* \320\237\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #000000; /* \320\246\320\262\320\265\321\202 \320\276\320\261\320\273\320\260\321\201\321\202\320\270 \320\277\321\200\320\276\320\272\321\200\321\203\321\202\320\272\320\270 */\n"
"    min-height: 20px; /* \320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \320\262\321\213\321\201\320\276\321\202\320\260 \320\276\320\261\320\273\320\260\321\201\321\202\320\270 \320\277\321\200\320\276\320\272\321\200\321\203\321\202\320\272\320\270 */\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBa"
                        "r::sub-line:vertical {\n"
"    height: 0; /* \320\241\320\264\320\265\320\273\320\260\321\202\321\214 \320\272\320\275\320\276\320\277\320\272\320\270 \320\277\321\200\320\276\320\272\321\200\321\203\321\202\320\272\320\270 \320\275\320\265\320\262\320\270\320\264\320\270\320\274\321\213\320\274\320\270 */\n"
"}\n"
"\n"
""));
        LanguageDialog->setSizeGripEnabled(false);
        LanguageDialog->setModal(false);
        gridLayout = new QGridLayout(LanguageDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_language = new QLabel(LanguageDialog);
        label_language->setObjectName(QString::fromUtf8("label_language"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_language->sizePolicy().hasHeightForWidth());
        label_language->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_language, 1, 0, 1, 2);

        pushButton_accept = new QPushButton(LanguageDialog);
        pushButton_accept->setObjectName(QString::fromUtf8("pushButton_accept"));

        gridLayout->addWidget(pushButton_accept, 4, 0, 1, 1);

        pushButton_cancel = new QPushButton(LanguageDialog);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        gridLayout->addWidget(pushButton_cancel, 4, 1, 1, 1);

        listView_language = new QListView(LanguageDialog);
        listView_language->setObjectName(QString::fromUtf8("listView_language"));
        listView_language->setStyleSheet(QString::fromUtf8("QListView::item {\n"
"    height: 40px; /* \320\222\321\213\321\201\320\276\321\202\320\260 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260 */\n"
"    border: 1px solid lightgray; /* \320\236\320\261\320\262\320\276\320\264\320\272\320\260 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260 */\n"
"    font-size: 14px; /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"}\n"
"\n"
"QListView::item:hover {\n"
"    background: lightgray; /* \320\246\320\262\320\265\321\202 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QListView::item:selected {\n"
"    background: lightblue; /* \320\246\320\262\320\265\321\202 \320\277\321\200\320\270 \320\262\321\213\320\261\320\276"
                        "\321\200\320\265 */\n"
"    color: white; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\321\200\320\270 \320\262\321\213\320\261\320\276\321\200\320\265 */\n"
"    border: none; /* \320\243\320\261\321\200\320\260\321\202\321\214 \320\276\320\261\320\262\320\276\320\264\320\272\321\203 */\n"
"    outline: none; /* \320\243\320\261\321\200\320\260\321\202\321\214 \320\262\320\275\320\265\321\210\320\275\320\270\320\271 \320\272\320\276\320\275\321\202\321\203\321\200 (outline) */\n"
"}\n"
"\n"
"\n"
"QScrollBar:vertical {\n"
"    width: 10px; /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\262\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\320\276\320\271 \320\277\320\276\320\273\320\276\321\201\321\213 \320\277\321\200\320\276\320\272\321\200\321\203\321\202\320\272\320\270 */\n"
"    background: white; /* \320\237\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"}\n"
"\n"
"QS"
                        "crollBar::handle:vertical {\n"
"    background: #000000; /* \320\246\320\262\320\265\321\202 \320\276\320\261\320\273\320\260\321\201\321\202\320\270 \320\277\321\200\320\276\320\272\321\200\321\203\321\202\320\272\320\270 */\n"
"    min-height: 20px; /* \320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \320\262\321\213\321\201\320\276\321\202\320\260 \320\276\320\261\320\273\320\260\321\201\321\202\320\270 \320\277\321\200\320\276\320\272\321\200\321\203\321\202\320\272\320\270 */\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    height: 0; /* \320\241\320\264\320\265\320\273\320\260\321\202\321\214 \320\272\320\275\320\276\320\277\320\272\320\270 \320\277\321\200\320\276\320\272\321\200\321\203\321\202\320\272\320\270 \320\275\320\265\320\262\320\270\320\264\320\270\320\274\321\213\320\274\320\270 */\n"
"}\n"
"\n"
""));
        listView_language->setFrameShape(QFrame::StyledPanel);
        listView_language->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        listView_language->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        gridLayout->addWidget(listView_language, 3, 0, 1, 2);

        lineEdit_language = new QLineEdit(LanguageDialog);
        lineEdit_language->setObjectName(QString::fromUtf8("lineEdit_language"));

        gridLayout->addWidget(lineEdit_language, 2, 0, 1, 2);


        retranslateUi(LanguageDialog);

        QMetaObject::connectSlotsByName(LanguageDialog);
    } // setupUi

    void retranslateUi(QDialog *LanguageDialog)
    {
        LanguageDialog->setWindowTitle(QApplication::translate("LanguageDialog", "Dialog", nullptr));
        label_language->setText(QApplication::translate("LanguageDialog", "<html><head/><body><p><span style=\" font-size:10pt;\">Choose the language</span></p></body></html>", nullptr));
        pushButton_accept->setText(QApplication::translate("LanguageDialog", "Ok", nullptr));
        pushButton_cancel->setText(QApplication::translate("LanguageDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LanguageDialog: public Ui_LanguageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LANGUAGEDIALOG_H
