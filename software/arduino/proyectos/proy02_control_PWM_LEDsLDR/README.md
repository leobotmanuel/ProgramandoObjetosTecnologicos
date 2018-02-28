# Control PWM de los LEDs con la luminosidad

## Propuesta del proyecto
Este proyecto enciende los LEDs en función de la luminosidad del ambiente. Se ha establecido 4 niveles de 0 a 3.
- nivel 0 --> 3 LEDs OFF.
- nivel 1 --> 1 LED ON y 2 LEDs OFF.
- nivel 2 --> 2 LEDs ON y 1 LED OFF.
- nivel 3 --> 3 LEDs ON.

## Objetos tecnológicos
Los objetos tecnológicos de la placa EduBasica utilizados son:
- Los LEDs

<a href="" target="_blank"><img width="366" height="278" border="0" align="center" src="https://github.com/leobotmanuel/ProgramandoObjetosTecnologicos/blob/master/software/arduino/proyectos/img/leds_cirEdubasica.png"/></a>

- El sensor LDR

<a href="" target="_blank"><img width="109" height="274" border="0" align="center" src="https://github.com/leobotmanuel/ProgramandoObjetosTecnologicos/blob/master/software/arduino/proyectos/img/LDR_esqEdubasica.png"/></a>

## Explicación del código.
```cpp
/*
Proyecto de control PWM de los LEDs con LDR 

enero 2018 - Manuel Hidalgo / LeoBot
programa de dominio publico
*/

//asignacion de etiquetas a los pines de los leds a
const int outAnaLedV = 3; // Salida analogica (PWM) al led verde
const int outAnaLedR = 5; // Salida analogica (PWM) al led rojo

// Etiquetas de identificacion de los pines
const int inAnaLDR = A1;     // Entrada analogica sensor LDR

int valorSensorLDR = 0;      // Lectura del valor del sensor LDR
int valorPWM = 0;            // Valor de salida PWM (salida analogica) a los pines LEDs


//Funcion de configuracion
void setup() {    
  // inizialización de comunicaciones monitor serie a 9600 bps
  Serial.begin(9600);            

  analogWrite(outAnaLedV, valorPWM);
  analogWrite(outAnaLedR, valorPWM);
}

//Comienzo programa principal
void loop(){
  // lee el valor analogico del LDR, A1
  valorSensorLDR = analogRead(inAnaLDR);            
  // mapea el rango de los valores de lectura del LDR, que pueden ser diferentes
  //por la luz recibida (los 2 primeros datos se deben de cambiar)
  valorPWM = map(valorSensorLDR, 600, 1015, 0, 255);  
  

  // salida analogica PWM
  analogWrite(outAnaLedV, valorPWM);
  analogWrite(outAnaLedR, valorPWM);  

/*
 //Solucion alternativa para evitar el encendido de los LEDs si valorSensorLDR < 600
 if (valorSensorLDR < 600) {
  analogWrite(outAnaLedV,  0);
  analogWrite(outAnaLedR, 0);
 }
 else if (valorSensorLDR > 1015) {
  analogWrite(outAnaLedV, 255);
  analogWrite(outAnaLedR, 255);
 }
 else{
  analogWrite(outAnaLedV, valorPWM);
  analogWrite(outAnaLedR, valorPWM);
 }
*/
  //Escribe los resultados en el monitor serie
  Serial.print("valor entrada LDR = ");  
  Serial.print(valorSensorLDR);      
  Serial.print("\t Intensidad luminosa de los LEDs = ");      
  Serial.println(valorPWM);   

  // Espera 10 milisegundos para que el conversor ADC haga la nueva lectura // waits 10 ms for the ADC makes a new reading
  delay(10);    
} //fin del programa principal
```
