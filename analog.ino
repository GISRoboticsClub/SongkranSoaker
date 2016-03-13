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

// variables joystick potentiometers are equal to the read of their corresponding potentiometer pin
  joystickH_Value = analogRead(joystickH_potent_pin);
  joystickV_Value = analogRead(joystickV_potent_pin);

// enter -0+ manually for each motor if needed for debugging
  if (true) {
    int incomingByte;
    Serial.print("Enter Hor Motor Direction (-0+) ");
    do {delay(1);} while (Serial.available() < 3);
    //Serial.print(Serial.available());
    //Serial.print("  ");
    incomingByte = Serial.read();
    Serial.println(char(incomingByte));
    Serial.read();
    Serial.read();
    Serial.read();
    if (incomingByte == '-') joystickH_Value = 0;
    if (incomingByte == '+') joystickH_Value = 1023;
    if (incomingByte == '0') joystickH_Value = 512;

    Serial.print("Enter Ver Motor Direction (-0+) ");
    do {delay(1);} while (Serial.available() < 3);
    //Serial.print(Serial.available());
    //Serial.print("  ");
    incomingByte = Serial.read();
    Serial.println(char(incomingByte));
    Serial.read();
    Serial.read();
    Serial.read();
    if (incomingByte == '-') joystickV_Value = 0;
    if (incomingByte == '+') joystickV_Value = 1023;
    if (incomingByte == '0') joystickV_Value = 512;
  }

  if (serialdebug && analogdebug) Serial.print("Hor = ");
  if (serialdebug && analogdebug) Serial.print(joystickH_Value);
  if (serialdebug && analogdebug) Serial.print("  Ver = ");
  if (serialdebug && analogdebug) Serial.println(joystickV_Value);
}

