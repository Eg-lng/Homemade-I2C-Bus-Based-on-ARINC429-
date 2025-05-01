#include <Arduino.h>

void bit1(); 
void bit0();


short int P = 0; // bit de parité !!!
short int A = 0; // variable A


double currentTime = 0;
double lastTime = 0;

double getLastTime(){
   return currentTime = millis()- lastTime; // horloge
}



// ENVOIE SUR LE BUS '1'
void bit1()
{
    digitalWrite(5,1);
    digitalWrite(6,1);
    delayMicroseconds(40); // 40 microsecondes
    digitalWrite(5,0);
    digitalWrite(6,0);
    delayMicroseconds(40); // 40 microsecondes
    P++;
}
// Envoie sur le Bus 0
void bit0()
{
    digitalWrite(6,1);
    delayMicroseconds(40); // 40 microsecondes
    digitalWrite(6,0);
    delayMicroseconds(40); // 40 microsecondes
}

void setup(){
    pinMode(5,OUTPUT); // pin data
    pinMode(6,OUTPUT); // pin clock
    pinMode(7,INPUT);  // input variable A 
    pinMode(8,OUTPUT); // LED de defaut 
}


void loop(){
    lastTime = millis();

    // mettre les capteur ici

    // Exemple : 
    if (digitalRead(7) == HIGH ) {
      (A = 1);
    }


    delay((25) - (getLastTime()));
    bit1();
    bit1();
    bit1();
    bit1();
    bit1();
    bit1();
    bit1();
    bit1();
    bit1();
    bit0();



   if ( A == 1 ) {
    bit1();
    bit0();
    bit0();
    bit0();
    }
    else{
        bit1();
        bit1();
        bit1();
        bit1();
        digitalWrite(8,1);
    }


    bit0();
    bit0();
    bit0();
    bit0();
    bit0();
    bit0();
    bit0();
    bit0();
    bit0();
    bit0();
    bit0();
    bit0();
    bit0();
    bit0();
    bit0();
    bit0();
    bit0();

    
    if(P == 1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31) bit1();
    else bit0();
  
    digitalWrite(8,0);

    A = 0;
    P = 0;

}