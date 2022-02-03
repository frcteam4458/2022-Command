#pragma once
#ifndef HANG_SUBSYSTEM_H
#define HANG_SUBSYSTEM_H

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMSparkMax.h>

class HangSubsystem : public frc2::SubsystemBase
{
public:
    HangSubsystem();

    void Set(double power);
private:
    frc::PWMSparkMax leftArm;
    frc::PWMSparkMax rightArm;
};
#endif