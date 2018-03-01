# Robot móvil con motores de corriente continua.

## Propuesta del proyecto
Programación de un robot móvil con motores DC y diversos sensores.

El diagrama de bloques del robot móvil es el siguiente

<a href="" target="_blank"><img width="637" height="256" border="0" align="center"
src="https://github.com/leobotmanuel/ProgramandoObjetosTecnologicos/blob/master/software/arduino/proyectos/img/diagramaRobot.png"/></a>

## Objetos tecnológicos
- **La tarjeta de control** la forma la placa Arduino-EduBasica donde se conectan los objetos tecnológicos.

- **Motores DC** son los actuadores del robot móvil.

Su programa de funcionamiento

```cpp
/*
  Movimientos basicos del robot 
  EL INTERRUPTOR DE CORRIENTE DE EDUBASICA TIENE QUE ESTAR EN POSICION ON

  Manuel Hidalgo - LeoBot  Julio 2014
  Pablo Garcia - May 2015
*/

//Etiquetas de identificación de los pines
const int motorA_Dir1 = 8;         //pines para controlar la direccion de giro
const int motorA_Dir2 = 9;
const int motorA_Velocidad = 10;  //salida PWM para controlar la velocidad // PWM for speed
const int motorB_Dir1 = 12;       //pines para controlar la direccion de giro
const int motorB_Dir2 = 13;
const int motorB_Velocidad = 11;  //salida PWM para controlar la velocidad

//Variables
//int vPWM = 155;    //valor de la velocidad en PWM 

void setup(){
  //configuracion de los pines
  pinMode(motorA_Dir1, OUTPUT);
  pinMode(motorA_Dir2, OUTPUT);
  pinMode(motorB_Dir1, OUTPUT);
  pinMode(motorB_Dir2, OUTPUT);
  
}

void loop(){
  //forward();
  //delay(4000);              
 // stop();
 // delay(2000);
 // backw(250);
  right(127);
  //left(127);
  delay(4000); 
  stop();
  delay(2000);  
}

void forward(int v){
  int vPWM = v;
  digitalWrite(motorA_Dir1,LOW);
  digitalWrite(motorA_Dir2,HIGH); 
  analogWrite(motorA_Velocidad,vPWM);
  digitalWrite(motorB_Dir1,HIGH);
  digitalWrite(motorB_Dir2,LOW); 
  analogWrite(motorB_Velocidad,vPWM);
}
   
void backw(int v){
  int vPWM = v;
  digitalWrite(motorA_Dir1,HIGH);
  digitalWrite(motorA_Dir2,LOW); 
  analogWrite(motorA_Velocidad,vPWM);
  digitalWrite(motorB_Dir1,LOW);
  digitalWrite(motorB_Dir2,HIGH); 
  analogWrite(motorB_Velocidad,vPWM);
}

void right(int v){
  int vPWM = v;
  digitalWrite(motorA_Dir1,LOW);
  digitalWrite(motorA_Dir2,HIGH); 
  analogWrite(motorA_Velocidad,vPWM);
  digitalWrite(motorB_Dir1,LOW);
  digitalWrite(motorB_Dir2,HIGH); 
  analogWrite(motorB_Velocidad,vPWM);
}

void left(int v){
  int vPWM = v;
  digitalWrite(motorA_Dir1,HIGH);
  digitalWrite(motorA_Dir2,LOW); 
  analogWrite(motorA_Velocidad,vPWM);
  digitalWrite(motorB_Dir1,HIGH);
  digitalWrite(motorB_Dir2,LOW); 
  analogWrite(motorB_Velocidad,vPWM);
}

void stop(){
  analogWrite(motorA_Velocidad,0);
  analogWrite(motorB_Velocidad,0);
}
```

