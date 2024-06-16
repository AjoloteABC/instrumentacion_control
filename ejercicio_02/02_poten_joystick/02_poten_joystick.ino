/*
  Dispositivo: joystick

  Entrada: digital y analógica
  Salida: puerto serie
*/

// Pin digital
int iPin_SW = 2;

// Pines analógicos
int iPin_VRx = A0;
int iPin_VRy = A1;

/*
  Tamaño del arreglo de caracteres
  que almacenará la cadena formateada,
  incluyendo el carácter nulo (\0) que
  marca el final de la cadena en C.
*/

char buffer[30];

void setup()
{
  // Inicialización del puerto serie
  Serial.begin(9600);

  // Pin digital como entrada
  pinMode(iPin_SW, INPUT);
}

void loop()
{
  // Cadena formateada y
  // lectura de entradas analógicas y digital
  sprintf(buffer, "(VRx: %d, VRy: %d) SW: %d", analogRead(iPin_VRx), analogRead(iPin_VRy), digitalRead(iPin_SW));
  Serial.println(buffer);

  delay(500);
}