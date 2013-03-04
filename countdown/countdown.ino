#include <Event.h>
#include <Timer.h>
#define ORDER LSBFIRST

int segdisp[10] = {3,159,37,13,153,73,65,27,1,9};
int latch = 24;                                   // номер RCK pin ("защелка")
int clock = 26;                                   //номер SCK pin ("такт")
int data = 22;                                    //номер DIO pin (данные последовательно)
int minutes = 1;                                 //отсчет в минутах
volatile int secs = minutes*60;
Timer t;

void setup() {               
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);  
  pinMode(data, OUTPUT);              
  t.every(1000, time_update);
}

void loop() {
    show_num();
    t.update(); 
}

void time_update() {
  if (secs > 0) secs -= 1;
}

void show_num() {
String myStr = String(secs); 
int b = myStr.length();
int a [b];
for (int i=0;i<b;i++)
  { 
  digitalWrite(latch,LOW);
  shiftOut(data,clock,ORDER,1<<i);
  int c = myStr.charAt(b-i-1);
  shiftOut(data,clock,ORDER,segdisp[c - '0']);
  digitalWrite(latch,HIGH);
  }
}
