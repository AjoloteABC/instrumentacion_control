/*
  Dispositivo: digital (radar ultrasónico)
  Salida: puerto serie (distancia en centímetros)
*/

// Pines digitales
int iPin_Echo = 2;
int iPin_Trigger = 3;

// Variables de apoyo para
// calcular la distancia
int iTiempo;
int iDistancia;
float fVelocidad = 0.03432;

// Tamaño del arreglo de caracteres
// que almacenará la cadena formateada
char buffer[20];

void setup()
{
  // Pin digital como entrada
  pinMode(iPin_Echo, INPUT);

  // Pin digital como salida
  pinMode(iPin_Trigger, OUTPUT);

  // Inicialización del puerto serie
  Serial.begin(9600);
}

void loop()
{
  // Apagado del trigger que
  // asegura un nivel bajo al iniciar
  digitalWrite(iPin_Trigger, LOW);
  delayMicroseconds(5);

  // Encendido del trigger
  digitalWrite(iPin_Trigger, HIGH);
  delayMicroseconds(10);

  // Apagado del trigger
  digitalWrite(iPin_Trigger, LOW);

  // Medición del tiempo de echo 
  // en detectar un valor alto
  iTiempo = pulseIn(iPin_Echo, HIGH);

  /*
    La función 'pulseIn' devuelve la longitud 
    del pulso en microsegundos (ida y vuelta).

    La velocidad del sonido en el aire 
    (a una temperatura de 20°C) es de 343.2 m/s.

    Si deseamos calcular la distancia en cm,
    debemos obtener la equivalencia en cm/µs 
    respecto a la velocidad del sonido:

    (343.2m/s)(100cm / 1m)(1s / 10e+6µs) = 0.03432cm/µs

    Además, no hay que olvidar dividir el tiempo
    a la mitad. Por lo tanto:
  */
  
  iDistancia = (iTiempo / 2.0) * fVelocidad;

  // Cadena formateada
  sprintf(buffer, "Distancia: %dcm", iDistancia);
  Serial.println(buffer);

  delay(100);
}
