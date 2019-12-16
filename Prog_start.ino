#include <Arduino.h>
// décalration des constantes

const int bouton1 = 48;
const int bouton2 = 49;
const int bouton3 = 50;
const int bouton4 = 51;
const int bouton5 = 52;
const int bouton6 = 53;
const int bouton7 = 8;
const int bouton8 = 9;



//déclaration des variables

int etatbouton1 = 0;
int etatbouton2 = 0;
int etatbouton3 = 0;
int etatbouton4 = 0;
int etatbouton5 = 0;
int etatbouton6 = 0;
int etatbouton7 = 0;
int etatbouton8 = 0;

int etatboutonprec1 = 0;
int etatboutonprec2 = 0;
int etatboutonprec3 = 0;
int etatboutonprec4 = 0;
int etatboutonprec5 = 0;
int etatboutonprec6 = 0;
int etatboutonprec7 = 0;
int etatboutonprec8 = 0;


//déclaration fonctions

void allumer_tout() {
  for (int i=22;i<=46;i++)
  {
    digitalWrite(i, HIGH);
  }
}

void eteindre_tout(){
    for (int i=22;i<=46;i++)
  {
    digitalWrite(i, LOW);
  }
}

int tout_on()
{
  int etat = 1, i = 22;

  while (i<=46 && etat==1)
  {
    if (digitalRead(i)==LOW)
    {
      etat=0;
    }
    i++;
  }
  return etat;
}

