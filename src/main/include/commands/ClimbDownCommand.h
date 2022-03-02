#pragma once
#ifndef CLIMB_DOWN_COMMAND_H
#define CLIMB_DOWN_COMMAND_H

#include "subsystems/HangSubsystem.h"

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>

class ClimbDownCommand : public frc2::CommandHelper<frc2::CommandBase, ClimbDownCommand> {
    public: 
    explicit ClimbDownCommand(HangSubsystem *_subsystem);

    void Initialize() override;
    bool IsFinished() override;
    void End(bool interrupted) override;

    private:
    HangSubsystem *subsystem;
};
#endif