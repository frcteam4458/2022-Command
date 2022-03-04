#pragma once
#ifndef SHOOTER_SUBSYSTEM_H
#define SHOOTER_SUBSYSTEM_H

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/DutyCycleEncoder.h>
#include <frc/simulation/DutyCycleEncoderSim.h>
#include <frc/simulation/PWMSim.h>

#include <cmath>
#include <math.h>

class ShooterSubsystem : public frc2::SubsystemBase
{
public:
  ShooterSubsystem();
  void Periodic() override;
  void SimulationPeriodic() override;
  void Set(double power);
  void SetRPM(double _rpm);
  double Get();
  double GetRPM();
  double GetTargetRPM();
private:
  frc::PWMSparkMax motor;
  frc::DutyCycleEncoder encoder;
  frc::sim::PWMSim s_motor;
  frc::sim::DutyCycleEncoderSim s_encoder;
  double rpm = NAN;
  double encoderRpm = 0;
  double encoderPrev = 0;
  double distance = 0; // for sim
  int c = 0;
};
#endif