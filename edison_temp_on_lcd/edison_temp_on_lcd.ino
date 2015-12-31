// Demo of Grove - Starter Kit V2.0

// Reads the value of the Grove - Temperature Sensor, converts it to a Celsius temperature,
// and prints it to the serial console.
// Connect the Grove - Temperature Sensor to the socket marked A0
// Open the Serial Monitor in the Arduino IDE after uploading
#include <Wire.h>
#include "rgb_lcd.h"
// Define the pin to which the temperature sensor is connected.
const int pinTemp = A0;

// Define the B-value of the thermistor.
// This value is a property of the thermistor used in the Grove - Temperature Sensor,
// and used to convert from the analog value it measures and a temperature value.
const int B = 3975;

rgb_lcd lcd;
void setup()
{
   lcd.begin(16, 2);
   
   lcd.print("Temperature");
}

void loop()
{
    // Get the (raw) value of the temperature sensor.
    int val = analogRead(pinTemp);

    // Determine the current resistance of the thermistor based on the sensor value.
    float resistance = (float)(1023-val)*10000/val;

    // Calculate the temperature based on the resistance value.
    float temperatureInCel = (1/(log(resistance/10000)/B+1/298.15)-273.15);
    float temperatureInFar = (temperatureInCel*1.8+32)-4;
    lcd.setCursor(12,1);
    // Print the temperature to lcd
    lcd.print(temperatureInFar );

    // Wait one second between measurements.
    delay(1000);
}

