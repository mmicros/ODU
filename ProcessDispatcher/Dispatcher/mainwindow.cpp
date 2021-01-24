#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

// Lists for all types of processes
std::list<process> ready ;
std::list<process> blocked ;
std::list<process> running ;

int process_counter = 1;
int resources = 4;
int clock_cycle = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMainWindow::showMaximized();
    updateView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_init_btn_clicked(){
    for(int i=0; i<9; i++){

        // create new process
        process* p = new process();
        p->randomize(process_counter);
        process_counter++;

        // add new process to priority "ready" queues.
        ready.push_back(*p);
    }

    // sort processes in ready queue based on priority
    ready.sort();

    // update the GUI tables
    updateView();

    // Disable button (we want to initialize only once)
    ui->init_btn->setDisabled(true);
}

void MainWindow::updateTable(QString table, std::list<process> l){

    std::list<process>::iterator litr;
    QString s;
    QTableWidgetItem* item;
    QTableWidget* t;

    if(table == "ready")
        t = ui->readyQueue;
    else if(table == "running")
        t = ui->Running;
    else
        t = ui->blocked;

    litr = l.begin();
    while(litr!=l.end()){

        //insert new row
        int row = t->rowCount();
        t->insertRow(row);

        // write pid to table
        s = QString::number(litr->getPid());
        item = new QTableWidgetItem(s);
        t->setItem(row,0,item);

        //write priority to table
        s = QString::number(litr->getPriority());
        item = new QTableWidgetItem(s);
        t->setItem(row,1,item);

        // write resources to table
        s = QString::number(litr->getResources());
        item = new QTableWidgetItem(s);
        t->setItem(row,2,item);

        // write CPU Bursts to table
        s = QString::number(litr->getBursts());
        item = new QTableWidgetItem(s);
        t->setItem(row,3,item);

        litr++;
    }
}

void MainWindow::updateView(){

    std::list<process>::iterator litr;
    QString table,s;

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //          TABLE UPDATES
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // clear tables
    ui->readyQueue->setRowCount(0);
    ui->Running->setRowCount(0);
    ui->blocked->setRowCount(0);

    table = "ready";
    updateTable(table,ready);

    table = "running";
    updateTable(table,running);

    table = "blocked";
    updateTable(table,blocked);


    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //          UPDATE COUNTERS
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    //Display number of resources available
    s = QString::number(resources);
    ui->resCount->setText(s);

    //Display clock cycle
    s = QString::number(clock_cycle);
    ui->clock_cycles->setText(s);

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //          ACTIVATE/DEACTIVATE BUTTONS
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Buttons and Combos for Ready list
    if(ready.size()==0){
        ui->send_to_cpu->setDisabled(true);
        ui->context_switch->setDisabled(true);
    }
    else{
        ui->send_to_cpu->setDisabled(false);
        //ui->context_switch->setDisabled(false);
    }

    // Buttons and Combos for Running list
    if(running.size()==0){
        ui->execute->setDisabled(true);
        ui->Block->setDisabled(true);
        ui->terminate->setDisabled(true);
        ui->block_combo->setDisabled(true);
        ui->terminate_combo->setDisabled(true);
    }
    else{
        ui->execute->setDisabled(false);
        ui->Block->setDisabled(false);
        ui->terminate->setDisabled(false);

        if (running.size() == 1){
            ui->block_combo->setDisabled(true);
            ui->terminate_combo->setDisabled(true);
        }
        else{
            ui->block_combo->setDisabled(false);
            ui->terminate_combo->setDisabled(false);
        }
    }

    // Buttons and Combos for Blocked list
    if(blocked.size()==0){
        ui->send_to_ready->setDisabled(true);
        ui->ready_combo->setDisabled(true);
    }
    else{
        ui->send_to_ready->setDisabled(false);

        if (blocked.size() == 1)
            ui->ready_combo->setDisabled(true);
        else
            ui->ready_combo->setDisabled(false);
    }
}

void MainWindow::on_add_clicked()
{
    // create new process
    process* p = new process();
    p->randomize(process_counter);
    process_counter++;

    // add new process to priority "ready" queue.
    ready.push_back(*p);

    // sort processes in ready queue based on priority
    ready.sort();

    // update the GUI tables
    updateView();
}

void MainWindow::on_execute_clicked()
{
    if (!running.empty()){
        //increment time step
        clock_cycle++;

        //update running processes (bursts)
        std::list<process>::iterator litr;
        litr = running.begin();

        while(litr != running.end()){
            if (litr->getBursts()>1)
                litr->decrementBursts();
            else if (litr->getBursts() == 1){
                litr->decrementBursts();
                QString message = "A process has finished execution. \n Please terminate the process.";
                ui->messageBox->setText(message);

            }
            else {}

            litr++;
        }
        updateView();
    }
}

