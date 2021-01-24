#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <list>
#include <cstdlib>
#include <stdio.h>
#include <process.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void updateTable(QString table, std::list<process> l);

    void updateView();

    void on_init_btn_clicked();

    void on_add_clicked();

    void on_execute_clicked();

    void on_send_to_cpu_clicked();

    void on_terminate_clicked();

    void on_Block_clicked();

    void on_send_to_ready_clicked();

    void on_context_switch_clicked();

private:
    Ui::MainWindow *ui;

};





#endif // MAINWINDOW_H
