#pragma once
#ifndef FEED_SUBSYSTEM_H
#define FEED_SUBSYSTEM_H

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMSparkMax.h>

class FeedSubsystem : public frc2::SubsystemBase
{
public:
    FeedSubsystem();
    void Set(double power);

private:
    frc::PWMSparkMax feedMotor;
};
#endif