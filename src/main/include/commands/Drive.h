#pragma once
#ifndef DRIVE_H
#define DRIVE_H

#include <frc/XboxController.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/Joystick.h>

#include "subsystems/Mecanum.h"

class Drive : public frc2::CommandHelper<frc2::CommandBase, Drive>
{
public:
    explicit Drive(Mecanum *drive);

    void Execute() override;

private:
    Mecanum *m_drive;
    frc::XboxController xboxController{0};

    frc::Joystick leftStick{0};
    frc::Joystick rightStick{1};

    // frc::PWMSparkMax fl{0};
    // frc::PWMSparkMax fr{1};
    // frc::PWMSparkMax bl{2};
    // frc::PWMSparkMax br{3};
};
#endif