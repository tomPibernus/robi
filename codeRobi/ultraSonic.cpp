#include "Sounds.h"
#include "config.h"

float durationUltra;
float distanceUltra;

void beSad() {
  sonidoTriste(buzzPin);
}

void medirDistancia(){
  
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);  
  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW);
  durationUltra = pulseIn(echoPin, HIGH);
  distanceUltra = (durationUltra*.0343)/2;  

  if (distanceUltra < 3.0){
    beSad();
  }
}







