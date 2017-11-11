#include "DriveTrain.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain"), left(new Talon(0)), right(
		                   new Talon(1)), leftEncoder(new Encoder(
		                   ENCODER_LEFT_1, ENCODER_LEFT_2)), rightEncoder(
		                   ENCODER_RIGHT_1, ENCODER_RIGHT_2), mult(1.0), ticksToDistance(114) {
	//need to check the port numbers

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
	SetDefaultCommand(new TankDrive());
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

void DriveTrain::reverseDrive(){
	left->SetInverted(!left->GetInverted());
	right->SetInverted(!right->GetInverted());
}

/*
float DriveTrain::Limit(float num, float  max) {
	if (num > max)
		return max;

	if (num < -max)
		return -max;

	return num;
}

//arcade drive from last year... not sure if it works
void DriveTrain::arcadeDrive(float moveValue, float rotateValue) {
	float leftMotorOutput;
	float rightMotorOutput;

	moveValue = DriveTrain::Limit(moveValue, 1.0);
	rotateValue = DriveTrain::Limit(rotateValue, 1.0);

	// Standard ArcadeDriveTrain algorithm from Google
	if (moveValue > 0.0) {
		if (rotateValue > 0.0) {
			leftMotorOutput = moveValue - rotateValue;
			rightMotorOutput = max(moveValue, rotateValue);
		} else {
			leftMotorOutput = max(moveValue, -rotateValue);
			rightMotorOutput = moveValue + rotateValue;
		}
	} else {
		if (rotateValue > 0.0) {
			leftMotorOutput = -max(-moveValue, rotateValue);
			rightMotorOutput = moveValue + rotateValue;
		} else {
			leftMotorOutput = moveValue - rotateValue;
			rightMotorOutput = -max(-moveValue, -rotateValue);
		}
	}
	*/

void DriveTrain::tankDrive(double leftVal, double rightVal)
{
	left->Set(leftVal);
	right->Set(-rightVal);
}

double DriveTrain::getDistance() {
	// Average of both encoders (must negate to get proper direction)
	return ((double) ((leftEncoder->Get()) / ticksToDistance)
			- (double) ((rightEncoder->Get()) / ticksToDistance)) / 2.0;
}

double DriveTrain::getRate() {
	// Average of both encoder rates (must negate to get proper direction)
	// TODO: test to see if negation is necessary
	return ((double) ((leftEncoder->GetRate()) / ticksToDistance)
			- (double) ((rightEncoder->GetRate()) / ticksToDistance)) / 2.0;

}

//may need the Limit method
