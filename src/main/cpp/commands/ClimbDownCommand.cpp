#include "commands/ClimbDownCommand.h"
#include "Constants.h"

ClimbDownCommand::ClimbDownCommand(HangSubsystem *_subsystem) : subsystem(_subsystem) {
    AddRequirements(subsystem);
}

void ClimbDownCommand::Initialize() {
    subsystem->Set(-1);
}

bool ClimbDownCommand::IsFinished() {
    return false;
}

void ClimbDownCommand::End(bool interrupted) {
    subsystem->Set(0);
}