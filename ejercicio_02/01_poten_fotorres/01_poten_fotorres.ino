/*
  Dispositivo: potenciómetro o fotorresistencia

  Entrada: analógica
  Salida: puerto serie
*/

// Pin analógico
int iPin_Sensor = A0;

/*
  Tamaño del arreglo de caracteres
  que almacenará la cadena formateada,
  incluyendo el carácter nulo (\0) que
  marca el final de la cadena en C.
*/

char buffer[20];

void setup()
{
  // Inicialización del puerto serie
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