//
// Code for setting up horizontal platter.
//    
//    More into needed... 
//
//    Last Modified: 3/8/2016*
//

//////////////////////////////////////////////////////////////////////////
void process_h_platter_setup() {
  
}
//////////////////////////////////////////////////////////////////////////
void process_h_platter_loop() {
  int val;
  
  val = map(joystickH_Value, 0, 1023, -255, 255);
  motorInput(1,val);
}
