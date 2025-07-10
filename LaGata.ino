#include <LiquidCrystal_I2C.h>

//LCD pin to Arduino
LiquidCrystal_I2C lcd(0x27,16,2);  //

  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();


// constants won't change
const int RELAY_PIN = 4;  // the Arduino pin, which connects to the IN pin of relay




int pinBuzzer = 5;

int C__ =  261/4;
int Cs__=  277/4;
int D__ =  293/4 ;
int Ds__=  311/4;
int E__ =  329/4 ;
int F__ =  349/4 ;
int Fs__=  369/4;
int G__ =  391/4 ;
int Gs__=  415/4;
int A__ =  440/4 ;
int As__=  466/4;
int B__ =  493/4;

int C_ =  261/2;
int Cs_=  277/2;
int D_ =  293/2 ;
int Ds_=  311/2;
int E_ =  329/2 ;
int F_ =  349/2 ;
int Fs_=  369/2;
int G_ =  391/2 ;
int Gs_=  415/2;
int A_ =  440/2 ;
int As_=  466/2;
int B_ =  493/2 ;


int Sil = 5;
int C =  261;
int Cs=  277;
int D =  293 ;
int Ds=  311;
int E =  329 ;
int F =  349 ;
int Fs=  369;
int G =  391 ;
int Gs=  415;
int A =  440 ;
int As=  466;
int B =  493 ;



int C2   =524;
int Cs2  =555;
int D2   =588;
int Ds2  =623;
int E2   =660;
int F2   =699;
int Fs2  =740;
int G2   =784;
int Gs2  =831;
int A_2   = 880;
int As2  =933;
int B2   =988;

int C3  =1047;
int Cs3  =555*2;
int D3   =588*2;
int Ds3  =623*2;
int E3   =660*2;
int F3   =699*2;
int Fs3  =740*2;
int G3   =784*2;
int Gs3  =831*2;
int A_3   = 880*2;
int As3  =933*2;
int B3   =988*2;



int tempo=88*2;
int negra=60000/tempo;
int semi = negra/4;

int fusa =semi/2;
int corch = 2*semi;
int np = corch*3;

int blanca = negra*2;
int redonda = blanca*2;
int rep = 3*negra;
int bnp = 3*negra+3*corch;

int r = redonda;
int b = blanca;
int n = negra;
int c = corch;
int s = c/2;
int f = s/2;
int sf = f/2;
int cp = 3*s;
int retardo = 100;

void nota(int nota, int duracion){


  nota = nota*0.89089871814;
  
  tone(pinBuzzer,nota, duracion);
  delay(duracion);
  noTone(pinBuzzer);
  delay(duracion);
}
void nota_(int nota, int duracion){


  tone(pinBuzzer,nota, duracion);
  delay(duracion);
  noTone(pinBuzzer);
  delay(duracion);
}

void iniciarCancion() {
  // initialize digital pin as an output.
  pinMode(RELAY_PIN, LOW);



 lcd.begin(16, 2);
 lcd.setCursor(0,0);
 lcd.print("La Gata Bajo la");
 lcd.setCursor(0,1);
 lcd.print("Lluvia   </3   ");

}


void cancionGata() {

 textopan("La Gata Bajo la","Lluvia           ");



    Intro();

  textopan("Amor...        ","                 ");
  Amor();

  textopan("Tranquilo no te","voy a molestar   ");
  TranquiloNoTeVoyAMolestar();

  textopan("Mi suerte      ","estaba echada    ");
    MiSuerteEstaba();

  textopan("Ya lo se       ","             :'( ");
  YaLoSeeee();  

  textopan("Y se que hay un","torrente     :'( ");
  y_se_quehayuntorrente();
  
  textopan("dando vueltas  ","por tu mente     ");
  DandoVueltasPortuMente();


// ====================================================
  
  textopan("Amor...        ","</3              ");
  Amor_();

  textopan("Lo nuestro solo","fue casualidad   ");
  TranquiloNoTeVoyAMolestar();

  textopan("La misma hora  ","el mismo...      ");
    MiSuerteEstaba();

  textopan("boulevard      ","             :'( ");
  YaLoSeeee();  

  textopan("No temas,      ","no hay cuidado,  ");
  y_se_quehayuntorrente();
  
  textopan("no te culpo del","pasado           ");
  DandoVueltasPortuMente();


// ====================================================
  nota(Sil,c);

textopan("Ya lo ves, la  ","vida es asi      ");
yaloves();
textopan("Tu te vas y yo ","me quedo aqui    ");
tutevas();
textopan("Llovera y ya no","sere tuya        ");
lloverayyanoseretuya();
textopan("Sere la gata   ","                 ");
SereLaGata(); 
textopan("bajo la lluvia ","                 ");
BajoLalluvia();
textopan("Y maullare     ","                 ");
ymaullare();
textopan("Por ti         ","                 ");
Porti();
textopan("Por ti      []]","                 ");
Outtro();

 delay(2000);


}
//C D F G


