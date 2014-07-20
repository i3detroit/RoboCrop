#include <Servo.h>

#define STOPSPEED 90
#define LEFTSPEED  (STOPSPEED + 25)
#define RIGHTSPEED (STOPSPEED - 25) 

Servo yawMotor;
int motorSpeed;
int yawTime;


void setup()
{
  // motor shield pins
  pinMode(12, OUTPUT); // dir A
  pinMode(3,  OUTPUT); // pwm A
  pinMode(9,  OUTPUT); // brake A
  pinMode(13, OUTPUT); // dir B
  pinMode(11,  OUTPUT); // pwm B
  pinMode(8,  OUTPUT); // brake B
  
  
  
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  
  pinMode(A4, INPUT_PULLUP); // arms actuate
  pinMode(A5, INPUT_PULLUP); // shoot water
  
  pinMode(2, INPUT_PULLUP); // limit switch
  pinMode(4, INPUT_PULLUP); // auto/manal
  
  pinMode(7, INPUT_PULLUP); // PIR right
  pinMode(10, INPUT_PULLUP); // PIR right

  analogWrite(3, 255);
  digitalWrite(12, 1);
   analogWrite(11, 255);
  digitalWrite(13, 1);
 
  
  yawMotor.attach(5);
  yawMotor.write(STOPSPEED);
  
  Serial.begin(9600);
  
}



void loop()
{
  Serial.print(" ");
  Serial.print(digitalRead(A2));
  Serial.print(digitalRead(A3));
  Serial.print(digitalRead(A4));
  Serial.print(digitalRead(A5));
  Serial.print(" ");
  Serial.print(digitalRead(2)); // limit switch
  Serial.print(" ");
  Serial.print(digitalRead(4)); // auto/manual
  Serial.print("  "); // D5 D6
  Serial.print(digitalRead(7)); // PIR left
  Serial.print("  "); // D8 D9
  Serial.print(digitalRead(10)); // PIR right
  Serial.println();
 
  
  if(digitalRead(2) == HIGH)
  {
    yawMotor.write(STOPSPEED); 
  }
  else if(digitalRead(A2) == LOW)
  {
    yawMotor.write(LEFTSPEED);
  }
  else if(digitalRead(A3) == LOW)
  {
    yawMotor.write(RIGHTSPEED);
  }
  else
  {
    yawMotor.write(STOPSPEED);
  }
  
  
  
  
 
  if(digitalRead(A4))
  {
    setValve(0);
  }
  else
  {
    setValve(1); 
  } 

  if(digitalRead(A5))
  {
    setWaterValve(0);
  }
  else
  {
    setWaterValve(1); 
  } 
  
  
}


void setValve(int state)
{
  if(state)
  {
    digitalWrite(9, 0);
  }
  else
  {
    digitalWrite(9, 1);
  }
}

void setWaterValve(int state)
{
  if(state)
  {
    digitalWrite(8, 0);
  }
  else
  {
    digitalWrite(8, 1);
  }
}
