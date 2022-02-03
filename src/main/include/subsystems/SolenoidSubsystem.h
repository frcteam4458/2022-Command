#pragma once
#ifndef SOLENOID_SUBSYSTEM_H
#define SOLENOID_SUBSYSTEM_H

#include <frc2/command/SubsystemBase.h>
#include <frc/Solenoid.h>
#include <frc/PneumaticsModuleType.h>   

class SolenoidSubsystem : public frc2::SubsystemBase
{
public:
    SolenoidSubsystem(frc::PneumaticsModuleType moduleType);

    void Set(bool set);
    bool Toggle();
private:
    frc::Solenoid leftSolenoid;
    frc::Solenoid rightSolenoid;
};
#endif