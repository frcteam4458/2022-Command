#pragma once
#ifndef LIGHT_COMMAND_H
#define LIGHT_COMMAND_H

#include "subsystems/LightSubsystem.h"

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>


class LightCommand : public frc2::CommandHelper<frc2::CommandBase, LightCommand>
{
public:
    explicit LightCommand(LightSubsystem *_subsystem);

    void Execute() override;
    void End(bool interrupted) override;
private:
    LightSubsystem *subsystem;
};
#endif