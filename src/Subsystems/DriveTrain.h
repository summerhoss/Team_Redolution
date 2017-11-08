#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "RobotMap.h"

class DriveTrain : public Subsystem {
private:
	Talon* left;
	Talon* right;
	Encoder* leftEncoder;
	Encoder* rightEncoder;
	double mult;
	int ticksToDistance;

public:
	DriveTrain();
	~DriveTrain();
	void InitDefaultCommand();
	void SetSpeedLeft(double speed);
	void SetSpeedRight(double speed);
	void SetMult(double num);
	int GetMult();
	void ResetEncoders();
	void tankDrive(double leftVal, double rightVal);
};

#endif  // DriveTrain_H
