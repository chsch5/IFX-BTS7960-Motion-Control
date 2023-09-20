#include <BTS7960.h>

int pwmSET = 130; //PWM intensity setting


void setup() 
{

  // Initialize motor pins as OUTPUT
  pinMode(47, OUTPUT); //RPWM_RS
  pinMode(49, OUTPUT); //LPWM_RS
  pinMode(51, OUTPUT); //REN_RS
  pinMode(53, OUTPUT); //LEN_RS
  pinMode(46, OUTPUT); //RPWM_LS
  pinMode(48, OUTPUT); //LPWM_LS
  pinMode(50, OUTPUT); //REN_LS
  pinMode(52, OUTPUT); //LEN_LS

  // Make sure both motor drivers are initially off
  digitalWrite(47, LOW);
  digitalWrite(49, LOW);
  digitalWrite(51, LOW);
  digitalWrite(53, LOW);
  digitalWrite(46, LOW);
  digitalWrite(48, LOW);
  digitalWrite(50, LOW);
  digitalWrite(52, LOW);

  delay(1000);
  Serial.begin(9600);
}

void loop()
{
  //FWD Drive
  xDrive(1, 1);
  xDrive(2, -1);
  delay(2000);


  //BACK DRIVE
  xDrive(1, -1);
  xDrive(2, 1);
  delay(2000);

  //CW DRIVE
  xDrive(1, 1);
  xDrive(2, 1);
  delay(2000);

  //CW DRIVE
  xDrive(1, -1);
  xDrive(2, -1);
  delay(2000);  
}


void xDrive(int side, int direction)
//xDrive Drives a both sides motors depending on the instantiation of the function
{
  switch(side)
  {
    case 1: //CASE 1: RS Motion
      if (direction == 1)
      {
        movementConfig(47, 49, 51, 53, 1);
      }
      else if (direction == -1)
      {
        movementConfig(47, 49, 51, 53, -1);
      }
      else 
      {
        movementConfig(47, 49, 51, 53, 0);
      }
      break;
      
      case 2: //CASE 2: LS Motion
      if (direction == 1)
      {
        movementConfig(46, 48, 50, 52, 1);
      }
      else if (direction == -1)
      {
        movementConfig(46, 48, 50, 52, -1);
      }
      else 
      {
        movementConfig(46, 48, 50, 52, 0);
      }
      break;
  }
}



//Untouched backup of original Void MovementConfig Code:
void movementConfig(int RPWM, int LPWM, int REN, int LEN, int direction)
//This function configures the signals sent to the motor drivers to control the direction and speeds of each motor driver
{
  if (direction == 1)
  {
    digitalWrite(REN, HIGH);
    digitalWrite(LEN, HIGH);
    analogWrite(RPWM, pwmSET);
    analogWrite(LPWM, 0);
  }
  else if (direction == -1)
  {
    digitalWrite(REN, HIGH);
    digitalWrite(LEN, HIGH);
    analogWrite(RPWM, 0);
    analogWrite(LPWM, pwmSET);
  }
  else
  {
    digitalWrite(REN, LOW);
    digitalWrite(LEN, LOW);
    analogWrite(RPWM, 0);
    analogWrite(LPWM, 0);
  }
}