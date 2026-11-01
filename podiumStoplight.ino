#include "BluetoothSerial.h"

BluetoothSerial serialBT; // Create an instance of a BlueTooth serial connection object
char cmdBT; // Name the variable we will use for our bluetooth command

// Define pin assignments
unsigned int ledYellow = 18; // Define the pin number the yellow LED is connected to
unsigned int ledRed = 19; // Define the pin number the red LED is connected to
//unsigned int pairingButton = 4; // Define the pin number of the bluetooth pairing button

// Define polling variables
unsigned int pollPeriod = 100; // Check for a bluetooth message this many ms
unsigned long prevPoll;

/* Bluetooth commmands (cmdBT) that can be received from the app:
 * "g" = All LED's off
 * "y" = Yellow LED on
 * "r" = Red LED on
 * Any other commands?
 */

void setup() {
  // put your setup code here, to run once:

  // Define what each pin does
  pinMode(ledYellow,OUTPUT);
  pinMode(ledRed,OUTPUT);

  // Set outputs to a default value
  digitalWrite(ledYellow,LOW);
  digitalWrite(ledRed,LOW);

  // Begin the serial connection to bluetooth and give it a name
  serialBT.begin("PQSL");
  delay(1000); // Give the system some time to finish stuff up before our main code

  prevPoll = millis(); // Time stamp right now
}

void loop() {
  // Check for a BT command every pollPeriod ms
  if (millis() - prevPoll >= pollPeriod){
    if (serialBT.available()){ // This means we have some data from our BT connection
      cmdBT = serialBT.read();
  
      // If we have a valid BT command, do what it tells us to do
      switch (cmdBT){
        case 'g':
          // Turn all LED's off
          digitalWrite(ledYellow,LOW);
          digitalWrite(ledRed,LOW);
          break;
        case 'y':
          // Turn Yellow LED on
          digitalWrite(ledYellow,HIGH);
          digitalWrite(ledRed,HIGH);
          break;
        case 'r':
          // Turn Red LED on
          digitalWrite(ledYellow,LOW);
          digitalWrite(ledRed,HIGH);
          break;
        default:
          // Default behavior is LED off
          digitalWrite(ledYellow,LOW);
          digitalWrite(ledRed,LOW);
          break;
      }
    }
  }

  
}
