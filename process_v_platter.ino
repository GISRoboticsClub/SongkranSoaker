//
// Code for setting up horizontal platter.
//    
//    More into needed... 
//
//    Last Modified: 3/8/2016*
//

//////////////////////////////////////////////////////////////////////////
void process_v_platter_setup() {
  
}
//////////////////////////////////////////////////////////////////////////
void process_v_platter_loop() {
  int val;
  
  val = map(joystickV_Value, 0, 1023, -255, 255);
  motorInput(0,val);
}
