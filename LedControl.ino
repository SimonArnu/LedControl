#include <OneButton.h>


// Setup a new OneButton on pin A1.  
OneButton button(A1, true);


// setup code here, to run once:
void setup() {
  // enable the standard led on pin 13.
  pinMode(13, OUTPUT);      // sets the digital pin as output

  // link the doubleclick function to be called on a doubleclick event.   
  button.attachDoubleClick(doubleclick);
  button.attachDuringLongPress(longPress);
  Serial.begin(9600);
  Serial.print("start");  
} // setup


// main code here, to run repeatedly: 
void loop() {
  // keep watching the push button:
  button.tick();

  // You can implement other code in here or just wait a while 
  delay(10);
} // loop

//

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
  Serial.print("longPress\n");  
} // doubleclick

