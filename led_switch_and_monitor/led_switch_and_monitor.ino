// простой выключатель на Arduino.
// по нажатии кнопки включает/выключает светодиод
// идея - реализовать то же, но на прерываниях
// прерывание по сути вставляет вызов функции
// большинство систем событийно-ориентировано


#include <Timer.h>
Timer t;
Timer b;
int a=0;  // счетчик продолжительности нажатия
int ms=20;  //минимальная продолжительность нажатия
int buttonPin = 7;
int ledPin = 2;

void setup() {               
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(buttonPin, HIGH);    // включаем подтягивающий резистор
  Serial.begin(9600);  
  t.every(1, check_button);         // проверяем кнопку каждую миллисекунду
  b.every(1000, info_led);
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

void info_led() {
  int ledState = digitalRead(ledPin);
  Serial.print("LED is: ");
  if (ledState == HIGH)
  {
    Serial.print("ON");
  }
  else 
  {
    Serial.print("OFF");
  }
  Serial.println();
}

void loop() {
    t.update();
    b.update();
}
