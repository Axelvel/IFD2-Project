#include <MQTT.h>
#include <ESP8266WiFi.h>

MQTTClient client;
WiFiClient wificlient;

//COORDONNEES WIFI
const char ssid[] = "Crunch LAB";
const char pass[] = "90xV@FsT";
const char hostname[14] = "192.168.1.101"; //IPv4 du broker à obtenir en tapant ipconfig dans le cmd

void connect() {
  //TENTATIVE DE CONNEXION
  Serial.println("[Start]");
  Serial.println("[checking wifi...]");
  while (WiFi.status() != WL_CONNECTED) {
  Serial.print(".");
  delay(1000);
  }

  //CONNEXION
  Serial.println("[connecting...]");
  while (!client.connect("CASSETETE", "try", "try")) {
  Serial.print("+");
  delay(1000);
  }
  Serial.println("[connected!]");

  //AFFICHE LADRESSE IP DANS LE MONITEUR SERIE
  Serial.print("IP address: ");  //  
  Serial.println(WiFi.localIP());

  //ABONNEMENT AU TOPIC NODERED CORRESPONDANT
  client.subscribe("/esp/cassetete");

}

//FONCTION QUI RECUPERE UN MESSAGE DE NODERED (payload) ET LE MET ENTRE CROCHER
void messageReceived(String &topic, String &payload) {
  Serial.print("[");
  Serial.print(payload);
  Serial.println("]");
}



void setup() {
  //COMMENCE LA CONNEXION AVEC LE PORT SERIE
  Serial.begin(115200);
  //COMMENCE LA CONNEXION WIFI
  WiFi.begin(ssid, pass);
  client.begin(hostname, 1883, wificlient);
  client.onMessage(messageReceived);
  
  connect();
}

void loop(void){
  //PERMET DE RESTER CONNECTE
  client.loop();
  if (!client.connected()) { 
    connect(); 
  } 


  
