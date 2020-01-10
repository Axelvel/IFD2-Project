#include <Arduino.h>
#include <string.h>


#define PIN_LED 13
String inString; //chaine de caractère dans laquelle se retrouve toutes les informations reçues par nodered
String commandeNodeRed; //Chaine de caractère avec uniquement les commandes voulues de NodeRed

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

bool stateb1 = false;
bool stateb2 = false;
bool stateb3 = false;
bool stateb4 = false;
bool stateb5 = false;
bool stateb6 = false;
bool stateb7 = false;
bool stateb8 = false;


int etat = 0, reset = 1, test_push = 0, temps = 0, i=0, j=0, T[16]={22,23,24,25,26,31,36,41,46,45,44,43,42,37,32,27};


//déclaration fonctions

void allumer_tout() {
  for (int k=22;k<=46;k++)
  {
    digitalWrite(k, LOW);
  }
}

void eteindre_tout(){
    for (int k=22;k<=46;k++)
  {
    digitalWrite(k, HIGH);
  }
}

int tout_on()
{
  int win = 1, k = 22;

  while (k<=46 && win==1)
  {
    if (digitalRead(k)==HIGH)
    {
      win=0;
    }
    k++;
  }
  return win;
}

void sequence_bouton1() {
  digitalWrite(22, LOW);
  digitalWrite(23, LOW);
  digitalWrite(24, LOW);
  digitalWrite(25, LOW);
  digitalWrite(26, LOW);
  digitalWrite(42, HIGH);
}

void sequence_bouton2() {
  digitalWrite(32, LOW);
  digitalWrite(33, LOW);
  digitalWrite(34, LOW);
  digitalWrite(35, LOW);
  digitalWrite(36, LOW);
  digitalWrite(27, HIGH);
}

void sequence_bouton3() {
  digitalWrite(27, LOW);
  digitalWrite(28, LOW);
  digitalWrite(29, LOW);
  digitalWrite(30, LOW);
  digitalWrite(31, LOW);
  digitalWrite(22, HIGH);
}

void sequence_bouton4() {
  digitalWrite(37, LOW);
  digitalWrite(38, LOW);
  digitalWrite(39, LOW);
  digitalWrite(40, LOW);
  digitalWrite(41, LOW);
  digitalWrite(32, HIGH);
  digitalWrite(34, HIGH);
}

void sequence_bouton5() {
  digitalWrite(22, LOW);
  digitalWrite(27, LOW);
  digitalWrite(32, LOW);
  digitalWrite(37, LOW);
}

void sequence_bouton6() {
  digitalWrite(22, LOW);
  digitalWrite(27, LOW);
  digitalWrite(32, LOW);
  digitalWrite(37, LOW);
  digitalWrite(42, LOW);
  digitalWrite(23, HIGH);
  digitalWrite(28, HIGH);
  digitalWrite(33, HIGH);
  digitalWrite(38, HIGH);
  digitalWrite(43, HIGH);
}

void sequence_bouton7() {
  digitalWrite(42, LOW);
  digitalWrite(43, LOW);
  digitalWrite(44, LOW);
  digitalWrite(45, LOW);
  digitalWrite(46, LOW);
  digitalWrite(37, HIGH);
}

