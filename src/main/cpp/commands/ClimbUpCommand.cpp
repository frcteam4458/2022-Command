#include "commands/ClimbUpCommand.h"
#include "Constants.h"

ClimbUpCommand::ClimbUpCommand(HangSubsystem *_subsystem) : subsystem(_subsystem) {
    AddRequirements(subsystem);
}

void ClimbUpCommand::Initialize() {
    subsystem->Set(1);
}

bool ClimbUpCommand::IsFinished() {
    return false;
}

void ClimbUpCommand::End(bool interrupted) {
    subsystem->Set(0);
}