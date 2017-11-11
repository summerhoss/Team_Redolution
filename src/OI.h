#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
public:
	OI();
	~OI();
	Joystick* getLeftStick();
	Joystick* getRightStick();

private:
	Joystick* leftStick;
    Joystick* rightStick;
};

#endif  // OI_H
