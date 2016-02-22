//


void motor_setup()
{
  pinMode(statpin, OUTPUT);

// Initialize digital pins as outputs
  for (int i=0; i<2; i++)
  {
    pinMode(inApin[i], OUTPUT);
    pinMode(inBpin[i], OUTPUT);
    pinMode(pwmpin[i], OUTPUT);
  }
// Initialize braked
  for (int i=0; i<2; i++)
  {
    digitalWrite(inApin[i], LOW);
    digitalWrite(inBpin[i], LOW);
  }
}

void motor_loop()
{
  if ((analogRead(cspin[0]) < CS_THRESHOLD) && (analogRead(cspin[1]) < CS_THRESHOLD)) {
    digitalWrite(statpin, HIGH);
    if (serialdebug && motordebug) Serial.println("CS Pin < Threshold");
  }
}


/* motorGo() will set a motor going in a specific direction
 the motor will continue going in that direction, at that speed
 until told to do otherwise.
 
 motor: this should be either 0 or 1, will selet which of the two
 motors to be controlled
 
 direct: Should be between 0 and 3, with the following result
 0: Brake to VCC
 1: Clockwise
 2: CounterClockwise
 3: Brake to GND
 
 pwm: should be a value between ? and 1023, higher the number, the faster
 it'll go
 // pwm value from 0 to 255
 */

void motorGo(unsigned int motor, unsigned int direct, unsigned int pwm)
{
  if (motor <= 1)
  {
    switch (direct) {
    case 0:
       //brake to VCC
      digitalWrite(inApin[motor], LOW);
      digitalWrite(inBpin[motor], LOW);
      break;
      
    case 1:
       //brake to clockwise
      digitalWrite(inApin[motor], HIGH);
      digitalWrite(inBpin[motor], LOW);
      break;
    
    case 2:
       //turn counterclockwise
      digitalWrite(inApin[motor], LOW);
      digitalWrite(inBpin[motor], HIGH);
      break;
    
      case 3:
       //brake to ground
       digitalWrite(inApin[motor], LOW);
       digitalWrite(inBpin[motor], LOW);
      break;
     }
     analogWrite(pwmpin[motor], pwm);
  } 
}

