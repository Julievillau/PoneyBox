#include<Servo.h>
//fil marrons = gnd   pour SG90
//fil rouge = 5v
//fil orange = pwm

Servo moteur1 ; //on le nome

void setup() {
  moteur1.attach(5); //on donne le numero d'une sortit pwm
}

void ServoMoteur(String nom,int positionActuel, int positionfuture,int vitesse){
  for (int position = positionActuel; position <= positionfuture; position=position + vitesse) {
    moteur1.write(position);  // donner directement l'angle
    delay(20);
    }
  }


void loop() {
  ServoMoteur('moteur1',0,100,3);// utilisation de la fonction

}

  
