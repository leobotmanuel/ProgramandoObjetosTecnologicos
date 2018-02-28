# Control ON-OFF de los LEDs con la luminosidad

Este proyecto enciende los LEDs en función de la luminosidad del ambiente. Se ha establecido 4 niveles de 0 a 3.
- nivel 0 --> 3 LEDs OFF.
- nivel 1 --> 1 LED ON y 2 LEDs OFF.
- nivel 2 --> 2 LEDs ON y 1 LED OFF.
- nivel 3 --> 3 LEDs ON.

Los objetos tecnológicos de la placa EduBasica son:
- Los LEDs
<a href="" target="_blank"><img width="88" height="31" border="0" align="center" src="img/leds_cirEdubasica.png "/></a>

```cpp
/*
Proyecto de control ON-OFF de los LEDs con LDR 
enero 2018 - Manuel Hidalgo / LeoBot
programa de dominio publico
*/

//asignacion de etiquetas a los pines de los leds // labels for the pins LEDs are connected to
int ledG = 3; // pin Green LED 
int ledY = 4; // pin Yellow LED
int ledR = 5; // pin Red LED

// Etiquetas de identificacion de los pines // label for pins connections
const int inAnaLDR = A1;     // Entrada analogica sensor LDR // analog input for LDR

int valorSensorLDR = 0;     // Lectura del valor del sensor LDR // for reading sensor's value
int valorNivel = 0;         // Valor de nivel de LEDs ON

//Funcion de configuracion
void setup() {    
  // inizialización de comunicaciones monitor serie a 9600 bps: // init communications at 9600 bauds per second
  Serial.begin(9600);            

  pinMode(ledG, OUTPUT);     
  pinMode(ledY, OUTPUT);     
  pinMode(ledR, OUTPUT); 
  //inicialmente todos los leds apagados // all LEDs off at the beginning
  digitalWrite(ledG, LOW);
  digitalWrite(ledY, LOW);
  digitalWrite(ledR, LOW);
}

//Comienzo programa principal
void loop(){
  // lee el valor analogico del LDR, A1. // reading on analog 1 pin
  valorSensorLDR = analogRead(inAnaLDR);            

  //Determinacion de los niveles de control de LEDs
  if (valorSensorLDR < 625) {
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    valorNivel = 0;
  }
  if ((valorSensorLDR >= 625) && (valorSensorLDR < 725)) {
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, LOW);
    valorNivel = 1;
  }
  if ((valorSensorLDR >= 725) && (valorSensorLDR < 900)) {
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, LOW);
    valorNivel = 2;
  }
  if (valorSensorLDR >= 900) {
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, HIGH);
    valorNivel = 3;
  }
  

  //Escribe los resultados en el monitor serie. // Writing the values over serial monitor
  Serial.print("valor entrada LDR / input value = ");  
  Serial.print(valorSensorLDR);      
  Serial.print("\t Nivel de alumbrado = ");      
  Serial.println(valorNivel);   

  // Espera 10 milisegundos para que el conversor ADC haga la nueva lectura // waits 10 ms for the ADC makes a new reading
  delay(10);    
} //fin del programa principal
```
