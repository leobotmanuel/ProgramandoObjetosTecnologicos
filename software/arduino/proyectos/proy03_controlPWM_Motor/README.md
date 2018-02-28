# Control de velocidad (control PWM) de un motor de corriente continua.

## Propuesta del proyecto
Control de velocidad (control PWM) de un motor dc, conectado a la **Salida de Potencia** (clema de conexión en la parte inferior izquierda) y el **potenciómetro** de la placa EduBasica.

## Objetos tecnológicos
Los objetos tecnológicos de la placa EduBasica utilizados son:
- Potenciómetro.

<a href="" target="_blank"><img width="130" height="275" border="0" align="center" src="https://github.com/leobotmanuel/ProgramandoObjetosTecnologicos/blob/master/software/arduino/proyectos/img/potenciometro_cirEdubasica01.png"/></a>

- Salida de potencia

<a href="" target="_blank"><img width="547" height="258" border="0" align="center" src="https://github.com/leobotmanuel/ProgramandoObjetosTecnologicos/blob/master/software/arduino/proyectos/img/SalidaPotencia01.png"/></a>

## Explicación del código.

```cpp
/*
Proyecto de control PWM de motor dc con potenciometro 

enero 2018 - Manuel Hidalgo / LeoBot
programa de dominio publico
*/

// Etiquetas de identificacion de los pines
const int inAnaPot = A0;     // Entrada analogica potenciometro
const int outControl = 6;    // Salida analogica PWM al motor dc

//Declaracion de variables
int valorSensorPot = 0;      // Lectura del valor del potenciometro
int valorPWM = 0;            // Valor de salida PWM (salida analogica) al motor dc

//Funcion de configuracion
void setup() {    
  Serial.begin(9600);       // inizialización de comunicaciones monitor serie a 9600 bps

  analogWrite(outControl, valorPWM); //motor dc OFF
}

//Comienzo programa principal
void loop(){
  valorSensorPot = analogRead(inAnaPot);  // lee el valor analogico del potenciometro, A0
  valorPWM = map(valorSensorPot, 0, 1023, 0, 255); // mapea el rango de los valores de 10 bits a 8 bits 
  
  // salida analogica PWM al motor dc
  analogWrite(outControl, valorPWM);

  //Escribe los resultados en el monitor serie
  Serial.print("valor entrada Pot = ");  
  Serial.print(valorSensorPot);      
  Serial.print("\t Valor PWM de control = ");      
  Serial.println(valorPWM);
  // Espera 10 milisegundos para que el conversor ADC haga la nueva lectura
  delay(10);    
} //fin del programa principal
```

## Código del proyecto
[Dercarga](https://github.com/leobotmanuel/ProgramandoObjetosTecnologicos/blob/master/software/arduino/proyectos/proy03_controlPWM_Motor.zip)
