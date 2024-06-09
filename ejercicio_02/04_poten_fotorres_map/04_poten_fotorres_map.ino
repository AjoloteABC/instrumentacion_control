/*
  Dispositivo: analógico (potenciómetro o fotorresistencia)
  Salida: puerto serie (ángulo y porcentaje)
*/

// Pin analógico
int iPin_Sensor = A0;

// Lectura ADC (Analog-to-Digital Converter)
int iLecADC_Sensor;

// Valores mapeados
int iMap_Grados;
int iMap_Porcentaje;

// Tamaño del arreglo de caracteres
// que almacenará la cadena formateada
char buffer[30];

void setup()
{
  // Inicialización del puerto serie
  Serial.begin(9600);
}

void loop()
{
  // Lectura de entrada analógica
  iLecADC_Sensor = analogRead(iPin_Sensor);

  // Mapeo de los niveles de cuantificación
  // map(var_entrada, entrada_min, entrada_max, salida_min, salida_max);
  
  iMap_Grados = map(iLecADC_Sensor, 0, 1023, 0, 270);
  iMap_Porcentaje = map(iLecADC_Sensor, 0, 1023, 0, 100);

  // Cadena formateada
  sprintf(buffer, "Grados: %d° Porcentaje: %d%%", iMap_Grados, iMap_Porcentaje);
  Serial.println(buffer);

  delay(500);
}
