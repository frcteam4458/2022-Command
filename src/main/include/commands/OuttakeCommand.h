#pragma once
#ifndef OUTTAKE_COMMAND_H
#define OUTTAKE_COMMAND_H

#include "subsystems/IntakeSubsystem.h"

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class OuttakeCommand : public frc2::CommandHelper<frc2::CommandBase, OuttakeCommand>
{
public:
    explicit OuttakeCommand(IntakeSubsystem *_subsystem);

    void Execute() override;
    void End(bool interrupted) override;

private:
    IntakeSubsystem *subsystem;
};
#endif