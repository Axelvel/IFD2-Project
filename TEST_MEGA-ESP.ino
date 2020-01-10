#include <string.h>


#define PIN_LED 13
String inString; //chaine de caractère dans laquelle se retrouve toutes les informations reçues par nodered
String commandeNodeRed; //Chaine de caractère avec uniquement les commandes voulues de NodeRed



void setup() {
  // Initialisation des ports et sorties (ESP envoie/reçoit vers ATMega avec serial, ATMega envoie/Reçoit vers ESP avec serial3)
  Serial.begin(115200);
  Serial3.begin(115200);
}

void loop() {
}

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
