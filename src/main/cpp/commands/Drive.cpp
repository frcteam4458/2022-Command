#include "commands/Drive.h"

Drive::Drive(Mecanum *drive) : m_drive(drive) {}

void Drive::Execute()
{
	double rx = rightStick.GetX();
	if(rx < 0.05 && rx > -0.05) rx = 0;
	m_drive->DriveJoystick(-leftStick.GetX(), leftStick.GetY(), rx);
	// fl.Set(1);
	// fr.Set(1);
	// bl.Set(1);
	// br.Set(1);
}