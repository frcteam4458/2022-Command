#include "commands/FeedCommand.h"
#include <frc/Joystick.h>
#include <frc/smartdashboard/SmartDashboard.h>

FeedCommand::FeedCommand(FeedSubsystem *_subsystem) : subsystem(_subsystem)
{
    
}

void FeedCommand::Execute() {
    (*subsystem).Set(1);
}

void FeedCommand::End(bool interrupted) {
    (*subsystem).Set(0);
}