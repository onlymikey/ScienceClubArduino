#include <LiquidCrystal_I2C.h>

// --- CONFIGURACIÓN DE HARDWARE ---
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int PIN_BOTON = 2;
const int PIN_BUZZER = 5;

// --- VARIABLES DE ESTADO ---
int cancionActual = 0;
const int NUM_CANCIONES = 4;

// --- DEFINICIONES DE NOTAS (LISTA COMPLETA Y CORREGIDA) ---
#define Sil 0
#define C_  131
#define Cs_ 139
#define D_  147
#define Ds_ 156 // <- Añadida
#define E_  165
#define F_  175
#define Fs_ 185
#define G_  196
#define Gs_ 208
#define A_  220
#define As_ 233 // <- Añadida
#define B_  247
#define C   261
#define Cs  277
#define D   294
#define Ds  311 // <- Añadida
#define E   330
#define Fa  349
#define Fas 369
#define G   392
#define Gs  415
#define A   440
#define As  466
#define B   493
#define C2  523
#define Cs2 554
#define D2  587
#define Ds2 623 // <- Añadida
#define E2  659
#define Fa2 698
#define Fas2 740
#define G2  784
#define Gs2 831 // <- Añadida
#define A2  880
#define As2 932
#define B2  988
#define C3  1047
#define Cs3 1109
#define D3  1175

// Caracter custom
byte laDuda[8] = { B00000, B00100, B00000, B00100, B01000, B10000, B10001, B01110 };

void textopan(String S1, String S2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(S1);
  lcd.setCursor(0, 1);
  lcd.print(S2);
}

// ==========================================================
// --- SECCIÓN CANCIÓN 2: "La Gata Bajo la Lluvia" ---
// ==========================================================
int tempo2 = 68 * 2;
int n2 = 60000 / tempo2; int b2 = n2 * 2; int r2 = b2 * 2; int c2 = n2 / 2; int s2 = c2 / 2; int np2 = c2 * 3 / 2; int cp2 = c2 + s2;

void nota_C2_normal(int freq, int dur) { freq = freq * 0.89089871814; if (freq > 0) tone(PIN_BUZZER, freq); delay(dur); noTone(PIN_BUZZER); delay(dur * 0.3); }
void nota_C2_directa(int freq, int dur) { if (freq > 0) tone(PIN_BUZZER, freq); delay(dur); noTone(PIN_BUZZER); delay(dur * 0.5); }
void nota_trem_C2(int Na, int Nb, int f, int nr) { int tt = f / (2 * nr); for (int i = 1; i <= nr; i++) { if (Na > 0) tone(PIN_BUZZER, Na); delay(tt); noTone(PIN_BUZZER); if (Nb > 0) tone(PIN_BUZZER, Nb); delay(tt); noTone(PIN_BUZZER); } }

