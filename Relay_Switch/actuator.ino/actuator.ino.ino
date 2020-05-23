int latchPin = 12;  //RCLK
int clockPin = 11;  //SRCLK
int dataPin = 13;   //SER
/*
byte leds = 0;
int currentLED = 0;
*/
const int pResistor = A0; // Photoresistor at Arduino analog pin A0
const int pBuzzer = 9;

byte zero = B11111100;
byte one = B10000101;
byte two = B11011010;
byte three = B01111010;
byte four = B00110110;
byte five = B01101110;
byte six = B11101110;
byte seven = B00111000;
byte eight = B11111110;
byte nine = B01111110;
byte A = B10111110;
byte C = B11001100;

int lightValue = 0;
  

/*
byte one = 0b00010010;
byte two = 0b01100111;
byte three = 0b01110110;
*/
byte numbers[] = {zero, one, two, three, four, five, six, seven, eight, nine};

void setup()
{
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(pResistor, INPUT);
    pinMode(pBuzzer, OUTPUT);

    Serial.begin(9600);

}

void loop()
{
  
    
    Serial.println(analogRead(pResistor)); //Write the value of the photoresistor to the serial monitor.
    lightValue = analogRead(pResistor);
    
    lightValue = lightValue - 1000;
    

    if(lightValue > 9 || lightValue < 0){
      lightValue = 0;
    }
    digitalWrite(pBuzzer, HIGH);
    delay(1);
    digitalWrite(pBuzzer, LOW);
    
    digitalWrite(latchPin, LOW);  // prepare shift register for data
    shiftOut(dataPin, clockPin, LSBFIRST, numbers[lightValue]); // send data

    
    digitalWrite(latchPin, HIGH); // update display
    delay(1000);
    
  
  /*
    digitalWrite(latchPin, LOW);  // prepare shift register for data
  shiftOut(dataPin, clockPin, LSBFIRST, C); // send data
  digitalWrite(latchPin, HIGH); // update display
  delay(1000);
  */
  
    
}
