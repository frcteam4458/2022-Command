#include "commands/Drive.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <math.h>


Drive::Drive(Mecanum *drive) : m_drive(drive) {
	AddRequirements(drive);
}

void Drive::Initialize() {
	m_drive->ResetAngle();	
}

double lx;
double ly;
double rx;
double xboxRx;

void Drive::Execute()
{
	lx = leftStick.GetX();
	ly = leftStick.GetY();
	rx = rightStick.GetX();
	xboxRx = xboxController.GetRawAxis(2);

	lx *= 0.75;
	ly *= 0.75;

	if(xboxController.GetRawButton(10)) xboxRx *= 0.1; 
	else xboxRx *= 0.25;
	// lx = std::pow(lx, 3.0);
	// ly = std::pow(ly, 3.0);
	// rx = std::pow(rx, 3.0);
	// xboxRx = std::pow(xboxRx, 3.0);
	// xboxRx *= 0.75;
	// if(rx < 0.05 && rx > -0.05) rx = 0;
	m_drive->DriveJoystick(-leftStick.GetX(), leftStick.GetY()/2, xboxRx, 0.00); // no deadzone

	// if(secondPlayer.GetRawButtonPressed(8)) m_drive->ResetAngle();
}

void Drive::End(bool interrupted)
{
	m_drive->DriveVoltages(0_V, 0_V, 0_V, 0_V);
}