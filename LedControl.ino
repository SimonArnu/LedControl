#include <OneButton.h>


// Setup a new OneButton on pin A1.  
OneButton button(A1, true);
int led = 9;           // the pin that the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 1;    // how many points to fade the LED by
int brightnessBackup = 128;
int onOff = 0;

// setup code here, to run once:
void setup() {
  // enable the standard led on pin 13.
  pinMode(13, OUTPUT);      // sets the digital pin as output

  // link the doubleclick function to be called on a doubleclick event.   
  button.attachClick(singleClick);
  button.attachDoubleClick(doubleclick);
  button.attachDuringLongPress(longPress);
  Serial.begin(9600);
  Serial.print("start");  
  pinMode(led, OUTPUT);
} // setup


// main code here, to run repeatedly: 
void loop() {
  // keep watching the push button:
  button.tick();
  analogWrite(led, brightness);
  // You can implement other code in here or just wait a while 
  delay(10);
} // loop

//
void singleClick(){
  if (onOff == 0){
    Serial.print("switching on");
    Serial.print(brightness);
    Serial.print("\n");  
    brightness = brightnessBackup;
    fadeAmount = 1;
    onOff = 1;
  }
  else {
    Serial.print("switching off:");  
    Serial.print(brightness);
    Serial.print("\n");
    brightnessBackup = brightness;
    brightness = 0;
    onOff = 0;
  }
  
}

// this function will be called when the button was pressed 2 times in a short timeframe.
void doubleclick() {
  static int m = LOW;
  // reverse the LED 
  m = !m;
  digitalWrite(13, m);
  Serial.print("doubleclick");  
} // doubleclick


// this function will be called when the button was pressed 2 times in a short timeframe.
void longPress() {
  //static int m = LOW;
  // reverse the LED 
  //m = !m;
  //digitalWrite(13, m);
  //Serial.print("longPress\n");  
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
    Serial.print("Reverse:");
    Serial.print(brightness);
    Serial.print("\n");
  }
} // doubleclick

