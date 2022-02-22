#pragma once
#ifndef LIMIT_SUBSYSTEM_H
#define LIMIT_SUBSYSTEM_H

#include <frc2/command/SubsystemBase.h>
#include <frc/DigitalInput.h>
#include "Constants.h"

class LimitSubsystem : public frc2::SubsystemBase
{
public:
    LimitSubsystem();

    bool IsFirstPressed();
    bool IsSecondPressed();
    bool IsBothPressed();
    void Periodic() override;
private:
    frc::DigitalInput first{FIRST_SWITCH};
    frc::DigitalInput second{SECOND_SWITCH};
};
#endif