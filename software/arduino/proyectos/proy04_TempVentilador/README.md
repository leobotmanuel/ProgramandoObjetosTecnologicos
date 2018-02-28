# Control de temperatura con ventilador.

## Propuesta del proyecto
Control de temperatura con un ventilador, conectado a la **Salida de Potencia** (clema de conexión en la parte inferior izquierda) de la placa EduBasica y el sensor de temperatura **[LM35](https://www.luisllamas.es/medir-temperatura-con-arduino-y-sensor-lm35/)**.

## Objetos tecnológicos
- **Sensor de temperatura LM35**, se conecta en la entrada analógica A5.

Explicación de funcionamiento del [LM35](https://www.luisllamas.es/medir-temperatura-con-arduino-y-sensor-lm35/), web de Luis Llamas.

Los objetos tecnológicos de la placa EduBasica utilizados son:
- **Salida de potencia**

<a href="" target="_blank"><img width="547" height="258" border="0" align="center" src="https://github.com/leobotmanuel/ProgramandoObjetosTecnologicos/blob/master/software/arduino/proyectos/img/SalidaPotencia01.png"/></a>

## Explicación del código.
Para el correcto funcionamiento del control, la variable umbral hay que modificarla para que actúe correctamente y al sensor de temperatura dando calor, apretando con los dedos el sensor o fuente de calor con cuidado (acercando una bombilla al sensor de 40W o 60W).

```cpp
/*
Control temperatura con ventilador OFF-ON.

enero 2018 - Manuel Hidalgo / LeoBot
programa adaptado a EduBasica
*/
int Sensor = A5 ;             // Pin que lee la temperatura
int umbral = 15 ;            // Temparatura que arranca el ventilador
const int control = 6 ;      // Gobierna el ventilador

void setup()
   {   Serial.begin(9600);
       pinMode(control,  OUTPUT) ;
   }

void loop()
   {   int lectura = analogRead(Sensor);
       float voltaje = 5.0 /1024 * lectura ;    
       float temp = voltaje * 100 -5 ;
       Serial.println(temp) ;

       if (temp >= umbral)
           digitalWrite(control, HIGH);
       else
           digitalWrite(control, LOW);

       delay(200);
   }
```

## Código del proyecto
[Dercarga](https://github.com/leobotmanuel/ProgramandoObjetosTecnologicos/blob/master/software/arduino/proyectos/proy04_controlTempVentilador.zip)
