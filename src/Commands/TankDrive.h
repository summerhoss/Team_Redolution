#ifndef TankDrive_H
#define TankDrive_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Talon.h"
#include "../Utilities/WVPIDController.h"

class TankDrive : public CommandBase {
public:
	TankDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	WVPIDController* Pid;
	bool isFinished;
};

#endif  // TankDrive_H
