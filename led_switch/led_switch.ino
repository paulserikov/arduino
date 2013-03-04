// простой выключатель на Arduino.
// по нажатии кнопки включает/выключает светодиод

#include <Timer.h>
Timer t;
Timer t;
int a=0;  // счетчик продолжительности нажатия
int ms=20;  //минимальная продолжительность нажатия
int buttonPin = 7;
int ledPin = 2;

void setup() {               
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(buttonPin, HIGH);    // включаем подтягивающий резистор       
  t.every(1, check_button);         // проверяем кнопку каждую миллисекунду
}

void check_button() {
  int buttonState = digitalRead(buttonPin);
  if (buttonState == 0) {
     a++;
  } else {
    if (a>=ms) {
      digitalWrite(ledPin, digitalRead(ledPin) == HIGH ? LOW : HIGH);  //тернарный оператор  
    }
    a=0;
  }      //функция изменения состояния порта
}

void loop() {
    t.update();
}