void sequence_bouton1() {
  digitalWrite(22, HIGH);
  digitalWrite(23, HIGH);
  digitalWrite(24, HIGH);
  digitalWrite(25, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(42, LOW);
}

void sequence_bouton2() {
  digitalWrite(32, HIGH);
  digitalWrite(33, HIGH);
  digitalWrite(34, HIGH);
  digitalWrite(35, HIGH);
  digitalWrite(36, HIGH);
  digitalWrite(27, LOW);
}

void sequence_bouton3() {
  digitalWrite(27, HIGH);
  digitalWrite(28, HIGH);
  digitalWrite(29, HIGH);
  digitalWrite(30, HIGH);
  digitalWrite(31, HIGH);
  digitalWrite(22, LOW);
}

void sequence_bouton4() {
  digitalWrite(37, HIGH);
  digitalWrite(38, HIGH);
  digitalWrite(39, HIGH);
  digitalWrite(40, HIGH);
  digitalWrite(41, HIGH);
  digitalWrite(32, LOW);
  digitalWrite(34, LOW);
}

void sequence_bouton5() {
  digitalWrite(22, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(32, HIGH);
  digitalWrite(37, HIGH);
}

void sequence_bouton6() {
  digitalWrite(22, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(32, HIGH);
  digitalWrite(37, HIGH);
  digitalWrite(42, HIGH);
  digitalWrite(23, LOW);
  digitalWrite(28, LOW);
  digitalWrite(33, LOW);
  digitalWrite(38, LOW);
  digitalWrite(43, LOW);
}

void sequence_bouton7() {
  digitalWrite(42, HIGH);
  digitalWrite(43, HIGH);
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(37, LOW);
}

void f_piege(){
  for (int i=0; i<=10; i++)
  {
    allumer_tout();
    delay(200);
    eteindre_tout();
    delay(200);
    
  }
}

void f_bouton1()
{
  sequence_bouton1();
}

void f_bouton2()
{
  sequence_bouton2();
}

void f_bouton3()
{
  sequence_bouton3();
}

void f_bouton4()
{
  sequence_bouton4();
}

void f_bouton5()
{
  sequence_bouton5();
}

void f_bouton6()
{
  sequence_bouton6();
}

void f_bouton7()
{
  f_piege();
}

void f_bouton8()
{
  sequence_bouton7();
}

void soluce(){
  eteindre_tout();
  allumer_tout();
}

int test_interrupt()
{
  int inter = 0;
  etatbouton1 = digitalRead(bouton1);
  etatbouton2 = digitalRead(bouton2);
  etatbouton3 = digitalRead(bouton3);
  etatbouton4 = digitalRead(bouton4);
  etatbouton5 = digitalRead(bouton5);
  etatbouton6 = digitalRead(bouton6);
  etatbouton7 = digitalRead(bouton7);
  etatbouton8 = digitalRead(bouton8);

  if ( etatbouton1 != etatboutonprec1)
  {
    eteindre_tout();
    f_bouton1();
    inter = 1;
  }
  if ( etatbouton2 != etatboutonprec2)
  {
    eteindre_tout();
    f_bouton2();
    inter = 1;
  }
  if ( etatbouton3 != etatboutonprec3)
  {
    eteindre_tout();
    f_bouton3();
    inter = 1;
  }
  if ( etatbouton4 != etatboutonprec4)
  {
    eteindre_tout();
    f_bouton4();
    inter = 1;
  }
  if ( etatbouton5 != etatboutonprec5)
  {
    eteindre_tout();
    f_bouton5();
    inter = 1;
  }
  if ( etatbouton6 != etatboutonprec6)
  {
    eteindre_tout();
    f_bouton6();
    inter = 1;
  }
  if ( etatbouton7 != etatboutonprec7)
  {
    eteindre_tout();
    f_bouton7();
    inter = 1;
  }
  if ( etatbouton8 != etatboutonprec8)
  {
    eteindre_tout();
    f_bouton8();
    inter = 1;
  }

  etatboutonprec1 = etatbouton1;
  etatboutonprec2 = etatbouton2;
  etatboutonprec3 = etatbouton3;
  etatboutonprec4 = etatbouton4;
  etatboutonprec5 = etatbouton5;
  etatboutonprec6 = etatbouton6;
  etatboutonprec7 = etatbouton7;
  etatboutonprec8 = etatbouton8;

  return inter;

}

int test_interrupt_en_jeu(int temps)
{
  etatbouton1 = digitalRead(bouton1);
  etatbouton2 = digitalRead(bouton2);
  etatbouton3 = digitalRead(bouton3);
  etatbouton4 = digitalRead(bouton4);
  etatbouton5 = digitalRead(bouton5);
  etatbouton6 = digitalRead(bouton6);
  etatbouton7 = digitalRead(bouton7);
  etatbouton8 = digitalRead(bouton8);

  if ( etatbouton1 != etatboutonprec1)
  {
    f_bouton1();
    temps=0;
  }
  if ( etatbouton2 != etatboutonprec2)
  {
    f_bouton2();
    temps=0;
  }
  if ( etatbouton3 != etatboutonprec3)
  {
    f_bouton3();
    temps=0;
  }
  if ( etatbouton4 != etatboutonprec4)
  {
    f_bouton4();
    temps=0;
  }
  if ( etatbouton5 != etatboutonprec5)
  {
    f_bouton5();
    temps=0;
  }
  if ( etatbouton6 != etatboutonprec6)
  {
    f_bouton6();
    temps=0;
  }
  if ( etatbouton7 != etatboutonprec7)
  {
    f_bouton7();
    temps=-1;
  }
  if ( etatbouton8 != etatboutonprec8)
  {
    f_bouton8();
    temps=0;
  }

  etatboutonprec1 = etatbouton1;
  etatboutonprec2 = etatbouton2;
  etatboutonprec3 = etatbouton3;
  etatboutonprec4 = etatbouton4;
  etatboutonprec5 = etatbouton5;
  etatboutonprec6 = etatbouton6;
  etatboutonprec7 = etatbouton7;
  etatboutonprec8 = etatbouton8;
  
  return temps;
}

void chenillard()
{
  int i=0, j=0, inter=0, T[16]={22,23,24,25,26,31,36,41,46,45,44,43,42,37,32,27}; // se référer au excel

  eteindre_tout();
  for (i = 0; i<=6; i++)
  {
    digitalWrite(T[i], HIGH);
  }
 i = 0;
  while (inter == 0)
  {
    j=0;
    if (i==16)
    {
      i=0;
    }
    digitalWrite(T[i], LOW);

    if (i+7>15)
    {
      j = i+7-16;
      digitalWrite(T[j], HIGH);
    }
    else
    {
      digitalWrite(T[i], HIGH);
    }
    i++;
    inter=test_interrupt();   
  }
  
}





// code principale


void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  
  //Setup pins
  for (int i = 22; i <= 46; i++){
        pinMode(i, OUTPUT);  //Ou OUTPUT_OPEN_DRAIN

      }
  
  //Setup Bouttons
    for (int i = 48; i <= 53; i++){
        pinMode(i, INPUT);

      }
    pinMode(8, INPUT);
    pinMode(9, INPUT);  
     
  
    
  allumer_tout();
  delay(1000);
  eteindre_tout();
  delay(1000);

    Serial.println("test2");
}



void loop() {
  // put your main code here, to run repeatedly:

   Serial.println("test");

  if (tout_on() == 0)
  {
    chenillard();
    int temps = 0, piege = 0;
    while (temps<30000 || piege==1)
    {
      temps = test_interrupt_en_jeu(temps);
      if (temps<0)
      {
        piege = 1;
      }
      delay(100);
      temps += 100;
    }
  }
  else
  {
    //déverouiller le verrou grâce au Node Red
  }
}
