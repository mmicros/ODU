#include <process.h>

void process::randomize(int id){
    this->pid = id;
    //qDebug()<<"id= " << id;

    //assign random prior ity
    int random = rand()% 9 +1;
    this->priority = random;


    //assign random number of resources needed
    random = rand()% 3 +1;
    resources_needed = random;

    //assign random CPU burst time
    random = rand()% 15 +1;
    cpu_bursts = random;
}
