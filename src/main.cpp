/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Motor1Right          motor         10              
// Motor10Left          motor         1               
// Controller1          controller                    
// Motor3Arm            motor         3               
// Motor8Intake         motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
//AUTO CODE BELOW VV//
void autonomous(void) { 
  // this is autonon code.
  Motor3Arm.spin(forward);
  wait(2, seconds);
  Motor1Right.spin(forward);
  Motor10Left.spin(forward);
  wait(1550, msec);
  Motor1Right.stop();
  Motor10Left.stop();
  Motor8Intake.spin(reverse, 80, percent);
  wait(1000, msec);
  Motor8Intake.stop();
  Motor1Right.spin(reverse);
  Motor10Left.spin(reverse);
  wait(1000, msec);
  Motor1Right.stop();
  Motor10Left.stop();
  wait(100, msec);
  Motor10Left.spin(reverse);
  Motor1Right.spin(forward);
  wait(2450, msec);
  Motor10Left.stop();
  Motor1Right.stop();
  Motor3Arm.spin(reverse, 30, percent);
  wait(100, msec);
  Motor10Left.spin(forward);
  Motor1Right.spin(forward);
  Motor8Intake.spin(forward, 65, percent);
  wait(500, msec);
  Motor3Arm.setStopping(coast);
  Motor3Arm.stop();
  wait(2300, msec);
  Motor3Arm.stop();
  Motor3Arm.setStopping(hold);
  Motor10Left.stop();
  Motor1Right.stop();
  wait(10, msec);
  Motor10Left.spin(reverse, 15, percent);
  Motor1Right.spin(reverse, 5, percent);
  wait(1300, msec);
  Motor10Left.stop();
  Motor1Right.stop();
  wait(10, msec);
  Motor3Arm.spin(forward, 60, percent);
  wait(760, msec);
  Motor10Left.spin(forward);
  Motor1Right.spin(forward);
  wait(500, msec);
  Motor8Intake.spin(reverse, 100, percent);
  wait(50, msec);
  Motor1Right.stop();
  Motor10Left.stop();
  // end of autonon code.
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

  // Joystick Info
  int FwdBack = Controller1.Axis3.position(percent);
  int Rotate = Controller1.Axis1.position(percent);
  
  // Movement
  Motor10Left.spin(forward, FwdBack + Rotate, percent);
  Motor1Right.spin(forward, FwdBack - Rotate, percent);
  // Precision Movement
  if (Controller1.ButtonDown.pressing())  {
    Motor10Left.spin(reverse, 40, percent);
    Motor1Right.spin(reverse, 40, percent);
  }
  else if (Controller1.ButtonUp.pressing()) {
    Motor10Left.spin(forward, 40, percent);
    Motor1Right.spin(forward, 40, percent);
  }
  else if (Controller1.ButtonLeft.pressing()) {
    Motor1Right.spin(forward, 28, percent);
    Motor10Left.spin(reverse, 28, percent);
  }
  else if (Controller1.ButtonRight.pressing()) {
    Motor1Right.spin(reverse, 28, percent);
    Motor10Left.spin(forward, 28, percent);
  }


  // Arm Movement
  if  (Controller1.ButtonL1.pressing())
  {
    Motor3Arm.spin(forward);
  }
  else if(Controller1.ButtonL2.pressing())
  {
   Motor3Arm.setStopping(coast);
  }
  else if (Controller1.ButtonB.pressing())  {
    Motor3Arm.spin(reverse);
  }
  else
  {
    Motor3Arm.stop();
    Motor3Arm.setStopping(hold);
  }
  
  // Intake Movement
  if  (Controller1.ButtonR1.pressing()) {
    Motor8Intake.spin(forward, 60, percent);
  }
  else if(Controller1.ButtonR2.pressing()) {
    Motor8Intake.spin(reverse, 60, percent);
  }
  else {
    Motor8Intake.stop();
    Motor8Intake.setStopping(hold);
  }

//     Controller Screen Experiment
//  if(Controller1.ButtonY.pressing())  {
//    Controller1.Screen.clearScreen();
//    Controller1.Screen.newLine();
//    Controller1.Screen.print(Motor3Arm.temperature(percent));
//    Controller1.Screen.print(" ");
//    Controller1.Screen.print(Brain.Battery.capacity());
//     }


  

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  } 
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
