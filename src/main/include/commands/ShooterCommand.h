#pragma once
#ifndef SHOOTER_COMMAND_H
#define SHOOTER_COMMAND_H

#include "subsystems/ShooterSubsystem.h"

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <frc/Joystick.h>

class ShooterCommand : public frc2::CommandHelper<frc2::CommandBase, ShooterCommand>
{
public:
    explicit ShooterCommand(ShooterSubsystem *_subsystem);

    void Execute() override;
    void End(bool interrupted) override;

private:
    // frc::Joystick joystick{0};
    ShooterSubsystem *subsystem;
    double power = 0;

    frc::Joystick rightStick{1};
};
#endif