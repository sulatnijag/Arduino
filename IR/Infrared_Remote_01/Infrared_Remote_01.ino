/*  Infrared Remote Controller & IR Receiver demo program
  copy right John Yu
  connect VS1838B to  D10 see http://osoyoo.com/?p=144
*/
#include <IRremote.h>


//DS - Serial data input
int dataPin = 8;
//ST_CP - Storage register clock pin (latch pin) or Output Clock
int latchPin = 9;
//SH_CP - Shift register clock pin or Input Clock
int clockPin = 10;




byte registers[] = {
  B00000000,
  B10000000, 
  B11000000, 
  B11100000, 
  B11110000, 
  B11111000, 
  B11111100, 
  B11111110, 
  B11111111
  };

byte relay = B11111111;
  

int ctr = 0;
boolean isIncrement = true;

//set D2 as input signal pin
int input_pin = 2; 
IRrecv irrecv(input_pin);
decode_results signals;

int relayPin = 3;

void setup()
{
  
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  
  pinMode(relayPin, OUTPUT);
  
  Serial.begin(9600);
  irrecv.enableIRIn(); // enable input from IR receiver
}

void sendBit(byte byteData){
   digitalWrite(latchPin, LOW);
    
    // shift out the bits:
    shiftOut(dataPin, clockPin, MSBFIRST, byteData);  
    
    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
}


void toggle(int n){
  Serial.println(relay, BIN);
  relay ^= 1UL << n;
  Serial.println(relay, BIN);
  sendBit(relay);
}

void loop() {
  
  if (irrecv.decode(&signals)) {
    //Serial.println("------");
    //Serial.println(signals.value, HEX);
    irrecv.resume(); // get the next signal

  
    
    switch(signals.value){
      case 0xFF6897:
        Serial.println("0");
        relay = B11111111;
        sendBit(relay);
        break;
      case 0xFF30CF:
        Serial.println("1");
        toggle(0);
        //sendBit(B01110000);
        break;
      case 0xFF18E7:
        Serial.println("2");
        toggle(1);
        //sendBit(B10110000);
        break;
      case 0xFF7A85:
        Serial.println("3");
        toggle(2);
        //sendBit(B11010000);
        break;
      case 0xFF10EF:
        Serial.println("4");
        toggle(3);
        //sendBit(B11100000);
        break;
    
    }

  }
/*
   Serial.println("All OFF");
    sendBit(registers[0]);
    delay(1000);

    Serial.println("All ON");
    sendBit(registers[8]);
    delay(1000);
*/
  /*
  Serial.println("HIGH");
  digitalWrite(relayPin, HIGH);
  delay(5000);
  Serial.println("LOW");
  digitalWrite(relayPin, LOW);
  delay(5000);
  */

  /*
  if(isIncrement){

    // take the latchPin low so 
    // the LEDs don't change while you're sending in bits:
    digitalWrite(latchPin, LOW);
    
    // shift out the bits:
    shiftOut(dataPin, clockPin, LSBFIRST, registers[ctr]);  
    
    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
    // pause before next value:
    delay(1000);
    
    ctr++;

    if(ctr >= 8) {
      isIncrement = false;
    }
  } else {
        // take the latchPin low so 
    // the LEDs don't change while you're sending in bits:
    digitalWrite(latchPin, LOW);
    
    // shift out the bits:
    shiftOut(dataPin, clockPin, LSBFIRST, registers[ctr]);  
    
    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
    // pause before next value:
    delay(1000);
    
    ctr--;

    if(ctr == 0) {
      isIncrement = true;
    }
  }*/
  

}
