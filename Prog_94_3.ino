/*  ----------------------------------------------------------------
    http://www.prometec.net/rover-4x4
    Prog_94_3
    
    Programando los movimientos basicos de un Rover 4x4
    Giro sobre su centro geometrico
--------------------------------------------------------------------  
*/
#include <AFMotor.h>

AF_DCMotor Motor1(1);
AF_DCMotor Motor2(2);
AF_DCMotor Motor3(3);
AF_DCMotor Motor4(4);

int Vel = 180 ;    // Define la velocidad base del Rover
float P = 0.25 ;      // Proporcion de giro

void setup() 
{
   Serial.begin(9600);
}

void loop() 
{    
    delay(3000);
    Avance();
    delay(2000);
    Retroceso();
    delay(2000);
    giroIzquierda();
    delay(4000);
    giroDerecha();
    delay(4000);
}

void SetVel(int v1, int v2, int v3, int v4)
{
         Motor1.setSpeed(v1);
         Motor2.setSpeed(v2);
         Motor3.setSpeed(v3);
         Motor4.setSpeed(v4);         
}

void Avance()
{ 
  SetVel(Vel,Vel,Vel,Vel);
  Motor1.run(FORWARD) ;
  Motor2.run(FORWARD);
  Motor3.run(FORWARD);
  Motor4.run(FORWARD); 
}

void Retroceso()
{ 
  SetVel(Vel,Vel,Vel,Vel);
  Motor1.run(BACKWARD) ;
  Motor2.run(BACKWARD);
  Motor3.run(BACKWARD);
  Motor4.run(BACKWARD);
}

void Paro()
{ Motor1.run(RELEASE);
  Motor2.run(RELEASE);
  Motor3.run(RELEASE);
  Motor4.run(RELEASE); 
}

void giroIzquierda()
{  
   SetVel( Vel, Vel, Vel, Vel) ;
    
    Motor1.run(BACKWARD) ;
    Motor2.run(FORWARD);
    Motor3.run(BACKWARD);
    Motor4.run(FORWARD);    
}
         
void giroDerecha()
{  
    SetVel( Vel, Vel, Vel, Vel) ;
    
    Motor1.run(FORWARD) ;
    Motor2.run(BACKWARD);
    Motor3.run(FORWARD);
    Motor4.run(BACKWARD);    
}

  
  

