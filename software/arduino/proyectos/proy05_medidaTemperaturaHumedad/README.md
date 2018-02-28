# Medida-Visualización de temperatura y humedad .

## Propuesta del proyecto
Medida-Visualización de temperatura y humedad con el sensor **DH11**.

## Objetos tecnológicos
- **Sensor de temperatura y humedad DH11**, se conecta en el pin digital D7 de la placa EduBasica.

Explicación de funcionamiento del [DH11](https://edubasica.github.io/manual/medida_de_la_temperatura_y_la_humedad_ambiente.html).

## Explicación del código.

```cpp
/*
Test del sensor DHT11, mide temperatura y humeda.
libreria utilizada
https://drive.google.com/file/d/0B2B9eCp8wRQhdTQwY196cHFfckk/view?usp=sharing 

enero 2018 - Manuel Hidalgo / LeoBot
programa adaptado a EduBasica
fuente:http://www.practicasconarduino.com/manualrapido/medida_de_la_temperatura_y_la_humedad_ambiente.html
*/
#include "DHT.h"
#define DHTPIN 7  
#define DHTTYPE DHT11   // DHT 11 
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600); 
  dht.begin();
}

void loop() {

  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Fallo al leer el sensor DHT11");
    return;
  }
  //Si se utiliza para monitorizar con Processing 
  //se quitan las lineas de mensajes, menos la coma (se ponen barras de comentarios) 
  // Únicamente enviar a Processing las variables t y h 
  Serial.print("Humedad (%): ");
  Serial.print(h);
  Serial.print(",");
  Serial.print("\tTemperatura (ºC): ");
  Serial.println(t);
}
*/
```

## Código del proyecto
[Dercarga](https://github.com/leobotmanuel/ProgramandoObjetosTecnologicos/blob/master/software/arduino/proyectos/proy05_medidaTemperaturaHumedad.zip)
