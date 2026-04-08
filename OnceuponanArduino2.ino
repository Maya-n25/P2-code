
#include <Servo.h>

Servo redServo;    // 180°
Servo spinServo;   // 360°

int button1 = 2;   // copper loop for 180 servo
int button2 = 3;   // copper loop for 360 servo

void setup() {
  redServo.attach(9);
  spinServo.attach(10);

  pinMode(button1, INPUT_PULLUP); // 180° servo keeps using pullup
  pinMode(button2, INPUT);        // 360° servo now uses plain input
}

void loop() {

  // 180° SERVO (pull-up logic)
  if (digitalRead(button1) == LOW) {   // loop closed
    redServo.write(180);
  } else {
    redServo.write(0);
  }


// interaction two

  // 360° SERVO (pull-down logic)
  if (digitalRead(button2) == HIGH) {   // loop closed
    spinServo.write(170);  // spin (adjust 150-180 as needed)
  } else {
    spinServo.write(90);   // stop
  }
}