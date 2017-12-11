/*
 * lee el valor del potenciometro conectado a A0 y
 * genera la señal PWM en el pin D5 (LED ROJO)
 * produciendo fading
 * diciembre 2017 - Manuel Hidalgo - LeoBot
 */
/***   Global variables   ***/
int valorPot=0;
int valorPWM=0;

/***   Function declaration   ***/

void setup()
{
  Serial.begin(9600);
  pinMode(5,OUTPUT);
}

void loop()
{
    valorPot=analogRead(A0);
    Serial.print("Valor leido del potenciometro: ");
    Serial.print(valorPot);
    valorPWM=map(valorPot,0,1023,0,255);
    analogWrite(5,valorPWM);
    Serial.print("  Escribe en el LED ROJO el valor PWM: ");
    Serial.println(valorPWM);
    delay(10);
}

/***   Function definition   ***/
