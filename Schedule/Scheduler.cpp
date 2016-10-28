#include "Scheduler.h"

Scheduler::Scheduler(unsigned long periodOfLoop, unsigned long periodOfTask, int ledPin)
{
  this->periodOfLoop = periodOfLoop;            
  this->periodOfTask = periodOfTask;
  this->ledPin = ledPin;
  
  // Configuração do pino usado pelo led de heart beat
  pinMode(ledPin, OUTPUT);  
  digitalWrite(ledPin, HIGH);    
}            

void Scheduler::start() 
{
  time0 = millis();    
  time1 = time0;     
}

int Scheduler::onTime()
{        
  unsigned long tmr;       
   
  if((tmr = millis() - time1) >= periodOfTask)
  {
#ifdef DEBUG            
     Serial.print("Task: ");     
     Serial.println(tmr);         
#endif     
     time1 = millis();
     return 1;
  }
  
  return 0;
}

void Scheduler::fitting()
{  
  unsigned long tmr;       

#ifdef DEBUG  
  Serial.print("Led HB: ");  
  Serial.println(tmr);  
#endif  
  digitalWrite(ledPin, HIGH);  delay(10); digitalWrite(ledPin, LOW);        
                  
  while((tmr = millis() - time0) < periodOfLoop)
  {        
     delay(1);                  
  }
  
  time0 = millis();  
}
