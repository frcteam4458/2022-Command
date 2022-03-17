#include "commands/FireCommand.h"
#include <frc/smartdashboard/SmartDashboard.h>
FireCommand::FireCommand(LimitSubsystem *subsystem, IntakeCommand intakeCommand, ShooterCommand shooterCommand, FeedCommand feedCommand, LimitWaitCommand limitWaitCommand, FlywheelWaitCommand flywheelWaitCommand)
{
    // if(subsystem->IsBothPressed()) {
    //     AddCommands(std::move(intakeCommand), frc2::SequentialCommandGroup{std::move(intakeCommand), std::move(flywheelWaitCommand), std::move(feedCommand), std::move(limitWaitCommand), std::move(feedCommand)});
    // } else {
    //     AddCommands(std::move(intakeCommand), frc2::SequentialCommandGroup{std::move(intakeCommand), std::move(flywheelWaitCommand), std::move(feedCommand)});
    // }
    AddCommands(std::move(shooterCommand));
}
double a = 0;
void FireCommand::Execute() {
}

void FireCommand::End(bool interrupted) {
    // frc::SmartDashboard::PutBoolean("Firing over", true);
}