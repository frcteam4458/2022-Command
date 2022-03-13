#pragma once
#ifndef HANG_SUBSYSTEM_H
#define HANG_SUBSYSTEM_H

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/DutyCycleEncoder.h>

class HangSubsystem : public frc2::SubsystemBase
{
public:
    HangSubsystem();

    void Set(double power);
    void Periodic() override;
    void ResetEncoder();
private:
    frc::PWMSparkMax climber;
    frc::DutyCycleEncoder encoder;
    double power = 0;
    bool reset = false;
};
#endif