#include "EZ-Template/piston.hpp"
#include "main.h"

//motors
pros::Motor intake11W(8,pros::v5::MotorGears::blue);
pros::MotorGroup intake5W({9,-10},pros::v5::MotorGears::blue);
pros::Motor liftM(6);

//pmeumatics

