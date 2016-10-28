#include <Scheduler.h>

#define PERIOD_OF_TASK        300000L
#define PERIOD_OF_LOOP        10000L
#define LED_HEARTBEAT         9

// Criando o scheduler para tarefa periodicas
// Parametros:
//            PERIOD_OF_LOOP � tempo que demora para executar o loop.
//            PERIOD_OF_TASK � o per�odo ou intervalo de repeti��o da tarefa 
//            que � executada em no metodo onTime().
//            LED_HEARTBEAT � o pino onde se liga o led de heartbeat. O per�odo 
//            de flashing do led � igual ao parametro PERIOD_OF_LOOP. O led        
//            pisca por um periodo de 10 mS.   
Scheduler scheduler(PERIOD_OF_LOOP, PERIOD_OF_TASK, LED_HEARTBEAT);
  
void setup()
{  
  Serial.begin(9600);

  // Partida do scheduler.
  scheduler.start();  
}

void loop(){
  //Codigo do usuario 
  // ...  
  // ...
  // ...
  
  // Verificar se j� � hora de chamar a tarefa periodica
  if(scheduler.onTime()){    
     Serial.print(".");
  }
  // Faz um ajuste do tempo de forma a garantir que o loop seja periodico
  scheduler.fitting();
}

