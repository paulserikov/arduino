int ledpin = 7;
int delay1 = 1000;

void setup() {               
  pinMode(ledpin, OUTPUT);   
}
 
void loop() {
  digitalWrite(ledpin, HIGH);   // зажигаем светодиод
  delay(delay1);              // ждем секунду
  digitalWrite(ledpin, LOW);    // выключаем светодиод
  delay(delay1);              // ждем секунду
}

