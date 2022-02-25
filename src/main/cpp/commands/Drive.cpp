#include "commands/Drive.h"

#include <frc/smartdashboard/SmartDashboard.h>

Drive::Drive(Mecanum *drive) : m_drive(drive) {
	AddRequirements(drive);
}

void Drive::Initialize() {
	m_drive->ResetAngle();	
}

void Drive::Execute()
{
	double rx = rightStick.GetX();
	double xboxRx = xboxController.GetRawAxis(2);
	xboxRx *= 0.75;
	// if(rx < 0.05 && rx > -0.05) rx = 0;
	m_drive->DriveJoystick(-leftStick.GetX(), leftStick.GetY(), xboxRx, 0.05); // 0.05 deadzone

	frc::SmartDashboard::PutNumber("Xbox LX", xboxController.GetLeftX());
	frc::SmartDashboard::PutNumber("Xbox LY", xboxController.GetLeftY());
	frc::SmartDashboard::PutNumber("Xbox RX", xboxController.GetRightX());
}