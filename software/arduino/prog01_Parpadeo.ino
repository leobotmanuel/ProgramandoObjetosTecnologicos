/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
  Programa de los ejemplos del IDE Arduino adaptado a EduBasica
  diciembre 2017 - Manuel Hidalgo - LeoBot
  programa de dominio publico
 */

// the setup function runs once when you press reset or power the board
// La funcion setup ejecuta una sola vez cuando presionas reset o alimentas la palca.
void setup() {
  // initialize digital pin 3 as an output.
  pinMode(3, OUTPUT);
}

// the loop function runs over and over again forever
// La funcion loop se ejecuta ciclicamente, si la placa esta alimentada.
void loop() {
  digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
