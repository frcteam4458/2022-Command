#pragma once
#ifndef INTAKE_COMMAND_H
#define INTAKE_COMMAND_H

#include "subsystems/IntakeSubsystem.h"

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class IntakeCommand : public frc2::CommandHelper<frc2::CommandBase, IntakeCommand>
{
public:
    explicit IntakeCommand(IntakeSubsystem *_subsystem);

    void Execute() override;
    void End(bool interrupted) override;

private:
    IntakeSubsystem *subsystem;
};
#endif