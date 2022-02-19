#include "commands/SolenoidToggle.h"

SolenoidToggle::SolenoidToggle(SolenoidSubsystem *_subsystem) : subsystem{_subsystem}
{
	AddRequirements(subsystem);
}

void SolenoidToggle::Execute()
{
	subsystem->Toggle();
}

bool SolenoidToggle::IsFinished()
{
	return true;
}