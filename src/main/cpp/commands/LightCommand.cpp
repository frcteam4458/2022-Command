#include "commands/LightCommand.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <math.h>
#include <iostream>

LightCommand::LightCommand(LightSubsystem *_subsystem) : subsystem(_subsystem) {
	AddRequirements(subsystem);
}

void LightCommand::Execute()
{
	subsystem->Set(0.9);
}

void LightCommand::End(bool interrupted) {
	subsystem->Set(0.0);
}
