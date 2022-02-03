#pragma once
#ifndef INTAKE_SUBSYSTEM_H
#define INTAKE_SUBSYSTEM_H

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMSparkMax.h>

class IntakeSubsystem : public frc2::SubsystemBase
{
public:
    IntakeSubsystem();

    void Set(double set);
private:
    frc::PWMSparkMax intakeMotor;
};
#endif