void reproducirCancion1() {
  textopan("Cancion 1:", "La Gata...");
  delay(2000);
  textopan("La Gata Bajo la", "Lluvia          ");
  nota_trem_C2(B2, G2, np2, 8); nota_C2_directa(A2, s2); nota_C2_directa(B2, s2); nota_trem_C2(A2, Fas2, np2, 8); nota_C2_directa(G2, s2); nota_C2_directa(A2, s2); nota_trem_C2(G2, E2, np2, 8); nota_C2_directa(Fas2, s2); nota_C2_directa(G2, s2); nota_C2_directa(Fas2, cp2); nota_C2_directa(E2, cp2); nota_C2_directa(D2, c2); nota_trem_C2(E2, C2, n2 + c2 + b2, 20); nota_C2_directa(E2, s2); nota_C2_directa(Fas2, s2); nota_C2_directa(G2, cp2); nota_C2_directa(Fas2, cp2); nota_C2_directa(G2, c2); nota_C2_directa(A2, cp2); nota_C2_directa(G2, cp2); nota_C2_directa(A2, c2); nota_trem_C2(B2, G2, r2, 22); nota_C2_directa(Sil, c2); nota_C2_directa(B / 2, c2); nota_C2_directa(D2 / 2, c2); nota_C2_directa(G2 / 2, n2); nota_C2_directa(B / 2, c2); nota_C2_directa(D2 / 2, c2);
  textopan("Amor...         ", "                "); nota_C2_normal(E, c2); nota_C2_normal(B, np2 + c2 + np2);
  textopan("Tranquilo no te ", "voy a molestar  "); nota_C2_normal(E, c2); nota_C2_normal(B, s2 + c2); nota_C2_normal(A, s2 + c2); nota_C2_normal(B, s2); nota_C2_normal(A, s2); nota_C2_normal(B, s2 + c2); nota_C2_normal(A, s2 + c2); nota_C2_normal(E, s2); nota_C2_normal(Cs, s2); nota_C2_normal(Gs, np2 + c2 + np2);
  textopan("Mi suerte       ", "estaba echada   "); nota_C2_normal(Cs, c2); nota_C2_normal(Gs, s2 + c2); nota_C2_normal(Fas, s2 + c2); nota_C2_normal(Gs, s2); nota_C2_normal(Fas, s2); nota_C2_normal(Gs, s2 + c2); nota_C2_normal(Fas, s2 + c2);
  textopan("Ya lo se        ", "             :'("); nota_C2_normal(Cs, s2); nota_C2_normal(A_, s2); nota_C2_normal(E, b2 + np2);
  textopan("Y se que hay un ", "torrente     :'("); nota_C2_normal(E, s2); nota_C2_normal(E, s2 + c2); nota_C2_normal(D, c2); nota_C2_normal(Cs, c2); nota_C2_normal(D, s2); nota_C2_normal(Cs, c2 + s2); nota_C2_normal(D, c2);
  textopan("dando vueltas   ", "por tu mente    "); nota_C2_normal(Fas, c2); nota_C2_normal(A, s2); nota_C2_normal(Cs2, c2 + s2); nota_C2_normal(B, c2); nota_C2_normal(Cs2, c2); nota_C2_normal(B, s2); nota_C2_normal(Cs2, c2 + s2); nota_C2_normal(B, c2);
  textopan("Amor...         ", "</3             "); nota_C2_normal(E, c2); nota_C2_normal(B, np2 + c2 + np2 + c2);
  textopan("Lo nuestro solo ", "fue casualidad  "); nota_C2_normal(E, c2); nota_C2_normal(B, s2 + c2); nota_C2_normal(A, s2 + c2); nota_C2_normal(B, s2); nota_C2_normal(A, s2); nota_C2_normal(B, s2 + c2); nota_C2_normal(A, s2 + c2); nota_C2_normal(E, s2); nota_C2_normal(Cs, s2); nota_C2_normal(Gs, np2 + c2 + np2);
  textopan("La misma hora   ", "el mismo...     "); nota_C2_normal(Cs, c2); nota_C2_normal(Gs, s2 + c2); nota_C2_normal(Fas, s2 + c2); nota_C2_normal(Gs, s2); nota_C2_normal(Fas, s2); nota_C2_normal(Gs, s2 + c2); nota_C2_normal(Fas, s2 + c2);
  textopan("boulevard       ", "             :'("); nota_C2_normal(Cs, s2); nota_C2_normal(A_, s2); nota_C2_normal(E, b2 + np2);
  textopan("No temas,       ", "no hay cuidado, "); nota_C2_normal(E, s2); nota_C2_normal(E, s2 + c2); nota_C2_normal(D, c2); nota_C2_normal(Cs, c2); nota_C2_normal(D, s2); nota_C2_normal(Cs, c2 + s2); nota_C2_normal(D, c2);
  textopan("no te culpo del ", "pasado          "); nota_C2_normal(Fas, c2); nota_C2_normal(A, s2); nota_C2_normal(Cs2, c2 + s2); nota_C2_normal(B, c2); nota_C2_normal(Cs2, c2); nota_C2_normal(B, s2); nota_C2_normal(Cs2, c2 + s2); nota_C2_normal(B, c2);
  nota_C2_normal(Sil, c2);
  textopan("Ya lo ves, la   ", "vida es asi     "); nota_C2_normal(Cs2, s2); nota_C2_normal(B, s2); nota_C2_normal(Cs2, n2 + c2); nota_C2_normal(B, c2); nota_C2_normal(Fas, c2); nota_C2_normal(A, n2); nota_C2_normal(Cs2, s2); nota_C2_normal(E2, s2); nota_C2_normal(Cs2, np2 + c2 + np2);
  textopan("Tu te vas y yo  ", "me quedo aqui   "); nota_C2_normal(B, s2); nota_C2_normal(A, s2); nota_C2_normal(B, n2 + c2); nota_C2_normal(A, c2); nota_C2_normal(E, c2); nota_C2_normal(Gs, n2); nota_C2_normal(B, s2); nota_C2_normal(E2, s2); nota_C2_normal(B, b2 + n2 + c2);
  textopan("Llovera y ya no ", "sere tuya       "); nota_C2_normal(A, s2); nota_C2_normal(Gs, s2); nota_C2_normal(A, n2 + c2); nota_C2_normal(Fas, c2); nota_C2_normal(Gs, c2); nota_C2_normal(A, n2); nota_C2_normal(Gs, s2); nota_C2_normal(Fas, s2); nota_C2_normal(A, c2 + s2); nota_C2_normal(Gs, np2 + n2);
  textopan("Sere la gata    ", "                "); nota_C2_normal(Gs, n2 / 3); nota_C2_normal(A, n2 / 3); nota_C2_normal(B, n2 / 3); nota_C2_normal(B, c2 + s2); nota_C2_normal(Gs, b2 + s2);
  textopan("bajo la lluvia  ", "                "); nota_C2_normal(Gs, n2 / 3); nota_C2_normal(A, n2 / 3); nota_C2_normal(B, n2 / 3); nota_C2_directa(C2, 2 * n2 / 3); nota_C2_directa(B, n2 / 3 + b2 + n2);
  textopan("Y maullare      ", "                "); nota_C2_normal(Fas, c2); nota_C2_normal(Gs, c2); nota_C2_normal(A, c2); nota_C2_normal(Cs2, b2);
  textopan("Por ti          ", "                "); nota_C2_normal(B, c2);
  textopan("Por ti       []]", "                ");
  nota_trem_C2(B2, G2, np2, 8); nota_C2_directa(A2, s2); nota_C2_directa(B2, s2); nota_trem_C2(A2, Fas2, np2, 8); nota_C2_directa(G2, s2); nota_C2_directa(A2, s2); nota_trem_C2(G2, E2, np2, 8); nota_C2_directa(Fas2, s2); nota_C2_directa(G2, s2); nota_C2_directa(Fas2, cp2); nota_C2_directa(E2, cp2); nota_C2_directa(D2, c2); nota_trem_C2(E2, C2, n2 + c2 + b2, 20); nota_C2_directa(E2, s2); nota_C2_directa(Fas2, s2); nota_C2_directa(G2, cp2); nota_C2_directa(Fas2, cp2); nota_C2_directa(G2, c2); nota_C2_directa(A2, b2);
  noTone(PIN_BUZZER);
  delay(2000);
}

