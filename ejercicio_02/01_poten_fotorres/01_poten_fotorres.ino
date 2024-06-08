/*
  Dispositivo: analógico (potenciómetro o fotorresistencia)
  Salida: puerto serie (nivel de cuantificación)
*/

// Pin analógico
int iPin_Sensor = A0;

// Tamaño del arreglo de caracteres
// que almacenará la cadena formateada
char buffer[20];

void setup()
{
  // Inicializamos puerto serie
  Serial.begin(9600);
}

void loop()
{
  // Cadena formateada y
  // lectura de entrada analógica
  sprintf(buffer, "LecturaADC: %d", analogRead(iPin_Sensor));
  Serial.println(buffer);

  delay(500);
}
