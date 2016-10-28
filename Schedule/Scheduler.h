#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <Arduino.h>

class Scheduler
{
public:      
      Scheduler(unsigned long periodOfLoop, unsigned long periodOfTask, int ledPin);
      
      void start();
      
      int onTime();
      
      void fitting();
      
private:
      unsigned long periodOfLoop;
      unsigned long periodOfTask;
      unsigned long time0;
      unsigned long time1;  
      int ledPin;

};

#endif
