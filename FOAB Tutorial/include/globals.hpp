#include "EZ-Template/piston.hpp"
#include "main.h"
#include "pros/rotation.hpp"

//motors
// common issues: friction
//extern pros::Motor liftM;
inline pros::Motor intakeM(4);
inline pros::Motor hookM(-14);

//pneumatics
// common issues: solenoid wire is plugged into the wrong port, default state is wrong, port is wrong, etc
inline ez::Piston clamp1('B');
extern ez::Piston hang;
inline ez::Piston scoopy('H');
inline ez::Piston intakechange('G');
inline ez::Piston pisswash('A', false); 

//sensors 
inline pros::Rotation washr(12);





















//timeout corner 
inline pros::Motor backLF(7);
inline pros::Motor backLH(-8);
inline pros::Motor frontLF(10);
inline pros::Motor frontLH(-9);
inline pros::Motor backRF(-17);
inline pros::Motor backRH(18);
inline pros::Motor frontRF(-20);
inline pros::Motor frontRH(19);