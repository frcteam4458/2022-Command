#include "commands/IntakeCommand.h"
#include <frc/Joystick.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>

IntakeCommand::IntakeCommand(IntakeSubsystem *_subsystem) : subsystem(_subsystem)
{
    AddRequirements(subsystem);
}

void IntakeCommand::Execute() {
    subsystem->Set(1);
    // frc::Shuffleboard::GetTab("Telemetry").Add("Intake Command", true).WithWidget(frc::BuiltInWidgets::kBooleanBox);
}

void IntakeCommand::End(bool interrupted) {
    subsystem->Set(0);
    // frc::Shuffleboard::GetTab("Telemetry").Add("Intake Command", false).WithWidget(frc::BuiltInWidgets::kBooleanBox);
}