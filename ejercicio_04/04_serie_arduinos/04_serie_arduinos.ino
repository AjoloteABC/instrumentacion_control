#include <SoftwareSerial.h>

/*
  Dispositivo: arduino

  Entrada: puertos serie
  Salida: puertos serie
*/

// Lectura de los puertos serie
String sCadena;

// Nombre del usuario
String sUsuario = "Angel: ";

// Emulación del puerto serie (Rx, Tx)
SoftwareSerial miSerial(2, 3);

void setup()
{
  // Inicialización del puerto serie
  // Computadora - Arduino
  Serial.begin(9600);

  // Método que vacía el contenido
  // del buffer del puerto serie
  Serial.flush();

  // Inicialización del puerto serie emulado
  // Arduino - Arduino
  miSerial.begin(9600);

  // Método que vacía el contenido
  // del buffer del puerto serie emulado
  miSerial.flush();

  Serial.println("Bienvenido al chat");
}

void loop()
{
  // Obtiene el número de bytes (caracteres)
  // disponibles para leer del puerto serie
  if (Serial.available() > 0)
  {
    enviar();
  }

  // Obtiene el número de bytes (caracteres)
  // disponibles para leer del puerto serie emulado
  if (miSerial.available() > 0)
  {
    recibir();
  }
}

void enviar()
{
  sCadena = "";

  // Utiliza un bucle para leer todos los
  // caracteres disponibles del puerto serie
  while (Serial.available())
  {
    // y construir una cadena completa
    sCadena = sCadena + char(Serial.read());
    delay(10);
  }
  Serial.println(sUsuario + sCadena);
  miSerial.println(sUsuario + sCadena);
}

void recibir()
{
  sCadena = "";

  // Utiliza un bucle para leer todos los
  // caracteres disponibles del puerto serie emulado
  while (miSerial.available())
  {
    // y construir una cadena completa
    sCadena = sCadena + char(miSerial.read());
    delay(10);
  }
  Serial.println(sCadena);
}
