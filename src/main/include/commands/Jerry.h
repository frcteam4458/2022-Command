#pragma once

#ifndef JERRY_H
#define JERRY_H

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/motorcontrol/PWMSparkMax.h>

#include "subsystems/Mecanum.h"

class Jerry : public frc2::CommandHelper<frc2::CommandBase, Jerry>
{
public:
    explicit Jerry(Mecanum *drive);

    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;

private:
    Mecanum *m_drive;
    // frc::PWMSparkMax test;
};
#endif