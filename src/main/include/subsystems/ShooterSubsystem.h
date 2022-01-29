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
  // void SetLeft(double power);
  // void SetRight(double power);
  void Set(double power);
  void Zero();
private:
  // frc::PWMSparkMax left;
  // frc::PWMSparkMax right;
  frc::PWMSparkMax motor;
};
#endif