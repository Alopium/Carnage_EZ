#include "main.h"
#include "pros/misc.h"


void setIntake(int intakePower){
    intake.move(intakePower);
    hook.move(intakePower);
}

//lift
void setlift(int liftpower){
    lift.move(liftpower);
}


ez::PID liftPID{0.6,0,0,0,"Lift"};

void lift_wait(){
    while(liftPID.exit_condition(lift,true) == ez::RUNNING){
        pros::delay(ez::util::DELAY_TIME);
    }
}

void lift_task(){
    pros::delay(2000);
    while(true){
    setlift(liftPID.compute(lift.get_position()));

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


