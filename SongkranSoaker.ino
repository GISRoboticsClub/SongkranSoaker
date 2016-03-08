//Last Changed: Feb 16, 2016
// This sketch controls our very first songkran soaker
// 
// This sketch will take the analog values of the platter and potentiometers and
// send this information to the math functions and the math functions will calculate
// the amount needed to move our self built servos. Then, the motor functions will take
// that value and move the motor(self built servo).
//

//////////////////////////////////////////////////////////////////////////

// Debug Definitions
#define serialdebug                     true    // Echos debug info out the Hardware Serial Port
#define timerdebug                      false   // Enables the Timer Chain debug output
#define analogdebug                     false   // "" 
#define mathdebug                       false   // ""
#define process_h_platterdebug          false   // ""
#define process_v_platterdebug          false   // ""
#define motordebug                      true    // 


//////////////////////////////////////////////////////////////////////////////

//Includes Files


//////////////////////////////////////////////////////////////////////////////

//Definitions ↓

//////////////////////////////////////////////////////////////////////////////

// Arduino pin definitions
  
  // Analog pin definitions
  
#define SwitchOutput1                        A0     // Motor Controller - EN: Status of switches output 
#define SwitchOutput2                        A1     // Motor Controller - EN: Status of switches output 
#define CurrentSenseInput1                   A2     // Motor Controller - CS: Current sense ANALOG input
#define CurrentSenseInput2                   A3     // Motor Controller - CS: Current sense ANALOG input
#define joystickH_potent_pin                 A4     // Horisantal joystick position potentiometer pin
#define joystickV_potent_pin                 A5     // Vertical joystick position potentiometer pin
//#define platterH_potent_pin                  A4     // Horizantal platter position potentiometer pin
//#define platterV_potent_pin                  A5     // Vertical platter position potentiometer pin

  // Digital pin definitions
  
#define ArduinoUSB_RX                   0       // Arduino USB Serial Port RX
#define ArduinoUSB_TX                   1       // Arduino USB Serial Port TX
#define Pin2                            2       // Pin2 - 
#define Pin3                            3       // Pin3 -
#define MotorAInput2                    4       // Motor Controller - INA: Clockwise input
#define PWM1                            5       // Motor Controller - PWM Input
#define PWM2                            6       // Motor Controller - PWN Input
#define MotorAInput1                    7       // Motor Controller - INA: Clockwise input
#define MotorBInput1                    8       // Motor Controller - INB: Counter-clockwise input
#define MotorBInput2                    9       // Motor Controller - INB: Counter-clockwise input
#define PushButton                      10      // Joystick Push Button
#define Pin11                           11      // Pin11 - 
#define Pin12                           12      // Pin12 - 
#define statpin                         13      // Motor Controller - status pin  *** Error Condition meaning the current going to (at least) one of the motors is too high ***

// Timer Chain Definitions - all timing in msec
#define quarterSecond                   250
#define halfSecond                      500
#define oneSecond                       1000
#define fiveSecond                      5000
#define tenSecond                       10000
#define sixtySecond                     60000

// Motor Control Definitions
#define MotorA            0             // Select Motor
#define MotorB            1

#define BRAKEVCC          0             // Motor Commands
#define CW                1
#define CCW               2
#define BRAKEGND          3

#define CS_THRESHOLD      100           //


//////////////////////////////////////////////////////////////////////////////

// Variables ↓

//////////////////////////////////////////////////////////////////////////////
// General global variables                // General means used in more than one tab


// Timer Chain Variables
unsigned long systemTime;                                 // Valid system time for the current "loop"
unsigned long quarterSecondTime = quarterSecond;
unsigned long halfSecondTime    = halfSecond;
unsigned long oneSecondTime     = oneSecond;
unsigned long fiveSecondTime    = fiveSecond;
unsigned long tenSecondTime     = tenSecond;
unsigned long sixtySecondTime   = sixtySecond;

// Math variables


// Analog variables
bool ButtonState = false;               // Buttonstate is whether or not the button is pushed down. Used for knowing when to fire trigger
unsigned int joystickH_Value = 0;       // Value read from joystick H potentiometer 10 bits
unsigned int joystickV_Value = 0;       // Value read from joystick V potentiometer 10 bits

// Motor variables
/*  Motor Shield (VNH2SP30) pin definitions
 xxx[0] controls '1' AKA CW outputs
 xxx[1] controls '2' AKA CCW outputs */
int inApin[2] = {MotorAInput2, MotorAInput1};                // INA: Clockwise input
int inBpin[2] = {MotorBInput1, MotorBInput2};                // INB: Counter-clockwise input
int pwmpin[2] = {PWM2, PWM1};                                // PWM input
int cspin[2]  = {CurrentSenseInput1, CurrentSenseInput2};    // CS: Current sense ANALOG input
int enpin[2]  = {SwitchOutput1, SwitchOutput2};              // EN: Status of switches output (Analog pin)

int lastdir[2];
int currentdir[2];

int horizontal_direction;
int vertical_direction;
int pwm;
int motor;
int motor_direction;
int horizontal_pwm;
int vertical_pwm;
int motor_stop;
int direction_input;
int previous;

///////////////////////////////////////////////////////////////////////////////
void setup(){

// Initialize for serial window debugging and communicating to the ESampler
  Serial.begin(9600);
  while (!Serial) { ; } // wait for serial port to connect. Needed for Leonardo only
  if (serialdebug) Serial.println("Setting up Arduino System");         // Notice this debug is for all debugging...

  analog_setup();
  math_setup();
  motor_setup();
  process_h_platter_setup();
  process_v_platter_setup();
  setup_TimerChain();
  }

void loop(){
  
  systemTime = millis();

  analog_loop();
  math_loop();
  motor_loop();
  process_h_platter_loop();
  process_v_platter_loop();
  loop_TimerChain();
}


