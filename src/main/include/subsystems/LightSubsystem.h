#pragma once
#ifndef LIGHT_SUBSYSTEM_H
#define LIGHT_SUBSYSTEM_H

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/simulation/PWMSim.h>

class LightSubsystem : public frc2::SubsystemBase
{
public:
    LightSubsystem();

    void Set(double set);
    void Periodic() override;
private:
    frc::PWMSparkMax light;
};
#endif