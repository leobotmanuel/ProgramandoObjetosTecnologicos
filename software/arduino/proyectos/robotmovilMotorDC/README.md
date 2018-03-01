# Robot móvil con motores de corriente continua.

## Propuesta del proyecto
Programación de un robot móvil con motores DC y diversos sensores.

El diagrama de bloques del robot móvil es el siguiente

<a href="" target="_blank"><img width="637" height="256" border="0" align="center"
src="https://github.com/leobotmanuel/ProgramandoObjetosTecnologicos/blob/master/software/arduino/proyectos/img/diagramaRobot.png"/></a>

<a href="" target="_blank"><img width="832" height="624" border="0" align="center"
src="https://github.com/leobotmanuel/ProgramandoObjetosTecnologicos/blob/master/software/arduino/proyectos/img/EducaBot_EduBasica.jpg"/></a>

## Objetos tecnológicos
- **La tarjeta de control** la forma la placa Arduino-EduBasica donde se conectan los objetos tecnológicos.

- [**Motores DC**](https://github.com/leobotmanuel/EduBasica/tree/master/software/03_Actuadores/01_MotorDC) son los actuadores del robot móvil.

Su programa de funcionamiento de movimientos básicos.

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
- [**Sensor bumper o parachoques**](https://github.com/leobotmanuel/EduBasica/tree/master/software/04_Sensores/01_Pulsador) son finales de carrera, que actúan coo pulsadores, para detectar obstáculos.

Su programa de funcionamiento

```cpp
/*
Test bumper del robot 

enero 2018 - Manuel Hidalgo / LeoBot
programa adaptado a EduBasica
*/

//Declaracion de pines

#define bumperD 18
#define bumperI 19

//Declaracion de variables
int estadoBumperD;
int estadoBumperI;

void setup(){
  //Configuracion de comunicaciones y pines
  Serial.begin(9600);
  pinMode(bumperD, INPUT);
  pinMode(bumperI, INPUT);
  
 }
 

void loop() {

  estadoBumperD = digitalRead(bumperD);
  estadoBumperI = digitalRead(bumperI);
  //monitoriza el estado
  // 1 --> NO pulsado
  // 0 --> pulsado
  Serial.print("Bumper Izquierdo: ");
  Serial.print(estadoBumperI);
  Serial.print("\tBumper Derecho: ");
  Serial.println(estadoBumperD);
  delay(1000);
}
```
- [**Sensor de ultrasonido**](https://www.luisllamas.es/medir-distancia-con-arduino-y-sensor-de-ultrasonidos-hc-sr04/), sensor que detecta los obstáculos a distancia. 

```cpp
/*
Test del sensor ultrasonido 

enero 2018 - Manuel Hidalgo / LeoBot
programa adaptado a EduBasica
fuente:https://www.luisllamas.es/medir-distancia-con-arduino-y-sensor-de-ultrasonidos-hc-sr04/

*/
//Declaracion de los pines 
const int EchoPin = 16;
const int TriggerPin = 17;

//Declaracion variables
int distancia;
 
void setup() {        //Configuracion de comunicaciones y pines
   Serial.begin(9600);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
}
 
void loop() {
   distancia = medida();
   Serial.print("Distancia: ");
   Serial.print(distancia);
   Serial.println(" cm");
   delay(1000);
}
 
int medida() {
   long duracion, distancaCm;
   
   digitalWrite(TriggerPin, LOW);  //inicio del pulso, ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);   //OFF del pulso
   
   duracion = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distancaCm = duracion * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distancaCm;
}
```
- [**Sensor IR CNY70**](http://www.practicasconarduino.com/manualrapido/sensor_de_infrarrojos_cny70.html), sensor de infrarrojos para detectar una línea negra sobre un fondo blanco. Se utiliza para hacer un robot seguidor de linea.

```cpp
/*
Test CNY70, sensor infrarrojos seguidor de linea, del robot 

enero 2018 - Manuel Hidalgo / LeoBot
programa adaptado a Robot con EduBasica
*/

//Declaracion de pines

#define cny70_D 17
#define cny70_I 16

//Declaracion de variables
int estadoCNY70_D;
int estadoCNY70_I;

void setup(){
  //Configuracion de comunicaciones y pines
  Serial.begin(9600);
  pinMode(cny70_D, INPUT);
  pinMode(cny70_I, INPUT);
  
 }
 

void loop() {

  estadoCNY70_D = digitalRead(cny70_D);
  estadoCNY70_I = digitalRead(cny70_I);
  //monitoriza el estado
  // 1 --> NEGRO
  // 1 --> BLANCO
  Serial.print("CNY70 Izquierdo: ");
  Serial.print(estadoCNY70_I);
  Serial.print("\tCNY70 Derecho: ");
  Serial.println(estadoCNY70_D);
  delay(1000);
}
```

Sabiendo el funcionamiento de los distintos objetos tecnológicos que hemos visto podemos programar un robot móvil seguidor de línea.

Su lógica de funcionamiento básico es la siguiente:
```cpp
REPETIR
  LEER CNY70_DER
  LEER CNY70_IZQ
  
  SI CNY70_DER --> NEGRO
     CNY70_IZQ --> NEGRO    ---> AVANZA
  
  SI CNY70_DER --> BLANCO
     CNY70_IZQ --> NEGRO    ---> GIRO IZQUIERDA
     
  SI CNY70_DER --> NEGRO
     CNY70_IZQ --> BLANCO   ---> GIRO DERECHA
     
  SI CNY70_DER --> BLANCO
     CNY70_IZQ --> BLANCO   ---> PARADO
 ```

Tu imaginación NO TIENE LÍMITE para programar robot.
