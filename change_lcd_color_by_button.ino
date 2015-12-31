#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
const int touchPin = 2;
const int colorR = 0;
const int colorG = 0;
const int colorB = 0;
const int pinButton = 7;
void setup() 
{
 // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    
    // Print a message to the LCD.
    lcd.print("Hello World");

    delay(1000);  // put your setup code here, to run once:

}

void loop() 
{
// set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    {
      int buttonState = digitalRead(touchPin);
      int buttonState2 = digitalRead(pinButton);
      if (buttonState == 1)
      {
        lcd.setRGB(0, 255, 0);
      }
      else 
      {
        lcd.setRGB(255,255,255);
      }
       if (buttonState2 == 1)
      {
        lcd.setRGB(0,0,255);
      }
      
      
      
    }

}
