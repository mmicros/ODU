/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableWidget *Running;
    QPushButton *execute;
    QLabel *running_label;
    QTableWidget *blocked;
    QLabel *blocked_label;
    QTextBrowser *messageBox;
    QPushButton *Block;
    QPushButton *terminate;
    QComboBox *block_combo;
    QComboBox *terminate_combo;
    QPushButton *send_to_ready;
    QComboBox *ready_combo;
    QFrame *running_frame;
    QFrame *frame_4;
    QPushButton *send_to_cpu;
    QTableWidget *readyQueue;
    QPushButton *context_switch;
    QLabel *ready_label;
    QFrame *frame_3;
    QTextBrowser *resCount;
    QFrame *frame_2;
    QTextBrowser *clock_cycles;
    QLabel *time_label;
    QLabel *resource_label;
    QPushButton *add;
    QPushButton *init_btn;
    QFrame *frame;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1361, 843);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Running = new QTableWidget(centralWidget);
        if (Running->columnCount() < 4)
            Running->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Running->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        Running->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        Running->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        Running->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        Running->setObjectName(QStringLiteral("Running"));
        Running->setGeometry(QRect(740, 240, 411, 181));
        Running->verticalHeader()->setVisible(false);
        execute = new QPushButton(centralWidget);
        execute->setObjectName(QStringLiteral("execute"));
        execute->setGeometry(QRect(1160, 240, 101, 51));
        execute->setStyleSheet(QLatin1String("\n"
"font: 10pt \"Arial Rounded MT Bold\";\n"
""));
        running_label = new QLabel(centralWidget);
        running_label->setObjectName(QStringLiteral("running_label"));
        running_label->setGeometry(QRect(870, 210, 121, 31));
        running_label->setStyleSheet(QLatin1String("font: 16pt \"Arial Rounded MT Bold\";\n"
"color: rgb(255, 255, 255);"));
        blocked = new QTableWidget(centralWidget);
        if (blocked->columnCount() < 4)
            blocked->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        blocked->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        blocked->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        blocked->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        blocked->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        blocked->setObjectName(QStringLiteral("blocked"));
        blocked->setGeometry(QRect(740, 480, 411, 181));
        blocked->verticalHeader()->setVisible(false);
        blocked_label = new QLabel(centralWidget);
        blocked_label->setObjectName(QStringLiteral("blocked_label"));
        blocked_label->setGeometry(QRect(830, 450, 131, 31));
        blocked_label->setStyleSheet(QLatin1String("font: 16pt \"Arial Rounded MT Bold\";\n"
"color: rgb(255, 255, 255);"));
        messageBox = new QTextBrowser(centralWidget);
        messageBox->setObjectName(QStringLiteral("messageBox"));
        messageBox->setGeometry(QRect(30, 20, 431, 181));
        messageBox->setStyleSheet(QLatin1String("background-color: rgb(255, 238, 49);\n"
"font: 12pt \"Arial Rounded MT Bold\";"));
        Block = new QPushButton(centralWidget);
        Block->setObjectName(QStringLiteral("Block"));
        Block->setGeometry(QRect(1160, 300, 101, 51));
        Block->setStyleSheet(QLatin1String("font: 10pt \"Arial Rounded MT Bold\";\n"
""));
        terminate = new QPushButton(centralWidget);
        terminate->setObjectName(QStringLiteral("terminate"));
        terminate->setGeometry(QRect(1160, 360, 101, 51));
        terminate->setStyleSheet(QLatin1String("\n"
"font: 10pt \"Arial Rounded MT Bold\";\n"
""));
        block_combo = new QComboBox(centralWidget);
        block_combo->setObjectName(QStringLiteral("block_combo"));
        block_combo->setGeometry(QRect(1280, 320, 41, 22));
        block_combo->setEditable(false);
        terminate_combo = new QComboBox(centralWidget);
        terminate_combo->setObjectName(QStringLiteral("terminate_combo"));
        terminate_combo->setGeometry(QRect(1280, 370, 41, 22));
        send_to_ready = new QPushButton(centralWidget);
        send_to_ready->setObjectName(QStringLiteral("send_to_ready"));
        send_to_ready->setGeometry(QRect(1160, 480, 101, 51));
        send_to_ready->setStyleSheet(QLatin1String("\n"
"font: 10pt \"Arial Rounded MT Bold\";\n"
""));
        ready_combo = new QComboBox(centralWidget);
        ready_combo->setObjectName(QStringLiteral("ready_combo"));
        ready_combo->setGeometry(QRect(1280, 490, 41, 22));
        running_frame = new QFrame(centralWidget);
        running_frame->setObjectName(QStringLiteral("running_frame"));
        running_frame->setGeometry(QRect(690, 210, 651, 231));
        running_frame->setStyleSheet(QStringLiteral("background-color: rgb(148, 148, 148);"));
        running_frame->setFrameShape(QFrame::StyledPanel);
        running_frame->setFrameShadow(QFrame::Raised);
        frame_4 = new QFrame(centralWidget);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(690, 450, 651, 221));
        frame_4->setStyleSheet(QStringLiteral("background-color: rgb(148, 148, 148);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        send_to_cpu = new QPushButton(centralWidget);
        send_to_cpu->setObjectName(QStringLiteral("send_to_cpu"));
        send_to_cpu->setGeometry(QRect(530, 240, 111, 51));
        send_to_cpu->setStyleSheet(QLatin1String("font: 10pt \"Arial Rounded MT Bold\";\n"
""));
        readyQueue = new QTableWidget(centralWidget);
        if (readyQueue->columnCount() < 4)
            readyQueue->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        readyQueue->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        readyQueue->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        readyQueue->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        readyQueue->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        readyQueue->setObjectName(QStringLiteral("readyQueue"));
        readyQueue->setGeometry(QRect(60, 240, 411, 371));
        readyQueue->verticalHeader()->setVisible(false);
        context_switch = new QPushButton(centralWidget);
        context_switch->setObjectName(QStringLiteral("context_switch"));
        context_switch->setEnabled(false);
        context_switch->setGeometry(QRect(530, 300, 111, 51));
        context_switch->setStyleSheet(QLatin1String("font: 10pt \"Arial Rounded MT Bold\";\n"
""));
        ready_label = new QLabel(centralWidget);
        ready_label->setObjectName(QStringLiteral("ready_label"));
        ready_label->setGeometry(QRect(180, 210, 211, 31));
        ready_label->setStyleSheet(QLatin1String("font: 16pt \"Arial Rounded MT Bold\";\n"
"color: rgb(255, 255, 255);"));
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(30, 210, 651, 461));
        frame_3->setStyleSheet(QStringLiteral("background-color: rgb(148, 148, 148);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        resCount = new QTextBrowser(centralWidget);
        resCount->setObjectName(QStringLiteral("resCount"));
        resCount->setGeometry(QRect(1130, 90, 81, 61));
        resCount->setStyleSheet(QLatin1String("font: 30pt \"Quartz MS\";\n"
""));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(910, 20, 431, 181));
        frame_2->setStyleSheet(QStringLiteral("background-color: rgb(41, 155, 255);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        clock_cycles = new QTextBrowser(centralWidget);
        clock_cycles->setObjectName(QStringLiteral("clock_cycles"));
        clock_cycles->setGeometry(QRect(1000, 90, 81, 61));
        clock_cycles->setStyleSheet(QLatin1String("font: 30pt \"Quartz MS\";\n"
"border-color: rgb(0, 0, 0);\n"
""));
        time_label = new QLabel(centralWidget);
        time_label->setObjectName(QStringLiteral("time_label"));
        time_label->setGeometry(QRect(1000, 30, 101, 51));
        time_label->setStyleSheet(QLatin1String("font: 12pt \"Arial Rounded MT Bold\";\n"
"color: rgb(255, 255, 255);"));
        resource_label = new QLabel(centralWidget);
        resource_label->setObjectName(QStringLiteral("resource_label"));
        resource_label->setGeometry(QRect(1120, 30, 141, 51));
        resource_label->setStyleSheet(QLatin1String("font: 12pt \"Arial Rounded MT Bold\";\n"
"color: rgb(255, 255, 255);"));
        add = new QPushButton(centralWidget);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(700, 60, 111, 71));
        add->setStyleSheet(QLatin1String("font: 12pt \"Arial Rounded MT Bold\";\n"
""));
        init_btn = new QPushButton(centralWidget);
        init_btn->setObjectName(QStringLiteral("init_btn"));
        init_btn->setGeometry(QRect(570, 60, 101, 71));
        init_btn->setStyleSheet(QStringLiteral("font: 12pt \"Arial Rounded MT Bold\";"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(470, 20, 431, 181));
        frame->setStyleSheet(QStringLiteral("background-color: rgb(148, 148, 148);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        MainWindow->setCentralWidget(centralWidget);
        frame->raise();
        frame_3->raise();
        frame_4->raise();
        running_frame->raise();
        Running->raise();
        execute->raise();
        running_label->raise();
        blocked->raise();
        blocked_label->raise();
        messageBox->raise();
        Block->raise();
        terminate->raise();
        block_combo->raise();
        terminate_combo->raise();
        send_to_ready->raise();
        ready_combo->raise();
        send_to_cpu->raise();
        readyQueue->raise();
        context_switch->raise();
        ready_label->raise();
        frame_2->raise();
        clock_cycles->raise();
        time_label->raise();
        resource_label->raise();
        resCount->raise();
        add->raise();
        init_btn->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1361, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        block_combo->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = Running->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "pID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = Running->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Priority", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = Running->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Resources", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = Running->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Bursts  ", Q_NULLPTR));
        execute->setText(QApplication::translate("MainWindow", "Execute \n"
" Time Step", Q_NULLPTR));
        running_label->setText(QApplication::translate("MainWindow", "RUNNING ", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = blocked->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "pID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = blocked->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Priority", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = blocked->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Resources", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = blocked->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Bursts  ", Q_NULLPTR));
        blocked_label->setText(QApplication::translate("MainWindow", "BLOCKED", Q_NULLPTR));
        messageBox->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial Rounded MT Bold'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">WELCOME TO THE PROCESS DISPATCHER SIMULATION!!! </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1.PRESS &quot;INITIALIZE PROCESSES&quot; TO PREPOPULATE THE READY QUEUE</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	OR</p>\n"
"<p "
                        "style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2. MANUALLY ADD A PROCESS AT A TIME BY PRESSING &quot;ADD PROCESS&quot;</p></body></html>", Q_NULLPTR));
        Block->setText(QApplication::translate("MainWindow", "Block \n"
" Process", Q_NULLPTR));
        terminate->setText(QApplication::translate("MainWindow", "Terminate \n"
" Process", Q_NULLPTR));
        send_to_ready->setText(QApplication::translate("MainWindow", "Send To \n"
" Ready", Q_NULLPTR));
        send_to_cpu->setText(QApplication::translate("MainWindow", "Send Process \n"
" To CPU", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = readyQueue->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "pID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = readyQueue->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Priority", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = readyQueue->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Resources", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = readyQueue->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Bursts", Q_NULLPTR));
        context_switch->setText(QApplication::translate("MainWindow", "Context \n"
" Switch", Q_NULLPTR));
        ready_label->setText(QApplication::translate("MainWindow", "READY QUEUE", Q_NULLPTR));
        time_label->setText(QApplication::translate("MainWindow", "     TIME \n"
" ELAPSED", Q_NULLPTR));
        resource_label->setText(QApplication::translate("MainWindow", "RESOURCES \n"
" AVAILABLE", Q_NULLPTR));
        add->setText(QApplication::translate("MainWindow", "Add Process", Q_NULLPTR));
        init_btn->setText(QApplication::translate("MainWindow", "Initialize \n"
" Processes", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
