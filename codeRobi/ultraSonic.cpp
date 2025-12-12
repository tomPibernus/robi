#include "config.h"
#include "robot_vector.h"

float durationUltra;
float distanceUltra;

float medirDistancia(){
  
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);  
  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW);
  durationUltra = pulseIn(echoPin, HIGH);
  distanceUltra = (durationUltra*.0343)/2; 



  return distanceUltra;
}







