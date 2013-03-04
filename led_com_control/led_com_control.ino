// программа зажигает светодиод при передаче в com-порт 1
// в классе serial уже заложено прерывание

int incomingByte = 0;   // for incoming serial data
int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.println(incomingByte);
  }
  if (incomingByte==49)
    {
      digitalWrite(ledPin, HIGH);
    }
   if (incomingByte==48)
    {
      digitalWrite(ledPin, LOW);
    }
}
