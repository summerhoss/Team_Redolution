#include "TankDrive.h"

TankDrive::TankDrive() {
	Requires(drive);

}

// Called just before this Command runs the first time
void TankDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute() {
	double yLeftRaw = oi->getLeftStick()->GetY();
	double yRightRaw = oi->getRightStick()->GetY();

	//drive->tankDrive(-yLeftAdjusted, -yRightAdjusted);
	//need to fix this
}

// Make this return true when this Command no longer needs to run execute()
bool TankDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TankDrive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDrive::Interrupted() {

}
