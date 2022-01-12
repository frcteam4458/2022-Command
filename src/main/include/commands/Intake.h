#pragma once

#ifndef INTAKE_H
#define INTAKE_H

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <frc/motorcontrol/PWMSparkMax.h>

class Intake : public frc2::CommandHelper<frc2::CommandBase, Intake>
{
public:
    Intake();

    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;

// private:
//     frc::PWMSparkMax intake;
};
#endif