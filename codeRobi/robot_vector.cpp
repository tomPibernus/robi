#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "config.h"
#include "ultraSonic.h"
#include "sounds.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#include "eyes.h"

void initFace() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.display();
}

int mood = 1;
int xp=16;

// Helper to draw eyes at specific offset/mood
void drawEyes(int xd_val, int mood_val) {
  int x1 = xd_val + (xp>16? (16+2*(xp-16)):xp);
  int x2 = 64 + xd_val + (xp<16? (-16+(xp*2))  :xp);

  display.clearDisplay(); 
  if (xp<6) { 
          display.drawBitmap(x1, 8, peyes[mood_val][2][0], 32, 32, WHITE);
          display.drawBitmap(x2, 8, peyes[mood_val][1][1], 32, 32, WHITE);
  } else if (xp<26) {
          display.drawBitmap(x1, 8, peyes[mood_val][0][0], 32, 32, WHITE);
          display.drawBitmap(x2, 8, peyes[mood_val][0][1], 32, 32, WHITE); 
  } else {
          display.drawBitmap(x1, 8, peyes[mood_val][1][0], 32, 32, WHITE); 
          display.drawBitmap(x2, 8, peyes[mood_val][2][1], 32, 32, WHITE);
  }
  display.display();
}

void angryShake(int id) {
   // Fast shake animation
   for(int i=0; i<8; i++) {
      int shake = (i % 2 == 0) ? -6 : 6; 
      drawEyes(shake, id);
      delay(40); 
   }
   drawEyes(0, id); // Return to center
}



void face(int id) {
  int n;

  Serial.println(id);


  static int xd=0;
  static int espera=0;
  static int step=0;
  int x1,x2; 
  
  mood=id;



  if (espera>0) {
    espera--;
    delay(1);
  } else {
    x1=   xd+ (xp>16? (16+2*(xp-16)):xp);
    x2=64+xd+ (xp<16? (-16+(xp*2))  :xp);
    switch (step){
      case 0:
       // Using helper function
       drawEyes(xd, mood);
       // ... existing random logic ...
       espera=random(250, 1000);
       n=random(0,7);
       if (n==6) {
          step=1;
       } else {
          step=2;
       }
       break;
      case 1:
       display.clearDisplay(); // Clear the display buffer
       display.drawBitmap(x1, 8, eye0, 32, 32, WHITE);
       display.drawBitmap(x2, 8, eye0, 32, 32, WHITE);
       display.display();
       espera=100;
       step=0;
       break;
      case 2:
       n=random(0,10);
       if (n<5) xd--;
       if (n>5) xd++;
       if (xd<-4) xd=-3;
       if (xd>4) xd=3; 
       espera=0;
       step=0;
       break;
    }
  }

  // if (id==2) xp=(xp<=0?0:xp-1); 
  // if (id==4) xp=(xp>=32?32:xp+1);
  

  if (id!=0) { espera=0; step=0; }

}