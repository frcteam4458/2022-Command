#pragma once
#ifndef SOLENOID_TOGGLE_H
#define SOLENOID_TOGGLE_H

#include "subsystems/SolenoidSubsystem.h"

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <frc/Joystick.h>


class SolenoidToggle : public frc2::CommandHelper<frc2::CommandBase, SolenoidToggle>
{
public:
    explicit SolenoidToggle(SolenoidSubsystem *_subsystem);

    void Execute() override;
    bool IsFinished() override;

private:
    SolenoidSubsystem *subsystem;
};
#endif