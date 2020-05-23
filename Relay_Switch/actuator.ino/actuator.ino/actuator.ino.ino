/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to set pin numbers:
const int BTNUP1 = 2;     // the number of the pushbutton pin
const int BTNDOWN1 = 3;
const int BTNUP2 = 4; 
const int BTNDOWN2 = 5;


const int RELAY01 =  13;      // the number of the LED pin
const int RELAY02 =  12;
const int RELAY03 =  11;      // the number of the LED pin
const int RELAY04 =  10;


// variables will change:
int buttonUPState1 = 0;         // variable for reading the pushbutton status
int buttonDOWNState1 = 0;
int buttonUPState2 = 0;         // variable for reading the pushbutton status
int buttonDOWNState2 = 0;


void setup() {
  // initialize the LED pin as an output:
  pinMode(RELAY01, OUTPUT);
  pinMode(RELAY02, OUTPUT);
  pinMode(RELAY03, OUTPUT);
  pinMode(RELAY04, OUTPUT);

  // keep the relays OFF
  digitalWrite(RELAY01, HIGH);
  digitalWrite(RELAY02, HIGH);
  digitalWrite(RELAY03, HIGH);
  digitalWrite(RELAY04, HIGH);
  
  // initialize the pushbutton pin as an input:
  pinMode(BTNUP1, INPUT);
  pinMode(BTNDOWN1, INPUT);
  pinMode(BTNUP2, INPUT);
  pinMode(BTNDOWN2, INPUT);

  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonUPState1 = digitalRead(BTNUP1);
  buttonDOWNState1 = digitalRead(BTNDOWN1);
  buttonUPState2 = digitalRead(BTNUP2);
  buttonDOWNState2 = digitalRead(BTNDOWN2);

  Serial.println(buttonUPState1); 
  Serial.println(buttonDOWNState1); 

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonUPState1 == HIGH) {
    // turn LED on:
    //digitalWrite(ledPin, HIGH);
    //Relay switch is low trigger, meaning the relat is turned on when driven LOW
    digitalWrite(RELAY01, LOW);
  } else {
    // turn LED off:
    //digitalWrite(ledPin, LOW);
    digitalWrite(RELAY01, HIGH);
  }

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonDOWNState1 == HIGH) {
    // turn LED on:
    //digitalWrite(ledPin, HIGH);
    //Relay switch is low trigger, meaning the relat is turned on when driven LOW
    digitalWrite(RELAY02, LOW);
  } else {
    // turn LED off:
    //digitalWrite(ledPin, LOW);
    digitalWrite(RELAY02, HIGH);
  }


  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonUPState2 == HIGH) {
    // turn LED on:
    //digitalWrite(ledPin, HIGH);
    //Relay switch is low trigger, meaning the relat is turned on when driven LOW
    digitalWrite(RELAY03, LOW);
  } else {
    // turn LED off:
    //digitalWrite(ledPin, LOW);
    digitalWrite(RELAY03, HIGH);
  }

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonDOWNState2 == HIGH) {
    // turn LED on:
    //digitalWrite(ledPin, HIGH);
    //Relay switch is low trigger, meaning the relat is turned on when driven LOW
    digitalWrite(RELAY04, LOW);
  } else {
    // turn LED off:
    //digitalWrite(ledPin, LOW);
    digitalWrite(RELAY04, HIGH);
  }
  
  
}
