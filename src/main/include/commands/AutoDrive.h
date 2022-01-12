#pragma once

#ifndef INTAKE_H
#define INTAKE_H

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/motorcontrol/PWMSparkMax.h>

#include "subsystems/Mecanum.h"

class Intake : public frc2::CommandHelper<frc2::CommandBase, Intake>
{
public:
    explicit Intake();

    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;

private:
    frc::PWMSparkMax test;
};
#endif