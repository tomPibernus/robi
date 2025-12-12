#include "ultraSonic.h"
#include "config.h"
#include "robot_vector.h"
#include "sounds.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)



void setup(){
  // Display
  Serial.begin(9600);
  initFace(); 

  // Buzzer
  pinMode(buzzPin, OUTPUT);

  // Ultra
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //Display OLED
  
}

void loop(){
  // Check sensor FIRST to interrupt waiting
  float dist = medirDistancia();
  if (dist < 3.0) {
    sonidoTriste(buzzPin);
    angryShake(3); 
    // angryShake takes ~320ms + drawing time
  } else {
    face(1);
  }
}
