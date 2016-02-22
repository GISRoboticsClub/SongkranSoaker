/*
//Setting up servos
Servo myservo[2];

//setting delay time
int delayA = 100;

//setting pin for water project
int unknownPin = 13;

// defining variable of potentiometer pins
int potentPin[2]= {A0, A1};

//define variable of pushpin
const int pushpin1 = 12;

//variable for reading button status
int buttonstate = 0;

// defining variable of servo pins
int servoPin[2] = {9, 10};
//variable to store value coming from potentiometers
int potentValue[2]= {0, 0};

int prevMeasure[2] = { 0, 0};

int actMeasure[2] = { 0, 0};

int setpoint[2] = { 0, 0};

// the setup routine runs once when you press reset:
void setup() {
  //declaring variable n for use in loop
  int n;
  
  platterH_setup(  potentPin[0], servoPin[0] );
  //declaring servo Pins as outputs, declaring potentpins as inputs, and attaching the servo pins to servo
  for(n = 0; n < 2; n = n + 1){
    pinMode(potentPin[n], INPUT);
    pinMode(servoPin[n], OUTPUT);
    myservo[n].attach(servoPin[n]);
  }
  
  // declare button as input
  pinMode(pushpin1, INPUT);
  pinMode(unknownPin, OUTPUT);
  
  //setting up serial moniter
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  //declaring variable n for use in loop
  int change[2] = { 0, 0};
  int error[2] = { 0, 0};
  int n;
  
  //setting buttonstate
  buttonstate = digitalRead(pushpin1);
  
  if (buttonstate == 0) {
    digitalWrite(unknownPin, LOW);
  }
  else if (buttonstate == 1) {
    digitalWrite(unknownPin, HIGH);
  }
  else {
    digitalWrite(unknownPin, LOW);
  }
  //read value from potentiometers then writes that into servo. then prints value into serial moniter
  for(n = 0; n < 2; n = n + 1){
    potentValue[n] = map(analogRead(potentPin[n]), 0, 1023, 0, 180);
    prevMeasure[n] = setpoint[n];
    actMeasure[n] = setpoint[n];
    setpoint[n] = potentValue[n];
    error[n] = setpoint[n] - actMeasure[n];
    change[n] = error[n] + prevMeasure[n];
    myservo[n].write(change[n]);
    Serial.println();
    Serial.print("potentiometer ");
    Serial.print(n);
    Serial.print(" = ");
    Serial.print(analogRead(potentPin[n]));
    Serial.print("servo = ");
    Serial.println(change[n]);
  }
  
  platterH();
  Serial.println();
  
  Serial.print("Button is ");
  Serial.print(buttonstate);
  
  //delay so as not to burn out servos
  delay(delayA);
}

////////////////////////////////////////////////////////////////////////////////////////
// MATH - KARSTON
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
/////// All the math needed to run the motors////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////////

////////////////////////////
//
//////// Functions that will tell the motor what to do////////////////////////
//
////////////////////////////

void platterH_process(){  
  potentValue[0] = map(analogRead(potentPin[0]), 0, 1023, 0, 180);
  prevMeasure[0] = setpoint[0];
  actMeasure[0] = setpoint[0];
  setpoint[0] = potentValue[0];
  error[0] = setpoint[0] - actMeasure[0];
  change[0] = error[0] + prevMeasure[0];
  myservo[0].write(change[0]);
  Serial.println();
  Serial.print("potentiometer ");
  Serial.print(0);
  Serial.print(" = ");
  Serial.print(analogRead(potentPin[0]));
  Serial.print("servo = ");
  Serial.println(change[n]);
}

void platterH_setup(int a, int b) {
  
}

  /*
  potentValue[1] = map(analogRead(potentPin[1]), 0, 1023, 0, 180);
    prevMeasure[1] = setpoint[1];
    actMeasure[1] = setpoint[1];
    setpoint[1] = potentValue[1];
    error[1] = setpoint[1] - actMeasure[1];
    change[1] = error[1] + prevMeasure[1];
    myservo[1].write(change[1]);
    Serial.println();
    Serial.print("potentiometer ");
    Serial.print(1);
    Serial.print(" = ");
    Serial.print(analogRead(potentPin[1]));
    Serial.print("servo = ");
    Serial.println(change[1]);
    */


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /*
  potentValue[1] = map(analogRead(potentPin[1]), 0, 1023, 0, 180);
    prevMeasure[1] = setpoint[1];
    actMeasure[1] = setpoint[1];
    setpoint[1] = potentValue[1];
    error[1] = setpoint[1] - actMeasure[1];
    change[1] = error[1] + prevMeasure[1];
    myservo[1].write(change[1]);
    Serial.println();
    Serial.print("potentiometer ");
    Serial.print(1);
    Serial.print(" = ");
    Serial.print(analogRead(potentPin[1]));
    Serial.print("servo = ");
    Serial.println(change[1]);
    */
    
