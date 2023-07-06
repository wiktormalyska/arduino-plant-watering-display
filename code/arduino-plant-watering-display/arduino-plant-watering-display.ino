#include <SPI.h>
#include "epd1in54_V2.h"
#include "epdpaint.h"
#include <cstdio>

//--- SETUP ---
int refreshDelay = 36;
int analogPins[] = {A0, A1, A2, A3};
//-------------

Epd epd;
unsigned char image[1024];
Paint paint(image, 0, 0);

unsigned long time_start_ms;
unsigned long time_now_s;
#define COLORED     0
#define UNCOLORED   1

// Function declarations
void drawHeader(int number);
void drawBox(int number, double fill);

void setup() {
  // Initialize
  Serial.begin(115200);
  epd.LDirInit();
  epd.Clear();

  // Draw Headers
  for (int i = 1; i <= 4; i++) {
    drawHeader(i);
  }
  // Draw Init Boxes
  for (int i = 1; i <= 4; i++) { 
    drawBox(i, 0);
  }

  // Show
  epd.DisplayFrame();
}

void loop() {
   //Get Values and set box sizes
   for(int i= 0;i<4;i++){
    double value = analogRead(analogPins[i]);
    value = value/320;
  drawBox(i+1, value);
   }
  //Display
  epd.DisplayFrame();
  delay(1000*refreshDelay);
}

void drawHeader(int number) {
  char text[20];
  sprintf(text, "%d", number);
  paint.SetWidth(40);
  paint.SetHeight(20);
  paint.Clear(COLORED);
  paint.DrawStringAt(14, 5, text, &Font16, UNCOLORED);
  epd.SetFrameMemory(paint.GetImage(), (8 + 40) * (number - 1) + 9, 6, paint.GetWidth(), paint.GetHeight());
}

void drawBox(int number, double fill) {
  paint.SetWidth(40);
  paint.SetHeight(160);
  paint.Clear(UNCOLORED);
  paint.DrawFilledRectangle(0, paint.GetHeight() * (1 - fill), paint.GetWidth(), paint.GetHeight(), COLORED);
  epd.SetFrameMemory(paint.GetImage(), (8 + 40) * (number - 1) + 9, 32, paint.GetWidth(), paint.GetHeight());
}