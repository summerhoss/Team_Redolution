#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "RobotMap.h"
#include "TankDrive.h"

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
	void reverseDrive();
	//float Limit(float num, float max);
	void arcadeDrive(float moveValue, float rotateValue);
	void tankDrive(double leftVal, double rightVal);
	double getDistance();
	double getRate();
};

#endif  // DriveTrain_H
