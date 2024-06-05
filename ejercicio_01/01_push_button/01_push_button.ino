// Dispositivo: digital (push button)

// Salida: puerto serie (presencia)

int iPinSensor = 2;

void setup()
{
  Serial.begin(9600);
  /*
     Inicializamos el puerto serie definiendo
     la velocidad de transmisión en baudios (bps).

     Entre los dispositivos que se realiza la 
     transmisión deben poseer el mismo baudaje;
     9600 es el estandar.

     'Serial' es un objeto y 'begin' es un método
     de la clase 'HardwareSerial'.
  */

  pinMode(iPinSensor, INPUT);
  // Pin digital como entrada
}

void loop()
{
  if (digitalRead(iPinSensor))
  { // Estado HIGH o LOW del pin digital

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
