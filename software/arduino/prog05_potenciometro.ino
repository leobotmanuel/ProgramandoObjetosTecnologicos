/*
 * lee el valor del potenciometro conectado a A0 y
 * lo escribe en el monitor serie
 * diciembre 2017 - Manuel Hidalgo - LeoBot
 */
/***   Global variables   ***/
int valorPot=0;

/***   Function declaration   ***/

void setup()
{



  Serial.begin(9600);

}


void loop()
{
    valorPot=analogRead(A0);
    Serial.println(valorPot);

}

/***   Function definition   ***/
