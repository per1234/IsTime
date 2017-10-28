# IsTime

Библиотека Arduino для определения времени наступления события.

# Использование

```c++
#include <IsTime.h>

#define SECOND 1000000

IsTime isTime;

void setup() {
  Serial.begin(115200);

  isTime = IsTime();
  isTime.add("event", SECOND * 10);
}

void loop() {
  if (isTime.over("event")) {
    Serial.println("Gotcha!");
  }
}
```

# ToDo
- Работать с замыканиями
