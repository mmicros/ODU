#ifndef PROCESS_H
#define PROCESS_H

#include <cstdlib>
#include <QDebug>

class process{
    int pid;
    int priority;
    int resources_needed;
    int cpu_bursts;


  public:
    void randomize(int id);

    void setPid(int id){this->pid = id; }
    int getPid(){ return this->pid;}

    void setPriority(int p){this->priority = p; }
    int getPriority(){ return this->priority;}

    void setResources(int r){this->resources_needed = r; }
    int getResources(){ return resources_needed;}

    void decrementBursts(){this->cpu_bursts--; }
    int getBursts(){ return cpu_bursts;}

    bool operator<( const process& p2){
        if(this->priority < p2.priority)
            return true;

        else if(this->priority == p2.priority){
            if (this->pid < p2.pid)
                return true;
            else
                return false;
        }
        else
            return false;
    }

    bool operator==( const process& p2){
        if(this->getPid() == p2.pid)
            return true;
        else
            return false;
    }
};

#endif // PROCESS_H
