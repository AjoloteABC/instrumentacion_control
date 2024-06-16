/*
  Dispositivo: push button

  Entrada: digital
  Salida: puerto serie
*/

// Pin digital
int iPin_PushButton = 2;

void setup()
{
  Serial.begin(9600);

  /*
     Inicialización del puerto serie definiendo
     la velocidad de transmisión en baudios (bps).

     Entre los dispositivos que se realiza la
     transmisión deben poseer el mismo baudaje;
     9600 es el estándar.

     'Serial' es un objeto y 'begin' es un método
     de la clase 'HardwareSerial'.
  */

  // Pin digital como entrada
  pinMode(iPin_PushButton, INPUT);
}

void loop()
{
  // Lectura de entrada digital
  if (digitalRead(iPin_PushButton))
  {
    Serial.println("Objeto posicionado");
  }
  else
  {
    Serial.println("No hay objeto...");
  }
  delay(1000);

  /*
     Importancia de la función 'delay':

     1. Evita la saturación del puerto serie
     2. Facilita el desarrollo y depuración
     3. Reduce el consumo de energía
     4. Evita el debouncing
     5. Sincronización y control de flujo
  */
}
