#include "main.h"

void setIntake(int intakePower);
//void setwash();

void clampSwitch();

//lift
void setLift(int liftPower);
extern ez::PID liftPID;
void liftWait();
void lift_task();
void init();

