#pragma once
#ifndef CLIMB_COMMAND_H
#define CLIMB_COMMAND_H

#include "subsystems/HangSubsystem.h"

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>

#include <frc/Joystick.h>

class ClimbCommand : public frc2::CommandHelper<frc2::CommandBase, ClimbCommand> {
    public: 
    explicit ClimbCommand(HangSubsystem *_subsystem);

    void Execute() override;
    bool IsFinished() override;
    void End(bool interrupted) override;

    private:
    HangSubsystem *subsystem;
    frc::Joystick joystick{2};
};  
#endif