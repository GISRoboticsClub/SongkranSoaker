/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void math_setup() {
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void math_loop() {
}


/*
 * // defining potentiometer pins
#define horizontal_potentiometer_pin A0
#define vertical_potentiometer_pin A1
#define horizontal_platter_pin A2
#define vertical_platter_pin A3

//constant definitions
#define inputMax 1023  
#define scaling_factor 20
#define pwm_max 255



  //read from the joystick potentiometer
  
  int joystick_horizontal_raw, joystick_vertical_raw, joystick_horizontal, joystick_vertical;
  int platter_horizontal_raw, platter_vertical_raw, platter_horizontal, platter_vertical;
  int d_horizontal, d_vertical;
  int horizontal_direction, vertical_direction;
  int horizontal_pwm, vertical_pwm;
    
  joystick_horizontal_raw = analogRead(horizontal_potentiometer_pin);     
  joystick_vertical_raw = analogRead(vertical_potentiometer_pin);
  joystick_horizontal = joystick_horizontal_raw - inputMax/2;     
  joystick_vertical = joystick_vertical_raw - inputMax/2;     
  
  Serial.print("joystick_horizontal_raw =  ");
  Serial.print(joystick_horizontal_raw);
  Serial.print("     joystick_vertical_raw = ");
  Serial.print(joystick_vertical_raw);
  
  Serial.print("joystick_horizontal =  ");
  Serial.print(joystick_horizontal);
  Serial.print("     joystick_vertical =  ");
  Serial.print(joystick_vertical);
  
//////////////////////////////////////////////////////////////////////////////////////////////
  //read from platter potentiometer
  platter_horizontal_raw = analogRead(horizontal_platter_pin);      
  platter_vertical_raw = analogRead(vertical_platter_pin);
  platter_horizontal = platter_horizontal_raw - inputMax/2;
  platter_vertical = platter_vertical_raw - inputMax/2;
  
//////////////////////////////////////////////////////////////////////////////////////////////  
  d_horizontal = joystick_horizontal - platter_horizontal;
  d_vertical = joystick_vertical - platter_vertical;
  
  Serial.print("d_horizontal =  ");
  Serial.print(d_horizontal);
  Serial.print("    d_vertical =  ");
  Serial.print(d_vertical);
  
///////////////////////////////////////////////////////////////////////////////////////////////
  if(d_horizontal>=0) {
    horizontal_direction = 1;
  }
  else {
    horizontal_direction = -1;
  }
  if(d_vertical>=0) {
    vertical_direction = 1;
  }
  else {
    vertical_direction = -1;
  }
  
  Serial.print("horizontal_direction =  ");
  Serial.print(horizontal_direction);
  Serial.print("     vertical_direction =  ");
  Serial.print(vertical_direction);

  
  
///////////////////////////////////////////////////////////////////////////////////////////////
  //pwm for horizontal direction
  if(d_horizontal>scaling_factor) {
    horizontal_pwm = pwm_max * horizontal_direction;
  }
  else {
    horizontal_pwm = (scaling_factor/pwm_max) * d_horizontal * horizontal_direction;
  }
  
  //pwm for vertical direction
  if(d_vertical>scaling_factor) {
    vertical_pwm = pwm_max * vertical_direction;
  }
  else {
    vertical_pwm = (scaling_factor/pwm_max) * d_vertical * vertical_direction;
  }
  
  Serial.print("horizontal_pwm =  ");
  Serial.print( horizontal_pwm);
  Serial.print("     vertical_pwm =  ");
  Serial.print(vertical_pwm);
  
}
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
inputMax = 1023;    
scaling_factor = 20;

int rate() {
  //read from the joystick potentiometer
  joystick_horizontal_raw = read(input_x);      
  joystick_vertical_raw = read(input_y);
  joystick_horizontal = joystick__horizontal_raw - inputMax/2;      
  joystick_vertical = joystick_vertical_raw - inputMax/2;     
  
  //read from platter potentiometer
  platter_horizontal_raw = read(input_x);     
  platter_vertical_raw = read(input_y);
  platter_horizontal = platter_horizontal_raw - inputMax/2;
  platter_vertical = platter_vertical_raw - inputMax/2;

  d_horizontal = joystick_horizontal - platter_horizontal;
  d_vertical = joystick_vertical - platter_vertical;
}
  
//Direction of rate of change
  if(d_horizontal>=0) {
    horizontal_direction = 1;
  }
  else {
    horizontal_direction = -1;
  }
  if(d_vertical>=0) {
    vertical_direction = 1;
  }
  else {
    vertical_direction = -1;
  }
  
//pwm for horizontal direction
  if(d_horizontal>scaling_factor) {
    horizontal_pwm = pwm_max * horizontal_direction;
  }
  else {
    horizontal_pwm = (scaling_factor/pwm_max) * d_horizontal * horizontal_direction;
  }
  
//pwm for vertical direction
  if(d_vertical>scaling_factor) {
    vertical_pwm = pwm_max * vertical_direction;
  }
  else {
    vertical_pwm = (scaling_factor/pwm_max) * d_vertical * vertical_direction;
  }

*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





