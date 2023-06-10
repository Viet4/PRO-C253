#include <ezButton.h>

const int button1 = 4;
const int button2 = 22;
int count = 0;

ezButton push_button1(button1);
ezButton push_button2(button2);

void setup() {
  Serial.begin(115200);

  push_button1.setDebounceTime(40);
  push_button2.setDebounceTime(40);
}

void loop() {
  push_button1.loop();
  push_button2.loop();

  if (push_button1.isPressed()) {
    count+=1;
    Serial.println("Number : "+String(count));
  }
  else if (push_button2.isPressed()) {
    Serial.println("Table of " + String(count));
    for (int i = 1; i<=10; i++) {
      if (i<10) {
        Serial.println(String(count) + "*" + String(i) + "     =     " + String(count*i));
      }
      else {
        Serial.println(String(count) + "*" + String(i) + "    =     " + String(count*i));
      }
    }
    count = 0;
  }
 
}
