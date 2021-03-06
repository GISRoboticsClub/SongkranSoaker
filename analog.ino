//
// Code for reading button and potentiometers
//
//   This code takes in the analog INPUT of the Ps3 joystick,
//   it reads the H and V direction and is also able to read
//   a button push.
//
//   Written by Sam Gilliam
//   Last Modified: 2/23/2016*
//

//////////////////////////////////////////////////////////////////////////
void analog_setup() {
  //setting pins of button and potentiometers to input
  pinMode(joystickH_potent_pin, INPUT);
  pinMode(joystickV_potent_pin, INPUT);
  pinMode(PushButton, INPUT);
}

//////////////////////////////////////////////////////////////////////////
void analog_loop() {
  
// variable buttonstate is equal to read of pushbutton
  ButtonState = digitalRead(PushButton);
  if (ButtonState) {
    digitalWrite(statpin, HIGH);
  }
  else {
    digitalWrite(statpin, LOW);
  }

// variables joystick potentiometers are equal to the read of their corresponding potentiometer pin
  joystickH_Value = analogRead(joystickH_potent_pin);
  joystickV_Value = analogRead(joystickV_potent_pin);

  if (serialdebug && analogdebug) Serial.print("Hor = ");
  if (serialdebug && analogdebug) Serial.print(joystickH_Value);
  if (serialdebug && analogdebug) Serial.print("  Ver = ");
  if (serialdebug && analogdebug) Serial.println(joystickV_Value);

// Simply take joystick inputs and make them do motor control
  motorInput(0, joystickH_Value/4 - 128);
  motorInput(1, joystickV_Value/4 - 128);
}

