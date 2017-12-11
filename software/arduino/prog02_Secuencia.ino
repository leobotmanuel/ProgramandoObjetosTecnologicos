/*
 * programa de secuencia de los leds
 * diciembre 2017 - Manuel Hidalgo - LeoBot
 */

/***   Global variables   ***/
int retardo=1000;

/***   Function declaration   ***/

void setup()
{
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop()
{
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    delay(retardo);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    delay(retardo);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    delay(retardo);
}


