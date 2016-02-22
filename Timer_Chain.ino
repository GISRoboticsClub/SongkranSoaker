//
// Code for setting up and controlling the Timer Chains.
//
//    Based of the Arduino millis() function that:
//
//            Returns the number of milliseconds since the Arduino board began running the current program.
//            This number will overflow (go back to zero), after approximately 50 days.
//            https://www.arduino.cc/en/Reference/Millis
//
//    This means that if the the SerialBox sketch runs to this approximately 50 day limit  timer chain
//    errors WILL occur.
//

//////////////////////////////////////////////////////////////////////////
void setup_TimerChain() {
}


//////////////////////////////////////////////////////////////////////////
void loop_TimerChain() {

  if (systemTime > quarterSecondTime) processQuarterSecond();
  if (systemTime > halfSecondTime)    processHalfSecond();
  if (systemTime > oneSecondTime)     processOneSecond();
  if (systemTime > fiveSecondTime)    processFiveSecond();
  if (systemTime > tenSecondTime)     processTenSecond();
  if (systemTime > sixtySecondTime)   processSixtySecond();
}


//////////////////////////////////////////////////////////////////////////
void processQuarterSecond() {
  if (serialdebug && timerdebug) Serial.print("Q");
  quarterSecondTime += quarterSecond;
}

//////////////////////////////////////////////////////////////////////////
void processHalfSecond() {
  if (serialdebug && timerdebug) Serial.print("H");
  halfSecondTime += halfSecond;
}

//////////////////////////////////////////////////////////////////////////
void processOneSecond() {
  if (serialdebug && timerdebug) Serial.print("1");
  oneSecondTime += oneSecond;
}

//////////////////////////////////////////////////////////////////////////
void processFiveSecond() {
  if (serialdebug && timerdebug) Serial.print("5");
  fiveSecondTime += fiveSecond;

  motorGo(MotorA, CW, 100);
  motorGo(MotorB, CCW, 100);
}

//////////////////////////////////////////////////////////////////////////
void processTenSecond() {
  if (serialdebug && timerdebug) Serial.print("T");
  tenSecondTime += tenSecond;

  motorGo(MotorA, CCW, 255);
  motorGo(MotorB, CW, 255);
}

//////////////////////////////////////////////////////////////////////////
void processSixtySecond() {
  if (serialdebug && timerdebug) Serial.println("M");
  sixtySecondTime += sixtySecond;
}


