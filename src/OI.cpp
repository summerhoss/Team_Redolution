#include "OI.h"

#include <WPILib.h>

OI::OI() : leftStick(new Joystick(2)), rightStick(new Joystick(1))  {
	//check arguments
}

OI::~OI()
{
	delete rightStick;
	delete leftStick;
}

Joystick* OI::getLeftStick() {
	return leftStick;
}

Joystick* OI::getRightStick() {
	return rightStick;
}
