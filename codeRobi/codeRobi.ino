#include "ultraSonic.h"
#include "config.h"


void setup(){
  // Display
  Serial.begin(9600);
  

  // Buzzer
  pinMode(buzzPin, OUTPUT);

  // Ultra
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //Display OLED
  
}

void loop(){
  medirDistancia();
}
