#include "commands/Drive.h"

Drive::Drive(Mecanum *drive) : m_drive(drive) {
	AddRequirements(drive);
}

void Drive::Initialize() {
	m_drive->ResetAngle();	
}

void Drive::Execute()
{
	double rx = rightStick.GetX();
	// if(rx < 0.05 && rx > -0.05) rx = 0;
	// m_drive->DriveJoystick(-leftStick.GetX(), leftStick.GetY(), rx, 0.05); // 0.05 deadzone
}