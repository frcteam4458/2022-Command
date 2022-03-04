#include "commands/ServoCommand.h"
#include <frc/Joystick.h>

ServoCommand::ServoCommand(ServoSubsystem *_subsystem, double _position) : subsystem(_subsystem)
{
    AddRequirements(subsystem);
    position = _position;
}

void ServoCommand::Initialize() {
    subsystem->Set(position);
}

bool ServoCommand::IsFinished() {
    return true;
}