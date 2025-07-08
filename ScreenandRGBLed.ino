

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>





/* Create object named lcd of the class LiquidCrystal */
const int potenciometro1 = A0;
const int POT_PIN2 = A1;
const float Voltajearduino = 5.0;

// Pines del LED RGB
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

// Función para convertir HSV a RGB
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

LiquidCrystal_I2C lcd(0x27,16,2);  //


void setup(){
  lcd.init();
   Serial.begin(9600); 
  //Encender la luz de fondo.
  lcd.backlight();
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(POT_PIN2, INPUT);
  lcd.setCursor(0, 1);
 lcd.println ("Hola walter");                               
}

void loop(){
  int potValue = analogRead(POT_PIN2); // 0 - 1023
float Voltaje =(potValue * Voltajearduino)/1023;   
 float hue = map(potValue, 0, 1023, 0, 360); // Hue entre 0° y 360°
 int r, g, b;
  hsvToRgb(hue, 1.0, 1.0, r, g, b); // Saturación y brillo al 100%
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);

  delay(10); // Suaviza un poco el cambio
  lcd.setCursor(1, 0);
 lcd.println ("voltaje");                /* Set cursor to column 0 row 0 */
  lcd.print(Voltaje,2);  
Serial.print(Voltaje);           /* Print data on display */ 
delay(100);


}

