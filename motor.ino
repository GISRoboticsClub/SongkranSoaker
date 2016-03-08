/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void motor_setup()
{
  int i;
  pinMode(statpin, OUTPUT);
  digitalWrite(statpin, LOW);         // Start out of alarm.

// Initialize pins as required
  for (i=0; i<2; i++)
  {
    pinMode(inApin[i], OUTPUT);       // Be sure output pins are outputs 
    pinMode(inBpin[i], OUTPUT);
    pinMode(pwmpin[i], OUTPUT);

    pinMode(cspin[i], INPUT);         // Be sure input pins are inputs
    digitalWrite(cspin[i], LOW);      //      and pullup resister not active
    pinMode(enpin[i], INPUT);         //
    digitalWrite(enpin[i], LOW);      //
  }

// Initialize motor to be in braked to VCC at no speed
  for (i=0; i<2; i++)
  {
    digitalWrite(inApin[i], LOW);
    digitalWrite(inBpin[i], LOW);
    analogWrite(pwmpin[i], 0);
  }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void motor_loop() {
  int i;

// Check for Over Current condition and if so stop everything and set the alarm
  if ((analogRead(cspin[0]) > CS_THRESHOLD) || (analogRead(cspin[1]) > CS_THRESHOLD)) {
    digitalWrite(statpin, HIGH);
    motorGo(MotorA, CW, 0);
    motorGo(MotorB, CW, 0);
    if (serialdebug && motordebug) Serial.println("***ERROR - At least one CS Pin > Threshold!  Motors could be BURNING!!! ***");
  }

// check to see if direction needs to be changed
   for (i=0; i<2; i++)   {
    if (currentdir[i] != lastdir[i])  {
      if (lastdir[i] != BRAKEVCC) {
        motorGo(i, BRAKEVCC, 0);
      }
    }
  lastdir[i] = currentdir[i];
  }
}


 
 
/////////////////////////////////////////////////////////////////////////////////
// 
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

void motorGo(unsigned int motor, unsigned int motor_direction, unsigned int pwm) {
  if (motor <= 1) {
if (motor == 0){
Serial.print("motor = ");
Serial.print(motor);
Serial.print("  motor direction = ");
Serial.print(motor_direction);
Serial.print("  pwm = ");
Serial.println(pwm);
}


     currentdir[motor] = motor_direction;

    if (motor_direction == BRAKEGND) { motor_direction = BRAKEVCC; }
    if (lastdir[motor] == CCW & motor_direction == CW) {motor_direction = BRAKEVCC;}
    if (lastdir[motor] == CW & motor_direction == CCW) {motor_direction = BRAKEVCC;}

    switch (motor_direction) {
    case BRAKEVCC:
       //brake to VCC
      digitalWrite(inApin[motor], LOW);
      digitalWrite(inBpin[motor], LOW);
      break;
      
    case CW:
       //brake to clockwise
      digitalWrite(inApin[motor], HIGH);
      digitalWrite(inBpin[motor], LOW);
      break;
    
    case CCW:
       //turn counterclockwise
      digitalWrite(inApin[motor], LOW);
      digitalWrite(inBpin[motor], HIGH);
      break;
    
      case BRAKEGND:
       //brake to ground
       digitalWrite(inApin[motor], LOW);
       digitalWrite(inBpin[motor], LOW);
      break;
     }
     analogWrite(pwmpin[motor], pwm);
  } 
}

/////////////////////////////////////////////////////////////////////////////
//
//motorInput gets information from speed from math in the range -255 to 0 to 255 and carrying labels of either horizontal or vertical
// and converts them to motor ID, motor_direction, and pwm
//for motor ID, horizontal is motor A and vertical is motor B
//for motor_direction, a negative sign is CCW and a positive sign is CW
//pwm is the absolute value of speed
//

void motorInput(unsigned int motor, signed int motor_speed) {
  unsigned int motor_direction, pwm;

//  Serial.print("motor = ");
//  Serial.print(motor);
//  Serial.print("  motor speed = ");
//  Serial.println(motor_speed);
  
  if (motor_speed >= 0){
    motor_direction = CW;
  }
  else {
    motor_direction = CCW;
  }
  pwm = abs(motor_speed);
  
  motorGo(motor, motor_direction, pwm);
}