void Intro(){



  // [1]
  nota_(B2,np);
  //nota(Na,tt);nota(G2,tt);
  //nota_trem(B2,G2,np, 8);


  nota_(A_2,s);
  nota_(B2,s);
  
  nota_(A_2,np);
  //nota_trem(A_2,Fs2,np, 8);

  nota_(G2,s);  
  nota_(A_2,s);  

 // nota_(G2,np); 
  nota_trem(G2,E2,np, 8);
 
  // [2]
    
  nota_(Fs2,s); 
  nota_(G2,s);  
  nota_(Fs2,cp);  

  nota_( E2,cp);  
  nota_( D2,c); 
  // nota_( E2,n+c+b); 
  nota_trem(E2,C2,n+c+b, 20);



///////////////////
  nota_(E2,s);
  nota_(Fs2,s);
  
  nota_(G2,cp);
  nota_(Fs2,cp);
  nota_(G2,c);

  nota_(A_2,cp);
  nota_(G2 ,cp);

  nota_(A_2,c);
  
  
  // ---------
  //nota_(B2,n);

  nota_trem(B2,G2,r, 22);

//
//nota_(D2,c);
//nota_(G2,n);

nota_(Sil,c);  
nota_(B/2,c);
nota_(D2/2,c);
nota_(G2/2,n);
nota_(B/2,c);
nota_(D2/2,c);
//nota_(G2,c);   
}


void Outtro(){



  // [1]
  //nota_(B2,np);
  nota_trem(B2,G2,np, 8);

  nota_(A_2,s);
  nota_(B2,s);
  
  //nota_(A_2,np);
  nota_trem(A_2,Fs2,np, 8);

  nota_(G2,s);  
  nota_(A_2,s);  

  //nota_(G2,np);  
  nota_trem(G2,E2,np, 8);

  // [2]
    
  nota_(Fs2,s); 
  nota_(G2,s);  
  nota_(Fs2,cp);  
  //nota_trem(Fs2,D2,cp, 6);


  nota_( E2,cp); 
 
  nota_( D2,c); 
  //nota_( E2,n+c+b); 
  nota_trem(E2,C2,n+c+b, 20);
 
  //nota_trem(A_2,Fs2,np, 10);



///////////////////
  nota_(E2,s);
  nota_(Fs2,s);
  
  nota_(G2,cp);
  nota_(Fs2,cp);
  nota_(G2,c);

  nota_(A_2,b); 
  
}

void Amor(){


 
  // [1]
  nota(E,c); 
  // [2]
  nota(B,np+c+np);


 
  // nota(Sil,negra+corch);
  //nota_(A_,c);
  //nota_(D_,np);
}

void Amor_(){


 
  // [1]
  nota(E,c); 
  // [2]
  nota(B,np+c+np+c);


 
  // nota(Sil,negra+corch);
  //nota_(A_,c);
  //nota_(D_,np);
}

void TranquiloNoTeVoyAMolestar(){

  // Tranquilo no te voy a molestar
  nota(E,corch); 
  // [3]
  nota(B,semi+corch);
  nota(A,semi+corch);
  nota(B,semi); 
  nota(A,semi);
  
  nota(B,semi+corch);
  nota(A,semi+corch);
  nota(E,semi); 
  nota(Cs,semi);
  // [4]
  //nota(Gs,np);
  nota(Gs,np+c+np);
  //nota(Sil,negra+corch);
  //nota_(B_,c);
  //nota_(E_,np);

}
void MiSuerteEstaba(){
  // Mi suerte estaba echada
  nota(Cs,corch); 
  
  // [5]
  nota(Gs,semi+corch);
  nota(Fs,semi+corch);
  nota(Gs,semi); 
  nota(Fs,semi);
  
  nota(Gs,semi+corch);
  nota(Fs,semi+corch);
}
void YaLoSeeee(){  
  nota(Cs,semi); 
  nota(A_,semi);

  // [6]
  nota(E,b+np);
  
  //nota(Sil,negra+corch);
  
  //nota_(Sil,np);

}


void y_se_quehayuntorrente(){

 
  nota(E,semi);
  // [7] ...
  nota(E,semi+corch);
  nota(D,corch);    
  
  nota(Cs,corch);    
  nota(D,semi);    
  nota(Cs,corch+semi);    
  nota(D,corch);  
}


void DandoVueltasPortuMente(){
  nota(Fs,corch);
  nota(A,semi);
  
  // 8..
  nota(Cs2,corch+semi);
  nota(B,corch);

  nota(Cs2,corch);    
  nota(B,semi);    
  nota(Cs2,corch+semi);    
  nota(B,corch);  
}

