#include <Adafruit_NeoPixel.h>
int photoPin = A2;

int photoValue = 0;

int outputValue = 0;

int sensorPin = A0;    
int ledPin = 8;      
int sensorValue = 0;

const int buttonPin = 10;
const int ledPin2 =  2;
int buttonState = 0;
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif


#define PIN            8
#define PIN2            2


#define NUMPIXELS      3
#define NUMPIXELS2     2


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);



Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);


void setup() {
  pinMode(PIN, OUTPUT);
  pinMode(photoPin, INPUT);
  Serial.begin(9600);


  pixels.begin(); 
  pixels.setBrightness(255);

  pinMode(PIN2, OUTPUT);
  pinMode(photoPin, INPUT);
  Serial.begin(9600);


  pixels2.begin(); 
  pixels2.setBrightness(255);


  pinMode(ledPin, OUTPUT);

  
  pinMode(ledPin2, OUTPUT);
 
  pinMode(buttonPin, INPUT);

}

void loop() {

  photoValue = analogRead(photoPin);
  sensorValue = analogRead(sensorPin);
  outputValue = map(photoValue, 0, 1023, 0, 255);
  //analogWrite(PIN, outputValue);

 // Serial.println(photoValue);
  pixels.setBrightness(outputValue);
  for (int i = 0; i < NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(255, 255, 255));
    pixels.show(); 

  }
buttonState = digitalRead(buttonPin);
 if (buttonState == HIGH) {
  digitalWrite(ledPin2,HIGH);
 
  Serial.println(photoValue);

  for (int i = 0; i < NUMPIXELS2; i++) {

    pixels2.setPixelColor(i, pixels2.Color(255, 0, 0));
    pixels2.show();
  }
 }
  else 
  { 
    digitalWrite(ledPin2, LOW);
 Serial.println(photoValue);

  for (int i = 0; i < NUMPIXELS2; i++) {

    pixels2.setPixelColor(i, pixels2.Color(0, 0, 0));
    pixels2.show();
  }
    
  }
}