void f_piege(){
  for (int k=0; k<=3; k++)
  {
    allumer_tout();
    delay(500);
    eteindre_tout();
    delay(500);
    
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

/*int test_interrupt()
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
}*/

void test_etat_ch(void)
{
  if (etat == 0)
  {
    eteindre_tout();
  }
}

void test_interrupt_en_jeu(void)
{

  //Bouton1
  
  if (digitalRead(bouton1) == HIGH) {
    if (!stateb1) {
      Serial.print("1");
      test_etat_ch();
      f_bouton1();
      etat = 1;
      stateb1 = true;
    }
  } else {
    if (stateb1) {
    Serial.print("1"); // changement est actif donc lancer le f_bouton
    test_etat_ch();
    f_bouton1();
    etat = 1;
    stateb1 = false;
    }
  }

 //Bouton2

    if (digitalRead(bouton2) == HIGH) {
    if (!stateb2) {
      test_etat_ch();
      f_bouton2();
      Serial.print("2");
      etat = 2;
      stateb2 = true;
    }
  } else {
    if (stateb2) {
    test_etat_ch();
    f_bouton2();
    Serial.print("2");
    etat = 2;
    stateb2 = false;
    }
  }

    //Bouton3

    if (digitalRead(bouton3) == HIGH) {
    if (!stateb3) {
      test_etat_ch();
      f_bouton3();
      Serial.print("3");
      etat = 3;
      stateb3 = true;
    }
  } else {
    if (stateb3) {
    test_etat_ch();
    f_bouton3();
    Serial.print("3");
    etat = 3;
    stateb3 = false;
    }
  }

    //Bouton4

    if (digitalRead(bouton4) == HIGH) {
    if (!stateb4) {
      test_etat_ch();
      f_bouton4();
      Serial.print("4");
      etat = 4;
      stateb4 = true;
    }
  } else {
    if (stateb4) {
      test_etat_ch();
      f_bouton4();
      Serial.print("4");
      etat = 4;
      stateb4 = false;
    }
  }

     //Bouton5

    if (digitalRead(bouton5) == HIGH) {
    if (!stateb5) {
      test_etat_ch();
     f_bouton5();
      Serial.print("5");
      etat = 5;
      stateb5 = true;
    }
  } else {
    if (stateb5) {
      test_etat_ch();
    f_bouton5();
    Serial.print("5");
    etat = 5;
    stateb5 = false;
    }
  }

   //Bouton6

    if (digitalRead(bouton6) == HIGH) {
    if (!stateb6) {
      test_etat_ch();
      f_bouton6();
      Serial.print("6");
      etat = 6;
      stateb6 = true;
    }
  } else {
    if (stateb6) {
      test_etat_ch();
    f_bouton6();
    Serial.print("6");
    etat = 6;
    stateb6 = false;
    }
  }

    //Bouton7

    if (digitalRead(bouton7) == HIGH) {
    if (!stateb7) {
      test_etat_ch();
      f_bouton7();
      etat = 0;
      stateb7 = true;
    }
  } else {
    if (stateb7) {
      test_etat_ch();
    f_bouton7();
    etat = 0;
    stateb7 = false;
    }
  }


    //Bouton8

    if (digitalRead(bouton8) == HIGH) {
    if (!stateb8) {
      test_etat_ch();
      f_bouton8();
      Serial.print("8");
      etat = 8;
      stateb8 = true;
    }
  } else {
    if (stateb8) {
      test_etat_ch();
    f_bouton8();
    Serial.print("8");
    etat = 8;
    stateb8 = false;
    }
}
     

}


/*void chenillard()
{
  int i=0, j=0, inter=0, T[16]={22,23,24,25,26,31,36,41,46,45,44,43,42,37,32,27}; // se référer au excel
  eteindre_tout();
  for (i = 0; i<=6; i++)
  {
    digitalWrite(T[i], LOW);
  }
 i = 0;
  while (inter == 0)
  {
    j=i+7;
    if (i==16)
    {
      i=0;
    }
    digitalWrite(T[i], HIGH);
    
    if (j>15)
    {
      j = j-16;
      digitalWrite(T[j], LOW);
    }
    else
    {
      digitalWrite(T[j], LOW);
    }
    i++;  
  }
  
}*/

// SE LANCER LORSQUE UN EVENEMENT EST DETECTE SUR LE SERIAL3
void serialEvent3() {
  while (Serial3.available()) {
    // Lecture des données Serial3 (ESP -> ATMega) 
    char inChar = Serial3.read();
    // Sortie des données lues sur le port série (ATMega -> ESP) peut-être pas nécessaire ici
    Serial.write(inChar);
    inString += inChar; //On ajoute les caractères dans la chaine inString à chaque fois
    //On chercher parmi cette chaîne les caractères qui nous intéressent
    if (inChar == ']') {
      if (inString.indexOf("TERMINER")>0) {
        digitalWrite(PIN_LED, HIGH);
        commandeNodeRed = 'TERMINER';
       
      }
      else if (inString.indexOf("RESET")>0) {
        digitalWrite(PIN_LED, LOW);
        commandeNodeRed = 'RESET';
      }
      else
      {
        Serial.print("Recu: ");
        Serial.println(inString);
        Serial.println("");
      }
      inString = "";
    }
  }
}

//Fonction à utiliser lorsque le jeu se termine
//Se termine soit par commande NodeRed, soit par fin du jeu, dans tous les cas, commandeNodeRed = 'TERMINER' (voir à l'appeler autrement du coup)
//if(strcmp(commandeNodeRed,'TERMINER')==0){
//  Serial3.print("[");
// Serial3.print("OUVRIR");
// Serial3.println("]");; 
//}





// code principale


void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  // Initialisation des ports et sorties (ESP envoie/reçoit vers ATMega avec serial, ATMega envoie/Reçoit vers ESP avec serial3)
  Serial.begin(115200);
  Serial3.begin(115200);
  
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
    eteindre_tout();
    
    
}



void loop() {
  if (tout_on() == 0)
  {
    if (etat==0) // test état du jeu, 0 -> en attente, !=0, en jeu
    { //Serial.println("reset1");
     /// Serial.println(reset);
      if (reset==1) // test si il faut initialiser le chenillard
      {
          eteindre_tout();
          reset = 0; // permet d'initialiser qu'une seul fois
          temps = 0; // remet le temps à 0 pour le prochain essai de jeu
         Serial.println("reset");
          for (int k = 0; k<=6; k++) // allume les 7 premières LED
            {
              digitalWrite(T[k], LOW);
            }
          i = 0;
        //  Serial.println("reset2");
        //  Serial.println(reset);
      }
      j=i+7; //cible la tête du chenillard
      if (i==16) //renvoie le pointeur de queue au début du tableau si il atteint la fin
      {
        i=0;
      }
      digitalWrite(T[i], HIGH); //éteint la LED suivante
      if (j>15) // si le pointeur de tête dépasse la taille du tableau il est remis au début 
      {
        j = j-16;
        digitalWrite(T[j], LOW);
      }
      else
      {
        digitalWrite(T[j], LOW);
      }
      i++; //incrémentation du chenillard
      test_interrupt_en_jeu();//mise à jour de l'état
     
      Serial.println(etat);
      delay(250);
    }
    else
    { 
      Serial.println(temps);
      Serial.println(etat);
      if (temps >= 30000) // test si le temps d'inactivité n'est pas dépassé
      {
        Serial.println("test");
        f_piege(); //lance le piège
        etat = 0; //remet l'état au chenillard
        Serial.println(etat);
        temps = 0;
        reset = 1; //active le reset au prochain loop
      }
      else
      {
        test_push = etat; //vérifie si un bouton a été enclenché
        test_interrupt_en_jeu();
        if (test_push != etat) //reset le temps equand un bouton a été enclenché
        {
          temps = 0;
          Serial.println("temps");
        }
        if (etat == 0) //active le reset pour le prochain loop
        {
          reset = 1;
        }
        temps += 100;
        delay(100);
        
      }
    }
  }
  else
  {
    Serial.println("Win");
    //déverouiller le cadenas via node red
  }
}
