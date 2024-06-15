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
  if (Serial.available())
  {
    // Lee todos los caracteres disponibles
    // del puerto serie en una cadena
    sCadena = Serial.readString();

    // Permite que el Arduino tenga tiempo suficiente para
    // recibir y procesar los datos entrantes correctamente
    delay(10);

    /*
      La función 'readString' intenta almacenar toda la cadena en el
      buffer de memoria del Arduino de una vez. Esto puede llevar a un
      desbordamiento de memoria cuando la cadena es demasiado larga
      para el espacio disponible en el buffer.

      Cuando la memoria se desborda, el Arduino empieza a usar más
      direcciones de memoria para manejar la operación, lo cual puede
      resultar en errores o un comportamiento inesperado del programa.

      Es importante gestionar adecuadamente la longitud y la velocidad
      de recepción de las cadenas para evitar saturar el buffer de
      memoria interna.
    */

    Serial.println(sCadena);
  }
}
