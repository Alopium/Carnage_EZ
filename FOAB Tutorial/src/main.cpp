#include "main.h"
#include "autons.hpp"
#include "pros/misc.h"
#include "pros/motors.h"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// Chassis constructor
ez::Drive chassis(
    // These are your drive motors, the first motor is used for sensing!
    {7,-8, 10, -9},     // Left Chassis Ports (negative port will reverse it!)
    {-17, 18, 19, -20},  // Right Chassis Ports (negative port will reverse it!)

    15,      // IMU Port
    2,  // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
    600);   // Wheel RPM
ez::Drive mchassis(
    // These are your drive motors, the first motor is used for sensing!
    {7,-8, -10, 9},     // Left Chassis Ports (negative port will reverse it!)
    {-17, 18,19,-20},  // Right Chassis Ports (negative port will reverse it!)

    15,      // IMU Port
    2,  // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
    600);   // Wheel RPM
//pros::Task lift_Task(liftTask);
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  // Print our branding over your terminal :D
  chassis.initialize();
  ez::as::initialize();
  //ez::ez_template_print();
  pros::delay(500);  // Stop the user from doing anything while legacy ports configure

  // Configure your chassis controls
  chassis.opcontrol_curve_buttons_toggle(false);  // Enables modifying the controller curve with buttons on the joysticks
  chassis.opcontrol_drive_activebrake_set(2);    // Sets the active brake kP. We recommend ~2.  0 will disable.
  chassis.opcontrol_curve_default_set(3, 3.5);     // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)

  // Set the drive to your own constants from autons.cpp!
  default_constants();
  init();

  // Autonomous Selector using LLEMU
  ez::as::auton_selector.autons_add({
        Auton("pos blue Match",bluefront),
        Auton("negative blue Match",blueback),
        Auton("pos red Match",redfront),
        Auton("negative red Match",redback), 
        Auton("pos blue Tournament",bluefrontT),
        Auton("negative blue Tournament",bluebackT),
        Auton("pos red Tournament",redfrontT),
        Auton("negative red Tournament",redbackT), 
        Auton("skills",Skills), 
  });
      //PID Tasks




  // Initialize chassis and auton selector
  


    master.rumble("...");

}
    pros::Task lifttask(lift_task);

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  // . . .
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
  // . . .
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  chassis.pid_targets_reset();                // Resets PID targets to 0
  chassis.drive_imu_reset();                  // Reset gyro position to 0
  chassis.drive_sensor_reset();               // Reset drive sensors to 0
  chassis.drive_brake_set(MOTOR_BRAKE_HOLD);  // Set motors to hold.  This helps autonomous consistency

  ez::as::auton_selector.selected_auton_call();  // Calls selected auton from autonomous selector
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
int countController = 0;

void opcontrol() {
  //disable chassis not being used so Hayden can like, drive the robot. 
  mchassis.pid_drive_toggle(false);
  chassis.pid_drive_toggle(false);
              liftPID.target_set(0);
  // This is preference to what you like to drive on
  pros::motor_brake_mode_e_t driver_preference_brake = MOTOR_BRAKE_HOLD;

  chassis.drive_brake_set(driver_preference_brake);

  while (true) {
    // PID Tuner
    // After you find values that you're happy with, you'll have to set them in auton.cpp
    if (!pros::competition::is_connected()) {
      // Enable / Disable PID Tuner
      //  When enabled:
      //  * use A and Y to increment / decrement the constants
      //  * use the arrow keys to navigate the constants
      if (master.get_digital_new_press(DIGITAL_X))
        chassis.pid_tuner_toggle(); 

      // Trigger the selected autonomous routine
      if (master.get_digital(DIGITAL_B) && master.get_digital(DIGITAL_DOWN)) {
        autonomous();
        chassis.drive_brake_set(driver_preference_brake);
      }

      //chassis.pid_tuner_iterate();  // Allow PID Tuner to iterate
    }
  //mecanum drive movement, fwd backward = +/- in globals, L/R = 1st +/-, strafe = 2nd +/-
  backLF.move(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)+master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)+master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X));
  backLH.move(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)+master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)+master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X));
  backRF.move(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)-master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)-master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X));
  backRH.move(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)-master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)-master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X));
  frontLF.move(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)+master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)-master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X));
  frontLH.move(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)+master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)-master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X));
  frontRF.move(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)-master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)+master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X));
  frontRH.move(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)- master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)+master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X));


    // ez template drive control
    //chassis.opcontrol_tank();  // Tank control
    //chassis.opcontrol_arcade_standard(ez::SPLIT);   // Standard split arcade
    // chassis.opcontrol_arcade_standard(ez::SINGLE);  // Standard single arcade
    // chassis.opcontrol_arcade_flipped(ez::SPLIT);    // Flipped split arcade
    // chassis.opcontrol_arcade_flipped(ez::SINGLE);   // Flipped single arcade

    // . . .
    // Put more user control code here!
    // . . .
    setIntake((master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)-master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))*127);
    clamp1.button_toggle(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B));
    scoopy.button_toggle(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN));
    //hang.button_toggle(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT));
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)){
            liftPID.target_set(-200);
            pisswash.set(true);
    };
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)){
            liftPID.target_set(900);
            pisswash.set(false);
    }
  // pid testing and position tracking for lifts
  /*if(!(countController % 25)){
    master.print(0,0,"%lf", washr.get_position());
  }
  countController++; */


    pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}