#pragma once
#ifndef LIMIT_WAIT_COMMAND_H
#define LIMIT_WAIT_COMMAND_H

#include "subsystems/LimitSubsystem.h"

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>

class LimitWaitCommand : public frc2::CommandHelper<frc2::CommandBase, LimitWaitCommand> {
    public:
    explicit LimitWaitCommand(LimitSubsystem *_subsystem);

    bool IsFinished() override;

    private:
    LimitSubsystem *subsystem;
};
#endif