#include <Servo.h>

// SERVOS
Servo redServo;    
Servo spinServo;   
Servo red2Servo;   
Servo wolfServo;   
Servo finalServo;  

const int halfSpinTime = 300; 
const int wolfSpinTime = 360;
const int finalSpinTime = 1200;

// TIMERS
unsigned long t2 = 0;
unsigned long t4 = 0;
unsigned long t5 = 0;

// STATES
bool spin2 = false;
bool spin4 = false;
bool spin5 = false;

bool done1 = false;
bool done2 = false;
bool done3 = false;
bool done4 = false;
bool done5 = false;

// BUTTONS
int button1 = 2;
int button2 = 3;
int button3 = 7;
int button4 = 5;
int button5 = 6;

void setup() {
  redServo.attach(9);
  spinServo.attach(10);
  red2Servo.attach(11);
  wolfServo.attach(12);
  finalServo.attach(8);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);

  // starting positions for 180 servos
  redServo.write(180);
  red2Servo.write(0);

  // stop continuous servos
  spinServo.write(10);
  wolfServo.write(10);

  delay (450);
  
  spinServo.write(90);
  wolfServo.write(90);
  finalServo.write(90);
}

void loop() {

  // -------- INTERACTION 1 (SMOOTH 180° ONCE) --------
  if (digitalRead(button1) == LOW && !done1) {
    for (int pos = 180; pos >= 0; pos -= 5) {
      redServo.write(pos);
      delay(15);
    }
    done1 = true;
  }

  // -------- INTERACTION 2 (HALF SPIN ONCE) --------
  if (digitalRead(button2) == LOW && !spin2 && !done2) {
    spinServo.write(10);
    t2 = millis();
    spin2 = true;
  }

  if (spin2 && millis() - t2 >= halfSpinTime) {
    spinServo.write(90);
    spin2 = false;
    done2 = true;
  }

  // -------- INTERACTION 3 (SMOOTH 180° ONCE) --------
  if (digitalRead(button3) == LOW && !done3) {
    for (int pos = 0; pos <= 180; pos += 5) {
      red2Servo.write(pos);
      delay(15);
    }
    done3 = true;
  }

  // -------- INTERACTION 4 (HALF SPIN ONCE) --------
  if (digitalRead(button4) == LOW && !spin4 && !done4) {
    wolfServo.write(10);
    t4 = millis();
    spin4 = true;
  }

  if (spin4 && millis() - t4 >= wolfSpinTime) {
    wolfServo.write(90);
    spin4 = false;
    done4 = true;
  }

  // -------- INTERACTION 5 (HALF SPIN ONCE) --------
  if (digitalRead(button5) == LOW && !spin5 && !done5) {
    finalServo.write(170);
    t5 = millis();
    spin5 = true;
  }

  if (spin5 && millis() - t5 >= finalSpinTime) {
    finalServo.write(180);
    spin5 = false;
    done5 = true;
  }
}
