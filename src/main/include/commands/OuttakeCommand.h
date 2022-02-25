#pragma once
#ifndef OUTTAKE_COMMAND_H
#define OUTTAKE_COMMAND_H

#include "subsystems/IntakeSubsystem.h"
#include "subsystems/FeedSubsystem.h"

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class OuttakeCommand : public frc2::CommandHelper<frc2::CommandBase, OuttakeCommand>
{
public:
    explicit OuttakeCommand(IntakeSubsystem *_intakeSubsystem, FeedSubsystem *_feedSubsystem);

    void Execute() override;
    void End(bool interrupted) override;

private:
    IntakeSubsystem *intakeSubsystem;
    FeedSubsystem *feedSubsystem;
};
#endif