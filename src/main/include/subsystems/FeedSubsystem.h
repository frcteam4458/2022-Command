#pragma once
#ifndef FEED_SUBSYSTEM_H
#define FEED_SUBSYSTEM_H

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/Encoder.h>
#include <frc/simulation/PWMSim.h>
#include <frc/simulation/EncoderSim.h>

class FeedSubsystem : public frc2::SubsystemBase
{
public:
    FeedSubsystem();
    void Set(double power);
    double GetPosition();

    void SimulationPeriodic() override;

private:
    frc::PWMSparkMax feedMotor;
    frc::sim::PWMSim s_feedMotor;
    frc::Encoder encoder;
    frc::sim::EncoderSim s_encoder;
};
#endif