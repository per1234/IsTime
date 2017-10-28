#include <IsTime.h>

#define SECOND 1000000

IsTime isTime;

void setup() {
  Serial.begin(115200);

  isTime = IsTime();
  isTime.add("event", SECOND * 10);
}

void loop() {
  if (isTime.isOver("event")) {
    Serial.println("Gotcha!");
  }
}
