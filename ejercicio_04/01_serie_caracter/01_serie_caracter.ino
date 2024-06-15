/*
  Dispositivo: LED

  Entrada: ninguna
  Salida: digital y puerto serie
*/

// Pin digital
int iPin_LED = 2;

// Lectura del puerto serie
char cCaracter;

void setup()
{
  // Inicialización del puerto serie
  Serial.begin(9600);

  // Pin digital como salida
  pinMode(iPin_LED, OUTPUT);
}

void loop()
{
  // Obtiene el número de bytes (caracteres)
  // disponibles para leer del puerto serie
  if (Serial.available() > 0)
  {
    // Retorna el primer byte de datos seriales
    // entrantes disponibles (-1 si no hay)
    cCaracter = Serial.read();

    /*
      Cuando enviamos una cadena a través del monitor serie, también
      se envía un retorno de carro (\r). Este último indica al receptor
      dónde acaba la cadena, y todo lo que siga después no interesa.

      El Arduino detecta el retorno de carro como un carácter. Por lo
      tanto, hay que configurar el monitor serie como 'no line ending'.
    */

    // Define el encendido o apagado de un LED
    // dependiendo de la entrada por monitor serie
    switch (cCaracter)
    {
      case '1':
        digitalWrite(iPin_LED, HIGH);
        Serial.println("LED Encendido");
        break;

      case '0':
        digitalWrite(iPin_LED, LOW);
        Serial.println("LED Apagado");
        break;

      default:
        Serial.println("Desconocido...");
        break;
    }
  }
}
