// C++ code
// BME 261 Motor Workshop

// Define Servo Library
 #include <Servo.h>

 // Define Servo Motors
 Servo myservo1;
 Servo myservo2;

 // Define Variable for Positional Rotation
 int num1 = 0;

 // Define Variables for Continuous Rotation
 int num2 = 93;
 int temp = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  // === Setup Code for Part 1 (a) === //
  myservo1.attach(11); //configure digital pin 11 to control the servo
  myservo1.write(0);
  
  // === Setup Code for Part 1 (b) === //
  myservo2.attach(9); //configure digital pin 9 to control the servo
  myservo2.write(93);
}

void posServo(){
  
  // Read Serial Input Values (default 0)
  num1 = Serial.parseInt();
  // Print Serial Input Values
  Serial.println(num1); 
  
  // Rotate Motor to Input Degree
  myservo1.write(num1);
  delay(15);
}

void rotServo(){
  
  // Read Serial Input Values (default 0)
  num2 = Serial.parseInt();
  // Print Serial Input Values
  Serial.println(num2); 
  
  // Check if the Input is 0 (rest state)
  if(num2 == 0){
    myservo2.write(93);
    delay(1500);
  }
  
  // Check if the Input is non-0 (rotating)
  else{
    // If Input is -100 to <0, CCW rotation
    if(num2 < 0){
    temp = 90 - num2*0.9;
    myservo2.write(temp);
    delay(1000);
    }
    // If input is >0 to 100, CW rotation
    if(num2 > 0){
    temp = 90 - num2*0.9;
    myservo2.write(temp);
    delay(1000);
    }
  }
}

void loop() {
  //posServo(); //For Position Servo
  rotServo(); //For Continuous Rotation Servo
  delay(5);
}
