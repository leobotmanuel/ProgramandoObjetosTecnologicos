/*
 * pulsando el pulsador el led rojo se enciende
 * diciembre 2017 - Manuel Hidalgo - LeoBot
 */

/***   Global variables   ***/

/***   Function declaration   ***/

void setup()
{
  pinMode(2,INPUT);
  pinMode(5,OUTPUT);
}

void loop()
{
    if (digitalRead(2) == 1) {
      digitalWrite(5,HIGH);
     }
    if (digitalRead(2) == 0) {
      digitalWrite(5,LOW);
     }
}

/***   Function definition   ***/