// ==========================================================
// --- SECCIÓN CANCIÓN 2: "El Triste" ---
// ==========================================================
int tempo3 = 100 * 2;
int n3 = 60000/tempo3; int s3 = n3/4; int c3 = s3*2; int b3 = n3*2; int np3 = c3*3/2; int sf3 = s3/4;

void nota_C3(int freq, int dur) { freq = freq * 2; if (freq > 0) tone(PIN_BUZZER, freq); delay(dur); noTone(PIN_BUZZER); delay(dur * 0.5); }
void nota_sf_C3(int N, int d) { int ttt = sf3; nota_C3(N*0.840, ttt); nota_C3(N*0.890, ttt); nota_C3(N*0.943, ttt); nota_C3(N, d - 3*ttt); }

void reproducirCancion2() {
  textopan("Cancion 2:", "El Triste");
  delay(2000);
  textopan("", ""); int ttt=b3+n3-c3-np3; nota_C3(Ds_, ttt/21); nota_C3(G_, ttt/21); nota_C3(C, ttt/21); nota_C3(Ds, ttt/21); nota_C3(G, ttt/21); nota_C3(C2, ttt/21); nota_C3(Ds2, ttt/21 + 2*ttt/21 +4*ttt/7);
  textopan("   :(           ", "Que triste      "); nota_sf_C3(G, c3); nota_C3(Fa, c3); nota_C3(Ds, np3);
  textopan("                ", "todos dicen     "); nota_C3(D, c3); nota_C3(C, c3); nota_C3(Gs, c3); nota_C3(Gs, c3);
  textopan("   :'(          ", "que soy         "); nota_C3(Gs, c3); nota_C3(Gs, np3 + 3 * n3); nota_C3(As_, c3); nota_C3(F_, c3); nota_C3(As_, c3 + c3); nota_C3(F_, c3);
  textopan("                ", "Que siempre     "); nota_C3(Gs, c3); nota_C3(G, c3); nota_C3(Fa, n3 + c3);
  textopan("                ", "estoy hablando  "); nota_C3(Ds, c3); nota_C3(D, c3); nota_C3(As, c3); nota_C3(As, c3);
  textopan("                ", "de ti           "); nota_C3(As, c3); nota_sf_C3(As, np3 + 3 * n3); nota_C3(C_, c3); nota_C3(Ds_, c3); nota_C3(G_, c3); nota_C3(C, n3);
  textopan("                ", "No saben que    "); nota_sf_C3(As, c3); nota_C3(Gs, c3); nota_C3(G, n3 + c3); nota_C3(Fa, c3);
  textopan("                ", "pensando en     "); nota_C3(Ds, c3); nota_C3(C2, c3); nota_C3(C2, c3);
  textopan("                ", "  tu amor       "); nota_C3(C2, c3); nota_sf_C3(C2, np3 + np3 + c3);
  textopan("                ", " En tu amor     "); nota_C3(B, c3); nota_C3(C2, c3); nota_sf_C3(D2, b3 + n3 + np3);
  nota_C3(Sil, c3);
  textopan("He podido       ", "                "); nota_C3(D2, c3); nota_C3(Ds2, c3); nota_C3(Fa2, n3 + c3 + c3);
  textopan("He podido       ", "ayudarme        "); nota_C3(Ds2, c3); nota_C3(D2, c3); nota_C3(Fa2, np3 + c3); nota_C3(Ds2, c3);
  textopan("He podido       ", "ayudarme a vivir"); nota_C3(D2, c3); nota_C3(D2, c3 / 3); nota_C3(Ds2, c3 / 3); nota_C3(D2, c3 / 3); nota_sf_C3(C2, n3 + 2 * np3);
  nota_C3(Sil, c3);
  textopan("He podido       ", "                "); nota_C3(D2, c3); nota_C3(Ds2, c3); nota_C3(Fa2, c3); nota_C3(Ds2, n3 + np3 + c3);
  textopan("ayudarme        ", "                "); nota_C3(D2, c3); nota_C3(Ds2, c3); nota_C3(Fa2, c3);
  textopan("ayudarme        ", "a vivir    :'(  "); nota_C3(Ds2, c3); nota_C3(Fa2, c3); nota_C3(G2, b3 + c3);
  textopan("   0 0          ", "   ' _ '        "); nota_sf_C3(Ds2, c3); nota_C3(D2, n3); nota_C3(C2, n3);
  textopan("   0 0          ", "    _ '         "); nota_C3(B, c3); nota_C3(C2, c3); nota_C3(Ds2, s3); nota_C3(Ds2, s3 + s3); nota_C3(Ds2, s3); nota_C3(Ds2, s3 + s3); nota_C3(Ds2, 2 * (b3 + n3 + c3));
  textopan("   0 0          ", "   ' _          "); nota_sf_C3(Fa2, c3); nota_C3(D2, n3); nota_C3(C2, n3); nota_C3(As, c3); nota_C3(C2, c3); nota_C3(D2, s3);
  textopan("   0 0          ", "    _ '         "); nota_C3(D2, s3 + s3); nota_C3(D2, s3); nota_C3(D2, s3 + s3); nota_C3(D2, 2 * (b3 + n3 + c3));
  textopan("   0 0          ", "   ' _          "); nota_sf_C3(Ds2, c3); nota_C3(C2, n3); nota_C3(As, n3); nota_C3(Gs, c3); nota_C3(As, c3);
  textopan("   0 0          ", "   ' _ '        "); nota_C3(C2, s3); nota_C3(C2, s3 + s3); nota_C3(C2, s3); nota_C3(C2, s3 + s3); nota_C3(C2, 2 * (b3 + n3 + c3));
  textopan("   0 0          ", "   ' _          "); nota_sf_C3(C2, c3); nota_C3(D2, n3); nota_C3(C2, n3); nota_C3(B, c3); nota_C3(C2, c3); nota_C3(D2, (b3 + n3));
  nota_C3(D2, s3); nota_C3(Ds2, c3); nota_C3(E2, c3); nota_C3(Fa2, s3); nota_C3(Fas2, c3); nota_C3(G2, c3); nota_C3(Gs2, s3); nota_C3(B2, s3); nota_C3(C3, c3);
  noTone(PIN_BUZZER);
  delay(2000);
}

