#include <stdint.h>
#include "Arduino.h"

#ifndef SCHEDULER_H
#define SCHEDULER_H

#define MSEC 1000

class Scheduler {
  
  private:
    unsigned long _interval; // in microseconds
    unsigned long _last_Tick_Time;
    void (*_tasks[10])(); // store all tasks that needs to be run, max 10 tasks
    int _task_Count; // count of total tasks added to the scheduler
      
  public:
    Scheduler(unsigned long interval=20); // in ms, default = 20ms)
    void initLastTick(); // initLastTick to current time;
    void addTask(void (*task)()); // add task to scheduler, 'queue', FIFO
    void run(); // run all tasks added to the tasks
  

};

#endif
