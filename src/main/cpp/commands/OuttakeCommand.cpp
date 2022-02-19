#include "commands/OuttakeCommand.h"
#include <frc/Joystick.h>

OuttakeCommand::OuttakeCommand(IntakeSubsystem *_subsystem) : subsystem(_subsystem)
{
    AddRequirements(subsystem);
}

void OuttakeCommand::Execute() {
    subsystem->Set(-1);
}

void OuttakeCommand::End(bool interrupted) {
    subsystem->Set(0);
}