/*
 * señal pwm (variacion analógica) sobre el led rojo 
 * haciendo fading
 * diciembre 2017 - Manuel Hidalgo - LeoBot
 */

/***   Global variables   ***/
int pinLED3=3;
int i=0;

/***   Function declaration   ***/

void setup()
{
  pinMode(i,OUTPUT);
  digitalWrite(i,LOW);
}

void loop()
{
    for (i = 0; i <= 255; i++) {
      pinMode(pinLED3,OUTPUT);
      analogWrite(pinLED3,i);
      delay(10);
    }
    delay(1000);
    for (i = 255; i >= 0; i--) {
      pinMode(pinLED3,OUTPUT);
      analogWrite(pinLED3,i);
      delay(10);
    }
    delay(1000);
} /*fin del programa*/

/***   Function definition   ***/
