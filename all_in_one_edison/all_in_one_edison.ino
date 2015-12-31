// Demo of Grove - Starter Kit V2.0

// Reads the value of the Grove - Temperature Sensor, converts it to a Celsius temperature,
// and prints it to the serial console.
// Connect the Grove - Temperature Sensor to the socket marked A0
// Open the Serial Monitor in the Arduino IDE after uploading
#include <Wire.h>
#include "rgb_lcd.h"
#include <Servo.h>


// Define the pin to which the temperature sensor is connected.
const int pinTemp = A0;
const int pinButton = 7;
const int pinLed    = 3;
const int pinServo = 5;
const int potentiometer = A1;
const int touchPin = 2;
const int relayPin =  4;
const int colorR = 0;
const int colorG = 0;
const int colorB = 0;
const int lightPin = A3;

// Define the B-value of the thermistor.
// This value is a property of the thermistor used in the Grove - Temperature Sensor,
// and used to convert from the analog value it measures and a temperature value.
const int B = 3975;
Servo groveServo;
rgb_lcd lcd;
void setup()
{
   lcd.begin(16, 2);
   lcd.setRGB(colorR, colorG, colorB);
   
   // Configure the button's pin for input signals.
    pinMode(pinButton, INPUT);

    // Configure the LED's pin for output.
    pinMode(pinLed, OUTPUT);
    groveServo.attach(pinServo);

    // Configure the angle sensor's pin for input signals.
    pinMode(potentiometer, INPUT);
    // Configure the relay's pin for output signals.
    pinMode(relayPin, OUTPUT);

}

void loop()
{
   {
      int buttonState = digitalRead(touchPin);
      int buttonState2 = digitalRead(pinButton);
      if (buttonState == 1)
      {
        lcd.setRGB(255, 0, 0);
      }
      else 
      {
        lcd.setRGB(0,255,0);
      }
       if (buttonState2 == 1)
      {
        lcd.setRGB(0,0,255);
      }
      
      
      
    }
  {
    int buttonState = digitalRead(touchPin);

    // If the button is pressed, activate (close) the relay.
    if (buttonState == 1)   
    {
        digitalWrite(relayPin, HIGH);
    }
    else   
    {
        digitalWrite(relayPin, LOW);
    }
    delay(10);
  }
  {
     int sensorPosition = analogRead(potentiometer);

    // The analog value from the angle sensor is between 0 and 1023, but
    // the servo only accepts values between 0 and 179; use the map()
    // function as a linear conversion between the two ranges.
    int shaftPosition = map(sensorPosition, 0, 1023, 0, 179);

    // Use the Servo object to move the servo.
    groveServo.write(shaftPosition);

    delay(15);
  }
  
  {
      if(digitalRead(pinButton))
    {
        // When the button is pressed, turn the LED on.
        digitalWrite(pinLed, HIGH);
    }
    else
    {
        // Otherwise, turn the LED off.
        digitalWrite(pinLed, LOW);
    }
    delay (10);
    
    }
    {// Get the (raw) value of the temperature sensor.
      
    int val = analogRead(pinTemp);

    // Determine the current resistance of the thermistor based on the sensor value.
    float resistance = (float)(1023-val)*10000/val;

    // Calculate the temperature based on the resistance value.
    float temperatureInCel = (1/(log(resistance/10000)/B+1/298.15)-273.15);
    float temperatureInFar = (temperatureInCel*1.8+32)-4;
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    
    // Print the temperature to lcd
    lcd.print(temperatureInFar );
    lcd.print(" F");
    

    // Wait one second between measurements.
    delay(07);
    }
    {
      int sensorVal = analogRead(lightPin);
      lcd.setCursor(0,2);
      lcd.print("Brightness ");
      lcd.print(sensorVal);
      delay(0);
      
    }
    
    
    
    
}


