/*
  Dispositivo: potenciómetro o fotorresistencia

  Entrada: analógica
  Salida: puerto serie
*/

// Pin analógico
int iPin_Sensor = A0;

// Lectura ADC (Analog-to-Digital Converter)
int iLecADC_Sensor;

// Valores calculados por R3
float iR3_Grados;
float iR3_Porcentaje;

/*
  Tamaño del arreglo de caracteres
  que almacenará la cadena formateada,
  incluyendo el carácter nulo (\0) que
  marca el final de la cadena en C.
*/

char buffer[40];


// Tamaño de los arreglos de caracteres
// que almacenarán los valores casteados
char sGrados[10];
char sPorcentaje[10];

void setup()
{
  // Inicialización del puerto serie
  Serial.begin(9600);
}

void loop()
{
  // Lectura de entrada analógica
  iLecADC_Sensor = analogRead(iPin_Sensor);

  // iLecADC_SensorMax -> iR3_SensorMax
  // iLecADC_Sensor    -> iR3_Sensor

  iR3_Grados = iLecADC_Sensor * 270.0 / 1023.0;
  iR3_Porcentaje = iLecADC_Sensor * 100.0 / 1023.0;

  // Conversión de un valor flotante a una cadena
  // dtostrf(float_entrada, no_char, no_deci, string_salida);

  dtostrf(iR3_Grados, 6, 2, sGrados);
  dtostrf(iR3_Porcentaje, 6, 2, sPorcentaje);

  // Cadena formateada
  sprintf(buffer, "Grados: %s° Porcentaje: %s%%", sGrados, sPorcentaje);
  Serial.println(buffer);

  delay(500);
}