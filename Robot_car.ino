#include <Servo.h>
#include <AFMotor.h>

// Initialization for servo
#define SERVO1_PWM 10      // Define the servo 1 PWM pin
const int TRIGGER_PIN=A0;   // Define the ultrasound sensor trigger pin
const int ECHO_PIN=A1;       // Define the ultrasound sensor echo pin

Servo servo_1;              // Create a servo object for servo 1
const int servoCenter = 55;
const int servoRightPos = 115;
const int servoLeftPos = 5;
unsigned long servo_timer = 0;
unsigned long sonar_timer = 0;
const int step = 1;
float distance;
float left_distance;
float right_distance;
float detection_distance=0.4;
float comparator_distance=1.0;




AF_DCMotor motor1(1);       // Motor 1
AF_DCMotor motor2(2);       // Motor 2
AF_DCMotor motor3(3);       // Motor 3
AF_DCMotor motor4(4);       // Motor 4

void setup() {
  Serial.begin(9600);
  Serial.println("Simple Adafruit Motor Shield sketch");

  pinMode(TRIGGER_PIN, OUTPUT);  // Set the trigger pin as an OUTPUT
  pinMode(ECHO_PIN, INPUT);       // Set the echo pin as an INPUT

  servo_1.attach(SERVO1_PWM);    // Attach servo_1 to its PWM pin
  servo_1.write(servoCenter);    // Move servo_1 to the initial position at servoCenter degrees
  delay(2000);                   // Delay for 2 seconds to allow the servo to reach the initial position

  motor1.setSpeed(255);          // Set motor speed (adjust as needed)
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
}

void loop() {
  

do {
  unsigned long start_timer = millis();
    if (start_timer - sonar_timer >= 60) {  // Check if at least 10 ms have passed
        sonar_and_distance();  // Get a new distance reading
        sonar_timer = start_timer;  // Update the timer with the current time
    }
    motorForward();
    Serial.print("Distance: ");
    Serial.print(distance);
} while (distance > detection_distance || distance == 0);

  motorStop(100);
 

  if (distance <= detection_distance && distance != 0) {

    move_and_scan();

    if (right_distance - left_distance>0.10) {
      unsigned long motor_timer=0;
      
      do {
        unsigned long start_timer = millis();
        motorRight(250);
        if(start_timer-motor_timer>60){
          sonar_and_distance();
          motor_timer=start_timer;
        }
        Serial.print("Distance (Right): ");
        Serial.print(distance);
        Serial.println(" m");
      } while (distance < detection_distance);
    }

    if (left_distance-right_distance>0.10) {
          unsigned long motor_timer=0;
      
      do {
        unsigned long start_timer = millis();
        motorLeft(250);
        if(start_timer-motor_timer>60){
          sonar_and_distance();
          motor_timer=start_timer;
        }
        Serial.print("Distance (Left): ");
        Serial.print(distance);
        Serial.println(" m");
      } while (distance < detection_distance);
    }
    if(left_distance-right_distance<0.10 || right_distance - left_distance<0.10 ){
      motorRight(500);
    }

  }

}

void move_and_scan() {
  servoRight();
  sonar_and_distance();
  right_distance = distance;
  Serial.print("Right Distance: ");
  Serial.print(right_distance);
  Serial.println(" m");

  servoLeft();
  sonar_and_distance();
  left_distance = distance;
  Serial.print("Left Distance: ");
  Serial.print(left_distance);
  Serial.println(" m");
}

void servoRight() {
  servo_1.write(servoCenter);
  for (int angle = servoCenter; angle <= servoRightPos; angle++) {
    servo_1.write(angle);
    delay(2);
  }
  delay(200);

  for (int angle = servoRightPos; angle >= servoCenter; angle--) {
    servo_1.write(angle);
    delay(2);
  }

  delay(200);
}

void servoLeft() {
  for (int angle = servoCenter; angle >= servoLeftPos; angle--) {
    servo_1.write(angle);
    delay(2);
  }

  delay(200);

  for (int angle = servoLeftPos; angle <= servoCenter; angle++) {
    servo_1.write(angle);
    delay(2);
  }

  delay(200);
}

void motorForward() {
  // Test moving all motors forward
  motor1.setSpeed(255);          // Set motor speed (adjust as needed)
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  Serial.println("Moving all motors forward");
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void motorBackward() {
  motor1.setSpeed(255);          // Set motor speed (adjust as needed)
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  // Test moving all motors backward
  Serial.println("Moving all motors backward");
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void motorRight(int d) {
  motor1.setSpeed(255);          // Set motor speed (adjust as needed)
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  // Test moving all motors right (rotate right)
  Serial.println("Moving all motors right (rotate right)");
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
  delay(d);
}

void motorLeft(int d) {
  motor1.setSpeed(255);          // Set motor speed (adjust as needed)
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  // Test moving all motors left (rotate left)
  Serial.println("Moving all motors left (rotate left)");
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
  delay(d);
}

void motorStop(int d) {
  // Stop all motors
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  delay(d);  // Pause for 2 seconds
}

void sonar_and_distance() {
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH, 25000);
  distance = (343 * (duration / 2.0)) / 1000000.0; // Update the global variable
}

void comparator(){
// The program will scan the forward region at a narrow 15degree cone. However, to compare which direction to move, it has to move its head slowly from side to side.
//This movement should not be as drastic as the move_and_scan() function but it should be enough for comparable distance. Or, it could be done in such a way that 
// it will scan infront and move to increase the distance>1.0m
sonar_and_distance();
if





}











