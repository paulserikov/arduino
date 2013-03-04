int buttonPin = 12;

void setup() {
  pinMode(buttonPin, INPUT); 
  digitalWrite(buttonPin, HIGH);    // включаем подтягивающий резистор
  Serial.begin(115200);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  Serial.print(buttonState);
  delay(1000);
}
