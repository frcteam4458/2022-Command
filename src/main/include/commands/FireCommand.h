#include "commands/IntakeCommand.h"
#include "commands/FeedCommand.h"
#include "commands/ShooterCommand.h"
#include "commands/LimitWaitCommand.h"
#include "subsystems/LimitSubsystem.h"

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/SequentialCommandGroup.h>


class FireCommand : public frc2::CommandHelper<frc2::ParallelRaceGroup, FireCommand> {
    FireCommand(LimitSubsystem *subsystem, IntakeCommand intakeCommand, ShooterCommand shooterCommand, FeedCommand feedCommand, LimitWaitCommand limitWaitCommand);
};