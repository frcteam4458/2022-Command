#include "commands/Drive.h"

Drive::Drive(Mecanum *drive) : m_drive{drive} {}

void Drive::Execute()
{
	m_drive->DriveJoystick(leftStick.GetX(), leftStick.GetY(), rightStick.GetX());
}