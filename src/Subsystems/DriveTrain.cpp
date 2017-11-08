#include "DriveTrain.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain"), left(new Talon(0)), right(
		                   new Talon(1)), leftEncoder(new Encoder(
		                   ENCODER_LEFT_1, ENCODER_LEFT_2)), rightEncoder(
		                   ENCODER_RIGHT_1, ENCODER_RIGHT_2), mult(1.0), ticksToDistance(
		                   1.0) /*need a number for this and check port nums*/ {

	leftEncoder->SetDistancePerPulse(1.0);
	rightEncoder->SetDistancePerPulse(1.0);
	//This was in last year's code but I'm not sure if it's necessary.
	//left->SetInverted(true);
	//right->SetInverted(true);
}

DriveTrain::~DriveTrain()
{
	delete left;
	delete right;
	delete leftEncoder;
	delete rightEncoder;
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void DriveTrain::SetSpeedLeft(double speed)
{
	left->SetSpeed(speed);
}

void DriveTrain::SetSpeedRight(double speed)
{
	right->SetSpeed(speed);
}

void DriveTrain::SetMult(double num)
{
	mult = num;
}

int DriveTrain::GetMult()
{
	return mult;
}

void DriveTrain::ResetEncoders()
{
	leftEncoder->Reset();
	rightEncoder->Reset();
}

//haven't mastered ArcadeDrive yet but when I figure it out it will go here

void DriveTrain::tankDrive(double leftVal, double rightVal)
{
	left->Set(leftVal);
	right->Set(rightVal);
}

//may need a Limit method but I don't know what purpose that serves
