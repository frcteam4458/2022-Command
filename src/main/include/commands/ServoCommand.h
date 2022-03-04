#pragma once
#ifndef SERVO_COMMAND_H
#define SERVO_COMMAND_H

#include "subsystems/ServoSubsystem.h"

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class ServoCommand : public frc2::CommandHelper<frc2::CommandBase, ServoCommand>
{
public:
    explicit ServoCommand(ServoSubsystem *_subsystem, double _position);

    void Initialize() override;
    bool IsFinished() override;

private:
    ServoSubsystem *subsystem;
    double position;
};
#endif