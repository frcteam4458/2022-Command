#include "commands/AutoDrive.h"

AutoDrive::AutoDrive(Mecanum *drive) : m_drive(drive)
{
	AddRequirements(drive);
}

void AutoDrive::Initialize() {}

void AutoDrive::Execute()
{
	// m_drive->Drive(1_mps, 0_mps, units::radians_per_second_t(0.5f));
}

bool AutoDrive::IsFinished()
{
	return true;
	// return m_drive->GetPose().X() >= 2_m;
}