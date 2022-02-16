#pragma once
#ifndef SHOOTER_SUBSYSTEM_H
#define SHOOTER_SUBSYSTEM_H

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/Encoder.h>

class ShooterSubsystem : public frc2::SubsystemBase
{
public:
  ShooterSubsystem();
  void Set(double power);
  double GetRPM();
private:
  frc::PWMSparkMax motor;
  frc::Encoder encoder;
};
#endif