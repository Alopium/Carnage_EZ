#include "autons.hpp"
#include "main.h"
#include "pros/rtos.hpp"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;
const int SWING_SPEED = 90;

///
// Constants
///
void default_constants() {
  chassis.pid_heading_constants_set(13.2, 0, 0); //og is 11, 0 ,20
  chassis.pid_drive_constants_forward_set(9,0,100); //og is 20, 0, 100
  chassis.pid_drive_constants_backward_set(9,0,100);// og is 20, 0 100
  chassis.pid_turn_constants_set(1.9025, 0.05, 10, 15); //3, 0.05, 20, 15
  chassis.pid_swing_constants_set(6, 0, 65); //6,0,65

  chassis.pid_turn_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(80_ms, 1_in, 250_ms, 3_in, 450_ms, 450_ms);

  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  chassis.slew_drive_constants_set(7_in, 50);

  mchassis.pid_heading_constants_set(13.2, 0, 20); //og is 11, 0 ,20
  mchassis.pid_drive_constants_forward_set(20,0,100); //og is 20, 0, 100
  mchassis.pid_drive_constants_backward_set(20,0,100);// og is 20, 0 100

  mchassis.pid_drive_exit_condition_set(80_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
}

//Autons are organized by auton selector order and order of use outside of comps 
void test(){
  mchassis.pid_drive_set(12, 110, false);
}

void bluefront(){
  chassis.pid_drive_set(-22, 110, false);
  chassis.pid_wait();
  clamp1.set(true);
  setIntake(-127);
  chassis.pid_drive_set(-6, 110, false);
  chassis.pid_wait();
  chassis.pid_turn_set(90, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(23, 100, false);
  chassis.pid_wait();
  chassis.pid_turn_set(-90, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(14, 90, false);
  setIntake(0);


}
void blueback(){
  chassis.pid_drive_set(-22, 110, false);
  chassis.pid_wait();
  clamp1.set(true);
  setIntake(-127);
  chassis.pid_drive_set(-6, 110, false);
  chassis.pid_wait();
  chassis.pid_turn_set(-90, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(23, 100, false);
  chassis.pid_wait();
  chassis.pid_drive_set(-24, 110, false);
  chassis.pid_wait();
  chassis.pid_turn_set(90, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(14, 90, false);
  setIntake(0);







  
}

void redfront(){
  chassis.pid_drive_set(-22, 110, false);
  chassis.pid_wait();
  clamp1.set(true);
  setIntake(-127);
  chassis.pid_drive_set(-8, 110, false);
  chassis.pid_wait();
  chassis.pid_turn_set(-90, 127);
  chassis.pid_wait();
  pros::delay(1500);
  chassis.pid_drive_set(23, 100, false);
  chassis.pid_wait();
  chassis.pid_turn_set(92, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(14, 90, false);
  setIntake(0);

}
void redback(){
  chassis.pid_drive_set(-22, 110, false);
  chassis.pid_wait();
  clamp1.set(true);
  setIntake(-127);
  chassis.pid_drive_set(-6, 110, false);
  chassis.pid_wait();
  chassis.pid_turn_set(90, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(23, 100, false);
  chassis.pid_wait();
  chassis.pid_drive_set(-24, 110, false);
  chassis.pid_wait();
  chassis.pid_turn_set(-90, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(14, 90, false);
  setIntake(0);


}

void bluefrontT(){
  chassis.pid_drive_set(-22, 110, false);
  chassis.pid_wait();
  clamp1.set(true);
  setIntake(-127);
  chassis.pid_drive_set(-6, 110, false);
  chassis.pid_wait();
  chassis.pid_turn_set(90, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(22, 90, false);
  chassis.pid_wait();
  pros::delay(800);
  setIntake(0);
  chassis.pid_turn_set(25, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(34, 110, false);
  chassis.pid_wait();
  scoopy.set(true);

}
void bluebackT(){
  chassis.pid_drive_set(-22, 110, false);
  chassis.pid_wait();
  clamp1.set(true);
  setIntake(-127);
  chassis.pid_drive_set(-6, 110, false);
  chassis.pid_wait();
  chassis.pid_turn_set(-90, 120);
  chassis.pid_wait();
  chassis.pid_drive_set(23, 100, false);
  chassis.pid_wait();
  chassis.pid_turn_set(-170, 120);
  chassis.pid_wait();
  chassis.pid_drive_set(12, 110, false);
  chassis.pid_wait();
  chassis.pid_turn_set(-124, 120);
  chassis.pid_wait(); 

}

void redfrontT(){
  chassis.pid_drive_set(-22, 110, false);
  chassis.pid_wait();
  clamp1.set(true);
  setIntake(-127);
  chassis.pid_drive_set(-6, 110, false);
  chassis.pid_wait();
  chassis.pid_turn_set(-90, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(22, 90, false);
  chassis.pid_wait();
  pros::delay(800);
  setIntake(0);
  chassis.pid_turn_set(-25, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(34, 110, false);
  chassis.pid_wait();
  scoopy.set(true);
}
void redbackT(){
  chassis.pid_drive_set(-22, 110, false);
  chassis.pid_wait();
  clamp1.set(true);
  setIntake(-127);
  chassis.pid_drive_set(-6, 110, false);
  chassis.pid_wait();
  chassis.pid_turn_set(90, 120);
  chassis.pid_wait();
  chassis.pid_drive_set(23, 100, false);
  chassis.pid_wait();
  chassis.pid_turn_set(170, 120);
  chassis.pid_wait();
  chassis.pid_drive_set(12, 110, false);
  chassis.pid_wait();
  chassis.pid_turn_set(124, 120);
  chassis.pid_wait(); 
}

  


void Skills(){
chassis.pid_drive_set(-4.5, 127, false);
chassis.pid_wait();
clamp1.set(true);
chassis.pid_drive_set(-10, 90, false);
chassis.pid_wait();
chassis.pid_turn_set(-182, 90);
chassis.pid_wait();
setIntake(-127);
chassis.pid_drive_set(20, 90, false);
chassis.pid_wait();
chassis.pid_turn_set(-90, 110);
chassis.pid_wait();
chassis.pid_drive_set(26, 100, false);
chassis.pid_wait();
chassis.pid_turn_set(0, 110);
chassis.pid_wait();
chassis.pid_drive_set(15, 50, false);
chassis.pid_wait();
pros::delay(250);
chassis.pid_drive_set(15, 50, false);
chassis.pid_wait();
chassis.pid_turn_set(107.5, 80);
chassis.pid_wait();
chassis.pid_drive_set(-15, 110, false);
chassis.pid_wait();
pros::delay(500);
setIntake(127);
pros::delay(750);
clamp1.set(false);
chassis.pid_drive_set(2.5, 127, false);
chassis.pid_wait();
setIntake(0);
chassis.pid_turn_set(105, 127);
chassis.pid_wait();
chassis.pid_drive_set(68.5, 127, false);
chassis.pid_wait();
chassis.pid_turn_set(244.5, 127);
chassis.pid_wait();
chassis.pid_drive_set(-15, 127, false);
chassis.pid_wait();
clamp1.set(true);
/*chassis.pid_drive_set(-7.5, 127, false);
chassis.pid_wait();
chassis.pid_turn_set(180, 127);
chassis.pid_wait();
setIntake(-127);
chassis.pid_drive_set(20, 90, false);
chassis.pid_wait();
chassis.pid_turn_set(90, 127);
chassis.pid_wait();
chassis.pid_drive_set(20, 90, false);
chassis.pid_wait();
chassis.pid_turn_set(22.5, 127);
chassis.pid_wait();
chassis.pid_drive_set(25, 90, false);
chassis.pid_wait();*/




}


//tuner autons
void drive_48(){
  chassis.pid_drive_set(48_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}
void drive_96(){
  chassis.pid_drive_set(96_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}
void driveBack_48(){
  chassis.pid_drive_set(48_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_drive_set(-48_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}
void driveBack_96(){
  chassis.pid_drive_set(96_in, DRIVE_SPEED, true);
  chassis.pid_wait();
  chassis.pid_drive_set(-96_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}
void turn_90(){
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
}
void turn_180(){
  chassis.pid_turn_set(180_deg, TURN_SPEED);
  chassis.pid_wait();
}
void turn_360(){
  chassis.pid_turn_set(360_deg, TURN_SPEED);
  chassis.pid_wait();
}
void turnBack(){
  chassis.pid_turn_set(360_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();
}
