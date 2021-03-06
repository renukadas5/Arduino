#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);

int r1 = 5;
int r2 = 6;
int l1 = 7;
int l2 = 8;
int a1 = 10;
int a2 = 11;
int g1 = 12;
int g2 = 13;

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

}

char d;

void loop()
{
  Serial.begin(9600);
  if (mySerial.available())
  {
    d = mySerial.read();
    digitalWrite(13, HIGH);
  }

  switch (d)
  {

    case 'F' :
      front();
      break;
    case 'B' :
      back();
      break;
    case 'L' :
      left();
      break;
    case 'R' :
      right();
      break;
    case 'W' :
      armup();
      break;
    case 'U' :
      armdown();
      break;
    case 'V' :
       grappleopen();
       break;
    case 'X' :
       grappleclose();
       break;        
    default :
      stopall();
      break;

  }

}
void back() {
  digitalWrite(r1, HIGH);
  digitalWrite(r2, LOW);
  digitalWrite(l1, HIGH);
  digitalWrite(l2, LOW);
}
void front() {
  digitalWrite(r1, LOW);
  digitalWrite(r2, HIGH);
  digitalWrite(l1, LOW);
  digitalWrite(l2, HIGH);
} void right() {
  digitalWrite(r1, HIGH);
  digitalWrite(r2, LOW);
  digitalWrite(l1, LOW);
  digitalWrite(l2, HIGH);
} void left() {
  digitalWrite(r1, LOW);
  digitalWrite(r2, HIGH);
  digitalWrite(l1, HIGH);
  digitalWrite(l2, LOW);
}
void stopall()
{
  digitalWrite(r1, LOW);
  digitalWrite(r2, LOW);
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(g1, LOW);
  digitalWrite(g2, LOW);
}
void armup()
{
   digitalWrite(a1, HIGH);
   digitalWrite(a2, LOW);
}
void armdown()
{
   digitalWrite(a1, LOW);
   digitalWrite(a2, HIGH);
}
void grappleopen()
{
   digitalWrite(g1, HIGH);
   digitalWrite(g2, LOW);
}
void grappleclose()
{
   digitalWrite(g1, LOW);
   digitalWrite(g2, HIGH); 
}

