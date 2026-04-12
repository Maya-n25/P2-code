#include <Servo.h>

// SERVOS
Servo redServo;    
Servo spinServo;   
Servo red2Servo;   
Servo wolfServo;   
Servo finalServo;  

const int halfSpinTime = 450; 

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
}

void loop() {

  // -------- INTERACTION 1 (180° ONCE) --------
  if (digitalRead(button1) == LOW && !done1) {
    redServo.write(180);
    done1 = true;
  }

  // -------- INTERACTION 2 (HALF SPIN ONCE) --------
  if (digitalRead(button2) == LOW && !spin2 && !done2) {
    spinServo.write(170);   // spin
    t2 = millis();
    spin2 = true;
  }

  if (spin2 && millis() - t2 >= halfSpinTime) {
    spinServo.write(90);    // stop
    spin2 = false;
    done2 = true;
  }

  // -------- INTERACTION 3 (180° ONCE) --------
  if (digitalRead(button3) == LOW && !done3) {
    red2Servo.write(180);
    done3 = true;
  }

  // -------- INTERACTION 4 (HALF SPIN ONCE) --------
  if (digitalRead(button4) == LOW && !spin4 && !done4) {
    wolfServo.write(170);  
    t4 = millis();
    spin4 = true;
  }

  if (spin4 && millis() - t4 >= halfSpinTime) {
    wolfServo.write(90);   // stop
    spin4 = false;
    done4 = true;
  }

  // -------- INTERACTION 5 (HALF SPIN ONCE) --------
  if (digitalRead(button5) == LOW && !spin5 && !done5) {
    finalServo.write(170);
    t5 = millis();
    spin5 = true;
  }

  if (spin5 && millis() - t5 >= halfSpinTime) {
    finalServo.write(90);
    spin5 = false;
    done5 = true;
  }
}
