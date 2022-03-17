#include "commands/AutoDrive.h"

AutoDrive::AutoDrive(Mecanum *drive) : m_drive(drive)
{
	AddRequirements(drive);
}

void AutoDrive::Initialize() {}

void AutoDrive::Execute()
{
	m_drive->DriveVoltages(4_V, 4_V, 4_V, 4_V);
}

bool AutoDrive::IsFinished()
{
	return false;
	// return m_drive->GetPose().X() >= 2_m;
}

void AutoDrive::End(bool interrupted) {
	m_drive->DriveVoltages(0_V, 0_V, 0_V, 0_V);
}