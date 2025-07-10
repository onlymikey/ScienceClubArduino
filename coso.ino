#include <Servo.h>
#include <Wire.h> 
#include <pt.h>

// Declaracion de servomotores
Servo servoX, servoY, servoUltrasonido,servoUltrasonido2;

static struct pt pt1, pt2; 

// Pines del joystick
const int pinJoystickX = A2;
const int pinJoystickY = A3;

// Pines del LED RGB
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;


// Pines del sensor ultrasonico
const int trigPin = 13;
const int echoPin = 12;

// Umbral de distancia para activar el servomotor
const int distanciaUmbral = 10;

// Pines de los servomotores (CAMBIAR)
const int pinServoX = 6;
const int pinServoY = 6;
const int pinServoUltrasonido = 3;
const int pinServoUltrasonido2 = 3;


// Variables para suavizar el movimiento
int posicionX = 90;
int posicionY = 90;



void setup() {
  // Configuracion de los servomotores
  servoX.attach(pinServoX);
  servoY.attach(pinServoY);
  PT_INIT(&pt1);  // initialise the two
  PT_INIT(&pt2);  // protothread variables


  //configuraciones de servo de ultrasonido
  servoUltrasonido.attach(pinServoUltrasonido);
  servoUltrasonido2.attach(pinServoUltrasonido2);


  // Configuracion del sensor ultrasonico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);



  // Posicion inicial de los servos
  servoX.write(posicionX);
  servoY.write(posicionY);
  servoUltrasonido.write(90); // Posicion inicial del tercer servo
  servoUltrasonido2.write(90);
  Serial.begin(9600); 
  //Pines del Led
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
}

void loop() {
  
  moverServosConJoystick();
  activarServoConUltrasonido();
  RGBPines();
}

static int protothread1(struct pt *pt, int interval) {
  static unsigned long timestamp = 0;
  PT_BEGIN(pt);
  while(1) { // never stop 
    /* each time the function is called the second boolean
    *  argument "millis() - timestamp > interval" is re-evaluated
    *  and if false the function exits after that. */
    PT_WAIT_UNTIL(pt, millis() - timestamp > interval );
    timestamp = millis(); // take a new timestamp
    RGBPines();
  }
  PT_END(pt);
}
/* exactly the same as the protothread1 function */
static int protothread2(struct pt *pt, int interval) {
  static unsigned long timestamp = 0;
  PT_BEGIN(pt);
  while(1) {
    PT_WAIT_UNTIL(pt, millis() - timestamp > interval );
    timestamp = millis();
    RGBPines();
  }
  PT_END(pt);
}

// Funcion para mover los servos con el joystick
void moverServosConJoystick() {
  int lecturaX = analogRead(pinJoystickX);
  int lecturaY = analogRead(pinJoystickY);

  // Mapear las lecturas del joystick a angulos de 0 a 180
  int objetivoX = map(lecturaX, 0, 1023, 0, 180);
  int objetivoY = map(lecturaY, 0, 1023, 0, 180);

  // Suavizar el movimiento
  posicionX = posicionX + (objetivoX - posicionX) / 3;
  posicionY = posicionY + (objetivoY - posicionY) / 3;

  // Mover los servos
  servoX.write(posicionX);
  servoY.write(posicionY);

  delay(10); // Pequeno retraso para suavizar
}

// Funcion para activar un servo con el sensor ultrasonico
void activarServoConUltrasonido() {
  long duracion = medirDistancia();
  int distancia = duracion * 0.034 / 2; // Convertir a cm

  if (distancia > 0 && distancia <= distanciaUmbral) {
    servoUltrasonido.write(0); // Activar el servo
    servoUltrasonido2.write(0);
  
  } else {
    servoUltrasonido.write(90); // Posicion inicial
    servoUltrasonido2.write(90);
  }

  delay(50); // Pequeno retraso para evitar lecturas erraticas
}

// Funcion para medir la distancia con el sensor ultrasonico
long medirDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  return pulseIn(echoPin, HIGH);
}


void hsvToRgb(float h, float s, float v, int &r, int &g, int &b) {
  float c = v * s;
  float x = c * (1 - abs(fmod(h / 60.0, 2) - 1));
  float m = v - c;
  float r1, g1, b1;

  if (h < 60)      { r1 = c; g1 = x; b1 = 0; }
  else if (h < 120){ r1 = x; g1 = c; b1 = 0; }
  else if (h < 180){ r1 = 0; g1 = c; b1 = x; }
  else if (h < 240){ r1 = 0; g1 = x; b1 = c; }
  else if (h < 300){ r1 = x; g1 = 0; b1 = c; }
  else             { r1 = c; g1 = 0; b1 = x; }

  r = (r1 + m) * 255;
  g = (g1 + m) * 255;
  b = (b1 + m) * 255;
}



void RGBPines() {
  delay(500);
  int colorRand=random(0,1023);
  float hue = map(colorRand, 0, 1023, 0, 360); // Hue entre 0° y 360°
  int r, g, b;
  hsvToRgb(hue, 1.0, 1.0, r, g, b); // Saturación y brillo al 100%
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);
  }