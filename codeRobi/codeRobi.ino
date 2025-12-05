#include "ultraSonic.h"
#include "config.h"

void setup(){
  // Display
  

  // Buzzer
  pinMode(buzzPin, OUTPUT);

  // Ultra
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loop(){
  medirDistancia();
}
