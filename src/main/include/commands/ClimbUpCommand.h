#pragma once
#ifndef CLIMB_UP_COMMAND_H
#define CLIMB_UP_COMMAND_H

#include "subsystems/HangSubsystem.h"

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>

class ClimbUpCommand : public frc2::CommandHelper<frc2::CommandBase, ClimbUpCommand> {
    public: 
    explicit ClimbUpCommand(HangSubsystem *_subsystem);

    void Initialize() override;
    bool IsFinished() override;
    void End(bool interrupted) override;

    private:
    HangSubsystem *subsystem;
};
#endif