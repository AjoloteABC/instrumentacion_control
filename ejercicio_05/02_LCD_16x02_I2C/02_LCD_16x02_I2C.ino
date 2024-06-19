#include <LiquidCrystal_I2C.h>

/*
  Dispositivo: ninguno

  Entrada: ninguna
  Salida: LCD 16x02 I2C
*/

// Creación del objeto tipo LiquidCrystal_I2C
// definiendo la dirección I2C y las dimensiones del display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  // Inicialización del objeto tipo LiquidCrystal_I2C
  lcd.init();

  // Encendido de la luz de fondo del display
  lcd.backlight();

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
