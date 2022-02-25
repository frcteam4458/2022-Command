#include "commands/OuttakeCommand.h"
#include <frc/Joystick.h>

OuttakeCommand::OuttakeCommand(IntakeSubsystem *_intakeSubsystem, FeedSubsystem *_feedSubsystem) : intakeSubsystem(_intakeSubsystem), feedSubsystem(_feedSubsystem)
{
    AddRequirements(intakeSubsystem);
    AddRequirements(feedSubsystem);
}

void OuttakeCommand::Execute() {
    intakeSubsystem->Set(-1);
    feedSubsystem->Set(-1);
}

void OuttakeCommand::End(bool interrupted) {
    intakeSubsystem->Set(-1);
    feedSubsystem->Set(-1);
}