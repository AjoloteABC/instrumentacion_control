#include <LiquidCrystal.h>

/*
  Dispositivo: ninguno

  Entrada: ninguna
  Salida: LCD 16x02
*/

// Pines del display
int RS = 2, EN = 3, D4 = 4, D5 = 5, D6 = 6, D7 = 7;

// Creación del objeto tipo LiquidCrystal
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup()
{
  // Inicialización del objeto tipo LiquidCrystal
  // definiendo las dimensiones del display
  lcd.begin(16, 2);

  // Ubicación del cursor en la columna 0 y fila 0
  lcd.setCursor(0, 0);
  lcd.print("Hola Mundo!");
}

void loop()
{
  // Ubicación del cursor en la columna 0 y fila 1
  lcd.setCursor(0, 1);
  lcd.print(String(millis() / 1000) + " segundos");

  /*
    La función 'millis' retorna el número de
    milisegundos desde que la placa Arduino
    comenzó a ejecutar el programa actual.
  */

  delay(1000);
}
