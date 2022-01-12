#include "commands/Jerry.h"

Jerry::Jerry(Mecanum *drive) : m_drive(drive)//, test{0}
{
	AddRequirements(drive);
}

void Jerry::Initialize()
{
}

void Jerry::Execute()
{
	m_drive->Drive(1_mps, 0_mps, units::radians_per_second_t(0.5f));
}

bool Jerry::IsFinished()
{
	return m_drive->GetPose().X() >= 2_m;
}