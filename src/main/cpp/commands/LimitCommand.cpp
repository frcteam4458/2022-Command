#include "commands/LimitCommand.h"
#include <frc/smartdashboard/SmartDashboard.h>

LimitCommand::LimitCommand(LimitSubsystem *_subsystem) : subsystem(_subsystem) {}

void LimitCommand::Execute()
{
	frc::SmartDashboard::PutBoolean("First Switch", subsystem->IsFirstPressed());
    frc::SmartDashboard::PutBoolean("Second Switch", subsystem->IsSecondPressed());
}