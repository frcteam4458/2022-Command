#pragma once
#ifndef FLYWHEEL_WAIT_COMMAND_H
#define FLYWHEEL_WAIT_COMMAND_H

#include "subsystems/ShooterSubsystem.h"

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>

class FlywheelWaitCommand : public frc2::CommandHelper<frc2::CommandBase, FlywheelWaitCommand> {
    public: 
    explicit FlywheelWaitCommand(ShooterSubsystem *_subsystem);

    bool IsFinished() override;
    void End(bool interrupted) override;

    private:
    ShooterSubsystem *subsystem;
};
#endif