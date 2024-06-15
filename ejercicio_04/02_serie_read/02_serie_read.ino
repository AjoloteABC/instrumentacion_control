/*
  Dispositivo: ninguno

  Entrada: ninguna
  Salida: puerto serie
*/

// Lectura del puerto serie
String sCadena;

void setup()
{
  // Inicialización del puerto serie
  Serial.begin(9600);
}

void loop()
{
  // Obtiene el número de bytes (caracteres)
  // disponibles para leer del puerto serie
  if (Serial.available() > 0)
  {
    sCadena = "";

    // Utiliza un bucle para leer todos los
    // caracteres disponibles del puerto serie
    while (Serial.available() > 0)
    {
      // y construir una cadena completa
      sCadena = sCadena + char(Serial.read());
      delay(10);
    }
    Serial.println("Cadena: " + sCadena);
  }
}
