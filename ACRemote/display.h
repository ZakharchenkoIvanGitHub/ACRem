#include "ico.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino resetpin)
#define ICO_HEIGHT   32
#define ICO_WIDTH    32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void update_display()
{
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);

  switch (status_AC[0]){
  case 0:
        display.setCursor(0, 0);
        display.println("OFF");
        break;
  case 1:
        display.setCursor(0, 0);
        display.println(status_AC[2]);

        switch (status_AC[1]){
                case 0:
                      display.drawBitmap(96, 0, logo_auto, ICO_WIDTH,ICO_HEIGHT,WHITE);
                      break;
                case 1:
                      display.drawBitmap(96, 0, logo_fun, ICO_WIDTH,ICO_HEIGHT,WHITE);
                      break;
                case 2:
                      display.drawBitmap(96, 0, logo_dry, ICO_WIDTH,ICO_HEIGHT,WHITE);
                      break;
                case 3:
                      display.drawBitmap(96, 0, logo_cool, ICO_WIDTH,ICO_HEIGHT,WHITE);
                      break;
                case 4:
                      display.drawBitmap(96, 0, logo_heat, ICO_WIDTH,ICO_HEIGHT,WHITE);
                      break;
                }

                switch (status_AC[3]){
                case 7:
                      display.drawBitmap(60, 16, fun_auto, ICO_WIDTH,16,WHITE);
                      break;
                case 0:
                      display.drawBitmap(60, 16, fun_quiet, ICO_WIDTH,16,WHITE);
                      break;
                case 2:
                      display.drawBitmap(60, 16, fun_medium, ICO_WIDTH,16,WHITE);
                      break;;
                case 4:
                      display.drawBitmap(60, 16, fun_maximum, ICO_WIDTH,16,WHITE);
                      break;
                }

                if (status_AC[4]==15){
                  display.drawBitmap(60, 0, swing_run, ICO_WIDTH,16,WHITE);
                }else
                  display.drawBitmap(60, 0, swing_stop, ICO_WIDTH,16,WHITE);



        break;
  }

  display.display(); 
}