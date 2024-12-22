#include "main.h"
#include "pros/misc.h"

void setIntake(int intakePower){
    intakeM.move(intakePower);
    hookM.move(intakePower);
}




//lift
void setlift(int liftpower){
    //liftM.move(liftpower);
}


ez::PID liftPID{0.1,0,0,0,"Lift"};

void lift_wait(){
    while(liftPID.exit_condition(washr,true) == ez::RUNNING){
        pros::delay(ez::util::DELAY_TIME);
    }
}

void lift_task(){
    pros::delay(10000);
    while(true){
        //setIntake(-liftPID.compute(washr.get_position()));

        pros::delay(ez::util::DELAY_TIME);
    }
}






//Initialize PID
void init() {
    //liftM.tare_position();

    liftPID.exit_condition_set(80, 
    50, 
    300, 
    150, 
    00, 
    500);

master.rumble(".");
}





