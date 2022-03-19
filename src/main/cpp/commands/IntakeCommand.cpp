#include "commands/IntakeCommand.h"
#include <frc/Joystick.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>

#include <networktables/NetworkTableEntry.h>


nt::NetworkTableEntry intakeCommandStatus;
IntakeCommand::IntakeCommand(IntakeSubsystem *_subsystem) : subsystem(_subsystem)
{
    AddRequirements(subsystem);
    intakeCommandStatus = frc::Shuffleboard::GetTab("Telemetry").Add("Intake Command", true).WithWidget(frc::BuiltInWidgets::kBooleanBox).GetEntry();
}

void IntakeCommand::Execute() {
    subsystem->Set(1);
    intakeCommandStatus.SetBoolean(true);
}

void IntakeCommand::End(bool interrupted) {
    subsystem->Set(0);
    intakeCommandStatus.SetBoolean(false);
}