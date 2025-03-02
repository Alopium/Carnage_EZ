#include "EZ-Template/piston.hpp"
#include "EZ-Template/tracking_wheel.hpp"
#include "main.h"
#include "pros/rotation.hpp"




inline pros::Motor intake(20);
inline pros::Motor hook(21);
inline ez::Piston clamps('C');
inline ez::Piston doinkr('E');
inline pros::Motor lift(-1);
inline pros::adi::DigitalIn bumper('A');
inline ez::Piston ringrush('D');
inline ez::Piston doinkl('F');
inline ez::Piston doinkrc('B');
