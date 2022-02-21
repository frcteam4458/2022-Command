#include "commands/FireCommand.h"

FireCommand::FireCommand(LimitSubsystem *subsystem, IntakeCommand intakeCommand, ShooterCommand shooterCommand, FeedCommand feedCommand, LimitWaitCommand limitWaitCommand)
{
    if(subsystem->IsBothPressed()) {
        AddCommands(std::move(intakeCommand), frc2::SequentialCommandGroup{std::move(shooterCommand), std::move(feedCommand), std::move(limitWaitCommand), std::move(feedCommand)});
    } else {
        AddCommands(std::move(intakeCommand), frc2::SequentialCommandGroup{std::move(shooterCommand), std::move(feedCommand)});
    }
}