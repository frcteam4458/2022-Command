#pragma once
#ifndef SHOOTER_SUBSYSTEM_H
#define SHOOTER_SUBSYSTEM_H

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/Encoder.h>
#include <frc/simulation/PWMSim.h>

class ShooterSubsystem : public frc2::SubsystemBase
{
public:
  ShooterSubsystem();
  void Periodic() override;
  void Set(double power);
  void SetRPM(double _rpm);
  double Get();
  double GetRPM();
  double GetTargetRPM();
private:
  frc::PWMSparkMax motor;
  frc::Encoder encoder;
  frc::sim::PWMSim s_motor;
  double rpm = 0;
};
#endif