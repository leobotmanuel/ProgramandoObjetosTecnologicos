/*
 * lee el valor del sensor LDR conectado a A1 y
 * lo escribe en el monitor serie
 * diciembre 2017 - Manuel Hidalgo - LeoBot
 */
 
/***   Global variables   ***/
int valorLDR=0;

/***   Function declaration   ***/

void setup()
{
  Serial.begin(9600);
}


void loop()
{
    valorLDR=analogRead(A1);
    Serial.print("Valor leido del sensor LDR: ");
    Serial.println(valorLDR);
    delay(2000);
}

/***   Function definition   ***/
