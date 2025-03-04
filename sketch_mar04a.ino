#include <Servo.h>

Servo myservo;  // create servo object to control a servo

#define echoPin 7 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 6 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int x = 0;
int pos = 0;  

void setup() {
  // put your setup code here, to run once:
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}


void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
      Serial.print(distance); //prints 

  // Displays the bites on the Serial Monitor
  
  if (distance > 30)//condition if distance is less than 30cm
  {
    x = x + 1; //number of bites
    Serial.print("bite "); //prints 
    Serial.println(x);

    // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(180);              // tell servo to go to position in variable 'pos'
    
    delay(15);       
    delay(2000);
} 

else { 
   // goes from 180 degrees to 0 degrees
    myservo.write(0);              // tell servo to go to position in variable 'pos'
    delay(15);     
  
  
  

} }
