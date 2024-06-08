/*
  Dispositivo: digital y analógico (joystick)
  Salida: puerto serie (estado digital y nivel de cuantificación)
*/

// Pin digital
int iPin_SW = 2;

// Pines analógicos
int iPin_VRx = A0;
int iPin_VRy = A1;

// Tamaño del arreglo de caracteres
// que almacenará la cadena formateada
char buffer[30];

void setup()
{
  // Inicializamos puerto serie
  Serial.begin(9600);

  // Pin digital como entrada
  pinMode(iPin_SW, INPUT);
}

void loop()
{
  // Cadena formateada y
  // lectura de entradad analógicas y digital
  sprintf(buffer, "(VRx: %d, VRy: %d) SW: %d", analogRead(iPin_VRx), analogRead(iPin_VRy), digitalRead(iPin_SW));
  Serial.println(buffer);

  delay(500);
}