void MainWindow::on_send_to_cpu_clicked()
{
    std::list<process>::iterator litr;

    if (running.size() == 0){
        litr = ready.begin();

        //process takes resources
        resources -= litr->getResources();

        // add process to running list
        running.push_back(*litr);

        // add item to dropdown menu
        QString s;
        s = QString::number(litr->getPid());
        ui->block_combo->addItem(s, QVariant(litr->getPid()) );
        ui->terminate_combo->addItem(s,0);

        ready.pop_front();
        clock_cycle++;
    }
    else{
        litr = ready.begin();
        if (resources >= litr->getResources()){

            //process takes resources
            resources -= litr->getResources();

            // add process to running list
            running.push_back(*litr);

            // add item to dropdown menu
            QString s;
            s = QString::number(litr->getPid());
            ui->block_combo->addItem(s, QVariant(litr->getPid()) );
            ui->terminate_combo->addItem(s,0);

            ready.pop_front();
            clock_cycle++;
        }
        else{
            QString message = "Not enough resources to run this process. Perform context switch.";
            ui->messageBox->setText(message);
            ui->context_switch->setEnabled(true);
        }
    }

    // insert pIDs into combo boxes
    litr = running.begin();

    updateView();
}

void MainWindow::on_terminate_clicked()
{
    std::list<process>::iterator litr = running.begin();

    if(running.size()==1){
        resources += litr->getResources();
        running.pop_front();
        ui->block_combo->removeItem(ui->block_combo->currentIndex());
        ui->terminate_combo->removeItem(ui->block_combo->currentIndex());

    }
    else{
        // find which process was selected in combo box
        int i=ui->terminate_combo->currentIndex();

        // iterate to item to be blocked
        for (int j=0; j<i; j++)
            litr++;

        // restore the resources the process used
        resources += litr->getResources();

        // remove process from running list and combo boxes
        running.remove(*litr);
        ui->block_combo->removeItem(i);
        ui->terminate_combo->removeItem(i);
    }
    clock_cycle++;
    updateView();

}

void MainWindow::on_Block_clicked()
{
    std::list<process>::iterator litr = running.begin();

    if(running.size()==1){

        // restore the resources the process used
        resources += litr->getResources();

        // add it to blocked queue and combo
        blocked.push_back(*litr);

        QString s;
        s = QString::number(litr->getPid());
        ui->ready_combo->addItem(s, QVariant(litr->getPid()) );

        // remove process from running queue and combo boxes
        running.pop_front();
        ui->block_combo->removeItem(ui->block_combo->currentIndex());
        ui->terminate_combo->removeItem(ui->terminate_combo->currentIndex());
    }
    else{
        // find which process was selected in combo box
        int i = ui->block_combo->currentIndex();

        // iterate to item to be blocked
        for (int j=0; j<i; j++)
            litr++;

        // restore the resources the process used
        resources += litr->getResources();

        // add it to blocked queue and combo
        blocked.push_back(*litr);

        QString s;
        s = QString::number(litr->getPid());
        ui->ready_combo->addItem(s, QVariant(litr->getPid()) );

        // remove process from running list and combo boxes
        running.remove(*litr);
        ui->block_combo->removeItem(i);
        ui->terminate_combo->removeItem(i);
    }
    clock_cycle++;
    updateView();
}

void MainWindow::on_send_to_ready_clicked()
{
    std::list<process>::iterator litr = blocked.begin();

    if(running.size()==1){

        ready.push_back(*litr);
        ready.sort();

        blocked.pop_front();

        ui->ready_combo->removeItem(ui->block_combo->currentIndex());
    }
    else{
        // find which process was selected in combo box
        int i = ui->ready_combo->currentIndex();

        // iterate to item to be restored to ready list
        for (int j=0; j<i; j++)
            litr++;


        // add it to blocked queue
        ready.push_back(*litr);
        ready.sort();

        // remove process from blocked list and combo boxes
        blocked.remove(*litr);
        ui->ready_combo->removeItem(i);
    }
    updateView();
}

void MainWindow::on_context_switch_clicked()
{
    std::list<process>::iterator litr = ready.begin();

    // if there are not enough resources for the process to run;
    // Start blocking processes (from oldest to newest) until
    // enough resources have been freed.

    while( resources < litr->getResources()){
        std::list<process>::iterator ritr = running.begin();

        // restore the resources the process used
        resources += ritr->getResources();

        // add it to blocked queue and combo
        blocked.push_back(*ritr);

        QString s;
        s = QString::number(ritr->getPid());
        ui->ready_combo->addItem(s, QVariant(ritr->getPid()) );

        running.pop_front();

        ui->block_combo->removeItem(ui->block_combo->currentIndex());
        ui->terminate_combo->removeItem(ui->terminate_combo->currentIndex());
    }

    //process takes resources
    resources -= litr->getResources();

    // add process to running list
    running.push_back(*litr);

    // add item to dropdown menu
    QString s;
    s = QString::number(litr->getPid());
    ui->block_combo->addItem(s, QVariant(litr->getPid()) );
    ui->terminate_combo->addItem(s,QVariant(litr->getPid()));

    // disable "context switch" button
    ui->context_switch->setDisabled(true);

    // increment execution time
    clock_cycle = clock_cycle +2;

    ready.pop_front();
    updateView();
}
