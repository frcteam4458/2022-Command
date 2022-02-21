#include "commands/LimitWaitCommand.h"

LimitWaitCommand::LimitWaitCommand(LimitSubsystem *_subsystem) : subsystem(_subsystem) {}

bool LimitWaitCommand::IsFinished() {
    if(subsystem->IsFirstPressed()) return true;
    return false;
}