#include <Servo.h>

int A = 0, B = 0, armup = A2, armdown = A3, armclench = A4, armrelease = A5, arm1pos, arm2pos;

int a = 4, b = 5, c = 6, d = 7;

Servo arm1, arm2;

void setup() {

  Serial.begin(9600);

  arm1.attach(8);
  arm2.attach(9);

  pinMode(a, OUTPUT);

  pinMode(b, OUTPUT);

  pinMode(c, OUTPUT);

  pinMode(d, OUTPUT);

  /*pinMode(armup, INPUT_PULLUP);
  
  pinMode(armdown, INPUT_PULLUP);*/

}

void loop() {

  A = analogRead(A0);

  B = analogRead(A1);

  if (A >= 700)

  {

    Serial.println("MF");

    MB();

  }

  if (A <= 300)

  {

    Serial.println("MB");

    MF();

  }

  if (B >= 700)

  {

    Serial.println("MR");

    ML();

  }

  if (B <= 300)

  {

    Serial.println("ML");

    MR();

  }

  if (A >= 450 && A <= 550 && B >= 450 && B <= 550)

  {

    //Serial.println("MS");

    MS();

  }
  Serial.println(analogRead(armup));
  //Serial.println(arm1pos);
  if (analogRead(armup) == HIGH)

  {
    Serial.println("arm is going up");
    arm1.write(arm1pos++);
  }

  if (analogRead(armdown) == HIGH)

  {
    Serial.println("arm is going down");
    arm1.write(arm1pos--);
  }
  if (analogRead(armclench) == HIGH)

  {
    Serial.println("arm clenching");
    arm2.write(++arm2pos);
  }

  if (analogRead(armrelease) == HIGH)

  {
    Serial.println("arm releasing");
    arm2.write(--arm2pos);
  }
}



void MB()

{

  digitalWrite(a, 0);

  digitalWrite(b, 1);

  digitalWrite(c, 0);

  digitalWrite(d, 1);

  delay(10);

}

void MF()

{

  digitalWrite(a, 1);

  digitalWrite(b, 0);

  digitalWrite(c, 1);

  digitalWrite(d, 0);

  delay(10);

}

void ML()

{

  digitalWrite(a, 0);

  digitalWrite(b, 1);

  digitalWrite(c, 1);

  digitalWrite(d, 0);

  delay(10);

}

void MR()

{

  digitalWrite(a, 1);

  digitalWrite(b, 0);

  digitalWrite(c, 0);

  digitalWrite(d, 1);

  delay(10);

}

void MS()

{

  digitalWrite(a, 0);

  digitalWrite(b, 0);

  digitalWrite(c, 0);

  digitalWrite(d, 0);

  delay(10);

}
