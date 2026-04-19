#include <Servo.h>

Servo s;

bool done = false;

void setup() {
  s.attach(8);
}

void loop() {

  if (!done) {

    s.write(0);
    delay(1000);

    s.write(180);
    delay(1000);

    done = true; // freeze after first run
  }

}