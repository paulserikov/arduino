int brightness = 0;    // уставливаем начально значение яркости
int fadeAmount = 5;    // шаг приращения/убывания яркости
int ledpin = 9;       //пин светодиода
int ms=30;           // задержка
 
void setup()  { 
  pinMode(ledpin, OUTPUT);
}
 
void loop()  {
  analogWrite(ledpin, brightness);   
  brightness = brightness + fadeAmount;
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }   
  delay(ms);                           
}

