/*
  Dispositivo: radar ultrasónico

  Entrada: digital
  Salida: digital y puerto serie
*/

// Pines digitales
int iPin_Echo = 2;
int iPin_Trigger = 3;

// Cálculo de distancia
int iTiempo;
float fDistancia;
float fVelocidad = 0.03432;

/*
  Tamaño del arreglo de caracteres
  que almacenará la cadena formateada,
  incluyendo el carácter nulo (\0) que
  marca el final de la cadena en C.
*/

char buffer[20];

// Tamaño del arreglo de caracteres
// que almacenará el valor casteado
char sDistancia[10];

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
  /*
     Estabilización: asegura que el 'trigger' esté
     completamente en estado bajo antes de iniciar
     un nuevo pulso, limpiando cualquier señal
     residual.
  */

  digitalWrite(iPin_Trigger, LOW);
  delayMicroseconds(5);

  /*
     Generación del puso: garantiza que el 'trigger'
     esté en estado alto el tiempo suficiente, al
     menos 10 µs, para generar un pulso eléctrico.
  */

  digitalWrite(iPin_Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(iPin_Trigger, LOW);

  /*
     Medición del tiempo de 'echo'
     en detectar un valor alto.

     Agregar un delay antes de llamar a 'pulseIn' no
     mejora la precisión y de hecho podría retrasar
     el inicio de la medición del 'echo'.
  */

  iTiempo = pulseIn(iPin_Echo, HIGH);

  /*
    La función 'pulseIn' devuelve la longitud
    del pulso en microsegundos (ida y vuelta).

    La velocidad del sonido en el aire
    (a una temperatura de 20°C) es de 343.2 m/s.

    Si deseamos calcular la distancia en cm,
    debemos obtener la equivalencia en cm/µs
    respecto a la velocidad del sonido:

    (343.2m/s)(100cm / 1m)(1s / 1e+6µs) = 0.03432cm/µs

    Además, no hay que olvidar dividir el tiempo
    a la mitad. Por lo tanto:
  */

  fDistancia = (iTiempo / 2.0) * fVelocidad;

  // Conversión de un valor flotante a una cadena
  // dtostrf(float_entrada, no_char, no_deci, string_salida);
  dtostrf(fDistancia, 6, 2, sDistancia);

  // Cadena formateada
  sprintf(buffer, "Distancia: %scm", sDistancia);
  Serial.println(buffer);

  delay(100);
}