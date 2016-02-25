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

// Check for Over Current condition and if so stop everything and set the alarm
  if ((analogRead(cspin[0]) > CS_THRESHOLD) || (analogRead(cspin[1]) > CS_THRESHOLD)) {
    digitalWrite(statpin, HIGH);
    motorGo(MotorA, CW, 0);
    motorGo(MotorB, CW, 0);
    if (serialdebug && motordebug) Serial.println("***ERROR - At least one CS Pin > Threshold!  Motors could be BURNING!!! ***");
  }

  
  motorPreviousDirection();
  motorGo(0, horizontal_direction, horizontal_pwm);
  motorGo(1, vertical_direction, vertical_pwm);
  
  
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
 
 
 
void motorGo(unsigned int motor, unsigned int motor_direction, unsigned int pwm) {
  if (motor <= 1)
  {
    switch (motor_direction) {
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
///
/// At this point let's save the motor, motor_direction, and pwm values into a new array variable that is called something like current motor state.  This will hold the information
///  of what the motors are doing.
/// 
/// To solve the problem of slamming from CCW to CW and back we can create another array variable that holds the direction that we want to go.  It may take us two steps to get there...
///  we don't need to worry about the PWM speed because we're going to be setting the direction pins and who cares what the PWM says when we're stopped.
///
/// Up in the motor_loop routine we can create a for loop that checks the actual motor state with the direction we want to go.  If they are not the same then we'll do the switch-over
///  that we coded here.
///
/// we also need to write a "wrapper" around motorGo that lets the math people talk their language and the motor code talk it's language.  For example, the math people are going to be
///  talking horizontal and vertical while motor talks motorA and motorB.  They speak positive and negative numbers between -255 and 255 while motor speak is CW and CCw and numbers
///  0 and 255.
///
/// To make all this complie I had to add a bunch of redundant variables in the main tab.  These will need to be removed.
///
/// The really bad news is that the example code for the motor controller did not implement two analog input pins that we wanted to use but are actually used by the motor
///  controller board.  This means that we don't have the ability to sense where the platters are.  We're going to lose our feedback ability and have to run what is called "open loop".
///  It also means we're going to have to put in limit switches to be sure we don't kill our machine.  I guess it's not that big a deal in real life, it just means we have to re-think
///  the math stuff and self-defense stuff.
///
/// I discovered this while trying to figure out what the current sense pins were used for.  They carry a signal proportional to the motor current so if the voltage we read gets too
///   high then we know we're trying to start a fire in the motors - a bad thing...  The two analog pins that I just learned about provide additional information to figure out what's
///   wrong. Cool stuff but we don't need to use them...
///
/// So, this new discovery actually means the math section for this project just about disapeared ---- or ---- we cut the analog pins from the motor controller and put our own wires
///  into the Arduino directly to get our analog pins back.  As I'm typing I leaning to that solution...
///
/// For the GitHub repository I made one last manual merge and then pushed this version of the code up as the master.  This way everyone can have the code and work on it.
///


  } 
}

void motorInput() {
  if (horizontal_direction == 1){
    motor = 0;
    motor_direction = 1;
    pwm = horizontal_pwm;
//    return motor;
//    return motor_direction;
//    return horizontal_pwm;
  }
  
  if (horizontal_direction == -1){
    motor = 0;
    motor_direction = 2;
    pwm = horizontal_pwm;
//    return motor;
//    return motor_direction;
//    return horizontal_pwm;
  }
  
  if (vertical_direction == 1){
    motor = 1;
    motor_direction = 1;
    pwm = vertical_pwm;
//    return motor;
//    return motor_direction;
//    return vertical_pwm;
  }
 
  if (vertical_direction == -1){
    motor = 1;
    motor_direction = 2;
    pwm = vertical_pwm;
//    return motor;
//    return motor_direction;
//    return vertical_pwm;
  }
}


int motorPreviousDirection()
{
if (motor = MotorA){
   motor_stop = 0;
   if (direction_input != previous){
     if (previous == motor_stop){
      motor_direction = direction_input;
     }
     else {
       previous = motor_stop;
     }
   }
   previous = motor_direction;
}

  if (motor = 1){
   motor_stop = 0;
   if (direction_input != previous){
     if (previous == motor_stop){
      motor_direction = direction_input;
     }
     else {
       previous = motor_stop;
     }
   }
    previous = motor_direction;
 }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*Scratch
  
  if (motor = 0){
   motor_stop = 0
   if (direction_input != previous){
     if (previous == motor_stop){
      motor_direcion = direction_input;
     }
     else {
       previous = motor_stop;
     }
   }
   motorGo(motor, motor_direction, pwm);
    previous = motor_direction;
  }

  if (motor = 1){
   motor_stop = 0
   if (direction_input != previous){
     if (previous == motor_stop){
      motor_direcion = direction_input;
     }
     else {
       previous = motor_stop;
     }
   }
   motorGo(motor, motor_direction, pwm);
    previous = motor_direction;
  }


  */

