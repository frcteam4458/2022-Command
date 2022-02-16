#include "commands/IntakeCommand.h"
#include <frc/Joystick.h>
#include <frc/smartdashboard/SmartDashboard.h>

IntakeCommand::IntakeCommand(IntakeSubsystem *_subsystem) : subsystem(_subsystem)
{
    
}

void IntakeCommand::Execute() {
    (*subsystem).Set(1);
}

void IntakeCommand::End(bool interrupted) {
    (*subsystem).Set(0);
}