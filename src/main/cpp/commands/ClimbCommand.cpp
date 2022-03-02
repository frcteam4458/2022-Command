#include "commands/ClimbCommand.h"
#include "Constants.h"

ClimbCommand::ClimbCommand(HangSubsystem *_subsystem) : subsystem(_subsystem) {
    AddRequirements(subsystem);
}

void ClimbCommand::Execute() {
    subsystem->Set(-joystick.GetY());
}

bool ClimbCommand::IsFinished() {
    return false;
}

void ClimbCommand::End(bool interrupted) {
    subsystem->Set(0);
}