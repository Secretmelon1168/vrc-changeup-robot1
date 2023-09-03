using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor Motor10Left;
extern motor Motor1Right;
extern controller Controller1;
extern motor Motor3Arm;
extern motor Motor8Intake;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );