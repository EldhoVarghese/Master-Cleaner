
const int FrontS=3;
const int LeftS=4;
const int RightS=5;
const int PIR=6;
const int FS=7;

const int MotorP=8;
const int MotorN=9;
const int DMotorP=10;
const int DMotorN=11;
const int Buzzer=12;
#include <avr/sleep.h>
int SelectW=0;
void setup()
{
  pinMode(FrontS, INPUT);
  pinMode(LeftS, INPUT);
  pinMode(RightS, INPUT);
  pinMode(PIR,INPUT);

  pinMode(FS,OUTPUT);
  pinMode(MotorP, OUTPUT);
  pinMode(MotorN, OUTPUT);
  pinMode(DMotorP, OUTPUT);
  pinMode(DMotorN, OUTPUT);
  pinMode(Buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  long duration, cm;
  digitalWrite(FS, LOW);
  delayMicroseconds(2);
  digitalWrite(FS, HIGH);
  delayMicroseconds(5);
  digitalWrite(FS, LOW);
  digitalRead(FrontS);
  duration = pulseIn(FrontS, HIGH);
  cm = microsecondsToCentimeters(duration);
  delay(100);
  digitalRead(LeftS);
  digitalRead(RightS);
  digitalRead(PIR);
  if(digitalRead(PIR)==HIGH){
    digitalWrite(Buzzer,HIGH);
    halt();
  }
  if((digitalRead(cm)==20) & (digitalRead(LeftS)==HIGH) & (digitalRead(RightS))==HIGH)
  {
    forward();
  }
  else if(digitalRead(cm)==20)
  {
    if(SelectW==0)
    {
      SelectpathR();
      SelectW==1;
    }
    else
    {
      SelectpathL();
      SelectW==0;
    }
  }
  else
if(digitalRead(LeftS)==LOW)
{
  leftEdge();
}
else
if(digitalRead(RightS)==LOW)
{
  rightEdge();
}
else
if((digitalRead(cm)==20) & (digitalRead(LeftS)==LOW) & (digitalRead(RightS)==LOW))
  {
    SelectpathR();
  }
  else
  if((digitalRead(cm)==20) & (digitalRead(LeftS)==LOW))
  {
    SelectpathR();
  }
  else
  if((digitalRead(cm)==20) & (digitalRead(RightS)==LOW))
  {
    SelectpathL();
  }
  else
  if((digitalRead(LeftS)==LOW) & (digitalRead(LeftS)==LOW))
  {
    SelectpathR();
  }
}
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
void forward()
{
  digitalWrite(MotorP,HIGH);
  digitalWrite(MotorN,LOW);
  delay(5);
  return;
}
void backward()
{
  digitalWrite(MotorP,LOW);
  digitalWrite(MotorN,HIGH);
  delay(5000);
  halt();
  return;
}
void halt()
{
  digitalWrite(MotorP,LOW);
  digitalWrite(MotorN,LOW);
  delay(10);
  return;
}
void SelectpathR()
{
  halt();
  backward();
  R180RSafely();
  halt();
  return;
}
void SelectpathL()
{
  halt();
  backward();
  R180LSafely();
  halt();
  return;
}
void leftEdge()
{
  halt();
  turnright();
  halt();
  return;
}
void rightEdge()
{
  halt();
  turnleft();
  halt();
  return;
}
void R180R()
{
  digitalWrite(DMotorP,HIGH);
  digitalWrite(DMotorN,LOW);
  digitalWrite(MotorP,HIGH);
  digitalWrite(MotorN,LOW);
  delay(1000);
  return;
}
void R180L()
{
  digitalWrite(DMotorP,LOW);
  digitalWrite(DMotorN,HIGH);
  digitalWrite(MotorP,HIGH);
  digitalWrite(MotorN,LOW);
  delay(1000);
  return;
}
void R180RSafely()
{
  R180R();
  if(digitalRead(LeftS)==LOW)
  {
  SelectpathL();
  }
  if((digitalRead(LeftS))==LOW & (digitalRead(RightS))==LOW)
  {
  turnleft();
  turnleft();
  turnleft();
  turnleft();
  backtoSP();
  }
   if(digitalRead(LeftS)==LOW)
  {
  SelectpathL();
  }
  if((digitalRead(LeftS))==LOW & (digitalRead(RightS))==LOW)
  {
  turnleft();
  turnleft();
  turnleft();
  turnleft();
  backtoSP();
  }
  if(digitalRead(LeftS)==LOW)
  {
  SelectpathL();
  }
  if((digitalRead(LeftS))==LOW & (digitalRead(RightS))==LOW)
  {
  turnleft();
  turnleft();
  turnleft();
  turnleft();
  backtoSP();
  }
   if(digitalRead(LeftS)==LOW)
  {
  SelectpathL();
  }
  if((digitalRead(LeftS))==LOW & (digitalRead(RightS))==LOW)
  {
  turnleft();
  turnleft();
  turnleft();
  turnleft();
  backtoSP();
  }
  return;
}
void R180LSafely()
{
  R180L();
  if(digitalRead(RightS)==LOW)
  {
  SelectpathR();
  }
  if((digitalRead(LeftS))==LOW & (digitalRead(RightS))==LOW)
  {
  turnright();
  turnright();
  turnright();
  turnright();
  backtoSP();
  }
  if(digitalRead(RightS)==LOW)
  {
  SelectpathR();
  }
  if((digitalRead(LeftS))==LOW & (digitalRead(RightS))==LOW)
  {
  turnright();
  turnright();
  turnright();
  turnright();
  backtoSP();
  }
  if(digitalRead(RightS)==LOW)
  {
  SelectpathR();
  }
  if((digitalRead(LeftS))==LOW & (digitalRead(RightS))==LOW)
  {
  turnright();
  turnright();
  turnright();
  turnright();
  backtoSP();
  }
  if(digitalRead(RightS)==LOW)
  {
  SelectpathR();
  }
  if((digitalRead(LeftS))==LOW & (digitalRead(RightS))==LOW)
  {
  turnright();
  turnright();
  turnright();
  turnright();
  backtoSP();
  }
  return;
}
void turnright()
{
  digitalWrite(DMotorP,HIGH);
  digitalWrite(DMotorN,LOW);
  digitalWrite(MotorP,HIGH);
  digitalWrite(MotorN,LOW);
  delay(500);
  return;
}
void turnleft()
{
  digitalWrite(DMotorP,LOW);
  digitalWrite(DMotorN,HIGH);
  digitalWrite(MotorP,HIGH);
  digitalWrite(MotorN,LOW);
  delay(500);
  return;
}
void backtoSP()
{
  forward();
  if(((digitalRead(LeftS)==LOW & (digitalRead(RightS)==LOW)) or (digitalRead(LeftS)==LOW) or (digitalRead(RightS))==LOW))
  backtoSP();
  return;
}