// ==========================================================
// --- SECCIÓN CANCIÓN 4: "31 Minutos" ---
// ==========================================================
int tempo4 = 150 * 2;
int n4 = 60000/tempo4; int s4 = n4/4; int c4 = s4*2; int b4 = n4*2; int r4 = b4*2;

void nota_C4(int freq, int dur) { if (freq > 0) tone(PIN_BUZZER, freq); delay(dur); noTone(PIN_BUZZER); delay(dur * 0.5); }

void reproducirCancion3() {
  textopan("Cancion 4:", "31 Minutos");
  delay(2000);

  textopan("Yo nunca vi     ", "television      "); nota_C4(D2, n4); nota_C4(E2, c4); nota_C4(D2, n4); nota_C4(Fas2, n4 + c4); nota_C4(D2, n4); nota_C4(E2, c4); nota_C4(D2, n4); nota_C4(Fas2, n4 + c4);
  textopan("porque es muy   ", "fome            "); nota_C4(D2, n4); nota_C4(E2, c4); nota_C4(D2, n4); nota_C4(B, n4); nota_C4(D2, n4 + b4 + c4);
  nota_C4(Sil, n4);
  textopan("Yo preferia     ", "estudiar        "); nota_C4(D2, n4); nota_C4(E2, c4); nota_C4(D2, n4); nota_C4(Fas2, n4 + c4); nota_C4(D2, n4); nota_C4(E2, c4); nota_C4(D2, n4); nota_C4(Fas2, n4 + c4);
  textopan("y hasta leer    ", "                "); nota_C4(D2, n4); nota_C4(E2, c4); nota_C4(D2, n4); nota_C4(B, r4 - c4); nota_C4(B2, c4); nota_C4(B, c4);
  nota_C4(Sil, n4);
  textopan("pero mi padre   ", "que es un loco  "); nota_C4(D2, n4); nota_C4(E2, c4); nota_C4(D2, n4); nota_C4(Fas2, n4 + c4); nota_C4(D2, n4); nota_C4(E2, c4); nota_C4(D2, n4); nota_C4(Fas2, n4 + c4); nota_C4(D2, n4);
  textopan("y vende teles   ", "                "); nota_C4(E2, c4); nota_C4(D2, n4); nota_C4(B, n4); nota_C4(D2, n4); nota_C4(Fas2, n4); nota_C4(E2, c4); nota_C4(D2, c4); nota_C4(E2, n4); nota_C4(D2, c4); nota_C4(B, n4);
  nota_C4(Sil, c4);
  textopan("para mi santo me", "vendio          "); nota_C4(D2, c4); nota_C4(E2, c4); nota_C4(D2, c4); nota_C4(Fas2, n4); nota_C4(D2, n4); nota_C4(E2, c4); nota_C4(D2, n4); nota_C4(A2, n4 + c4);
  textopan("un televisor    ", "                "); nota_C4(D2, n4); nota_C4(Fas2, c4); nota_C4(E2, n4); nota_C4(D2, b4 + n4); nota_C4(B, c4); nota_C4(D2, c4); nota_C4(E2, n4);
  
  noTone(PIN_BUZZER);
  delay(2000);
}

void esperarBoton() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Presiona para");
  lcd.setCursor(0, 1);
  lcd.print("la siguiente...");
  noTone(PIN_BUZZER);
  delay(500);
  while (digitalRead(PIN_BOTON) == HIGH) {
    delay(10); 
  }
  delay(50); 
  while (digitalRead(PIN_BOTON) == LOW) {
    delay(10);
  }
}

// --- FUNCIONES PRINCIPALES DEL PROGRAMA ---
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, laDuda);
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_BOTON, INPUT_PULLUP);
  lcd.setCursor(0, 0);
  lcd.print("Reproductor");
  lcd.setCursor(0, 1);
  lcd.print("4 Canciones :)");
  delay(2000);
}

void loop() {
  switch (cancionActual) {
    case 0:
      reproducirCancion1();
      break;
    case 1:
      reproducirCancion2();
      break;
    case 2:
      reproducirCancion3();
      break;
  }
  
  esperarBoton();
  cancionActual = (cancionActual + 1) % NUM_CANCIONES;
}

