#pragma once
#ifndef LIMIT_COMMAND_H
#define LIMIT_COMMAND_H

#include "subsystems/LimitSubsystem.h"

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h> 

class LimitCommand : public frc2::CommandHelper<frc2::CommandBase, LimitCommand>
{
public:
    explicit LimitCommand(LimitSubsystem *_subsystem);

    void Execute() override;
private:
    LimitSubsystem *subsystem;
};
#endif