void amor2(){
  nota(E,corch); 
  // 9
  nota(B,blanca);
  nota(Sil,blanca);

  nota(E,corch); 
  // [11]
  nota(B,semi+corch);
  nota(A,semi+corch);
  nota(B,semi); 
  nota(A,semi);
  
  nota(B,semi+corch);
  nota(A,semi+corch);
  nota(E,semi); 
  nota(Cs,semi);
  // [12]
  nota(Gs,blanca);
  nota(Sil,negra+corch);
 
  nota(Cs,corch); 
  
  // [13]
  nota(Gs,semi+corch);
  nota(Fs,semi+corch);
  nota(Gs,semi); 
  nota(Fs,semi);
  
  nota(Gs,semi+corch);
  nota(Fs,semi+corch);
  nota(Cs,semi); 
  nota(A_,semi);

  // [14]
  nota(E,blanca);
  nota(Sil,negra+corch);
 
  nota(E,semi);
  // [15] ...
  nota(E,semi+corch);
  nota(D,corch);    
  
  nota(Cs,corch);    
  nota(D,semi);    
  nota(Cs,corch+semi);    
  nota(D,corch);  

  nota(Fs,corch);
  nota(A,semi);
  
  // 16..
  nota(Cs2,corch+semi);
  nota(B,corch);

  nota(Cs2,corch);    
  nota(B,semi);    
  nota(Cs2,corch+semi);    
  nota(B,corch+semi+s);  

  //nota(Sil,semi); 
  

};




void yaloves(){
  
  nota(Cs2,semi);
  nota(B,semi);
  
  // [16]
  nota(Cs2,negra+corch);
  
  
  nota(B,corch);
  nota(Fs,corch);
  nota(A,negra);
  
  nota(Cs2,semi); 
  nota(E2,semi);
  
  // 17
  nota(Cs2,np+c+np);

  //nota_(B_,c);
  //nota_(B_,np);

  //nota(Sil,negra+corch);

}
  void tutevas(){  
  nota(B,semi);
  nota(A,semi);
  
  // [18]
  nota(B,negra+corch);
  
  
  nota(A,corch);
  nota(E,corch);
  nota(Gs,negra);
  
  nota(B,semi); 
  nota(E2,semi);

  // [19]
  nota(B,blanca+n+c);
  //nota(Sil,negra); //////////
  }
void lloverayyanoseretuya(){
  
  nota(A,semi);
  nota(Gs,semi);
  
  
  // [20]
  nota(A,negra+corch);
  
  
  nota(Fs,corch);
  nota(Gs,corch);
  nota(A,negra);
  
  nota(Gs,semi); 
  nota(Fs,semi);

  // 21
  nota(A,corch+semi);
  nota(Gs,np+n);
  
  //nota(Sil,negra);  nota(Sil,semi);
  ///nota_(D_,);
  //nota_(C_,n);
}
void SereLaGata(){  
  nota(Gs,negra/3);
  nota(A,negra/3);
  nota(B,negra/3);

  // 22
  nota(B,corch+semi);
  nota(Gs,b+s);
  
  
  }
void BajoLalluvia(){
  nota(Gs,negra/3);
  nota(A,negra/3);
  nota(B,negra/3);

  // 
  nota_(C2,2*n/3);
  nota_(B,n/3 + b+n);
}  

void ymaullare(){
  
//  // 23
//  nota(D2,corch+semi);
//  nota(Cs2,negra);
//  nota(Sil,blanca);
//  nota(Sil,semi);

  // 24
  nota(Fs,corch);
  nota(Gs,corch);
  nota(A, corch);

  
  nota(Cs2,blanca);


}

void Porti(){
  
  nota(B,corch);
  
  //25
  
 // nota(A,blanca);
}






void nota_sf(int N ,int d ){

    int  ttt = sf/2;
    
    nota_( N*0.84089641525 , ttt);
    nota_( N*0.89089871814 , ttt);
    nota_( N*0.94387431268 , ttt);
    
    nota_( N              , d - 3*ttt);


}




void nota_sf5(int N ,int d ){

    int  ttt = sf/2;

    nota_( N*0.74915353843 , ttt);
    nota_( N*0.79370052598 , ttt);
    nota_( N*0.84089641525 , ttt);
    nota_( N*0.89089871814 , ttt);
    nota_( N*0.94387431268 , ttt);
    
    nota_( N              , d - 5*ttt);


}





void nota_sf6(int N ,int d ){

    
    int  ttt = sf/2;
    nota_( N*0.70710678118 , ttt);
    nota_( N*0.74915353843 , ttt);
    nota_( N*0.79370052598 , ttt);
    nota_( N*0.84089641525 , ttt);
    nota_( N*0.89089871814 , ttt);
    nota_( N*0.94387431268 , ttt);
    
    nota_( N              , d - 6*ttt);


}




//nota(Na,tt);nota(G2,tt);

void nota_trem(int Na, int Nb,int f,int nr){
  
  //int nr= 4;
  int tt = f/(2*nr);


  for (int i=1; i<=nr; i++){
  nota_(Na,tt);nota_(Nb,tt);
  }
  
  
  }


  

void textopan(String S1,String S2){
  
 lcd.setCursor(0,0);
 lcd.print(S1);
 lcd.setCursor(0,1);
 lcd.print(S2);

  
  }