#include <Servo.h>
Servo m1; // create servo object to control a servo
int trigger = 5; 
int echo = 6; // pins of the Ultrasonic sensor
int x = 0; // x is the duration of the pulse
int D = 0; // D is the distance 
void setup() {
  // put your setup code here, to run once:
  m1.attach(3); // attaches the servo on pin 3 to servo object
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);

  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  x= pulseIn(echo, HIGH);
  D = x*0.034/2; // determin the distance in cm
  Serial.print("Distance");
  Serial.println(D); // print the distance in Virtual Terminal
  if (D<300 && D>200){ // range of the small box
    m1.write(135);
  }else if (D<199 && D>100){ // range of the medium box 
    m1.write(90);
  }else if (D<99 && D>0){ // range of the large box
    m1.write(45);
  }
}
