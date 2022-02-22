#include "commands/IntakeCommand.h"
#include <frc/Joystick.h>
#include <frc/smartdashboard/SmartDashboard.h>

IntakeCommand::IntakeCommand(IntakeSubsystem *_subsystem) : subsystem(_subsystem)
{
    AddRequirements(subsystem);
}

void IntakeCommand::Execute() {
    subsystem->Set(1);
    frc::SmartDashboard::PutBoolean("intake on", true);
}

void IntakeCommand::End(bool interrupted) {
    subsystem->Set(0);
    frc::SmartDashboard::PutBoolean("intake on", false);
}

bool IntakeCommand::IsFinished() { return false; }