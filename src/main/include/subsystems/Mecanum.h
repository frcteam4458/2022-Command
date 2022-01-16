#pragma once
#ifndef MECANUM_H
#define MECANUM_H

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/simulation/PWMSim.h>
#include <frc/kinematics/MecanumDriveKinematics.h>
#include <frc/kinematics/MecanumDriveOdometry.h>

#include <frc/AnalogGyro.h>
#include <frc/Encoder.h>
#include <frc/simulation/EncoderSim.h>

class Mecanum : public frc2::SubsystemBase
{
public:
  Mecanum();
  void Periodic() override;
  void Drive(units::meters_per_second_t vx, units::meters_per_second_t vy, units::radians_per_second_t omega);
  void DriveJoystick(float lx, float ly, float rx);
  void DriveVoltages(units::volt_t fl, units::volt_t fr, units::volt_t bl, units::volt_t br);

  float GetAngle();
  units::degree_t GetAngleDegrees();
  units::radian_t GetAngleRadians();

  frc::Pose2d GetPose();

private:
  frc::PWMSparkMax fl;
  frc::PWMSparkMax fr;
  frc::PWMSparkMax bl;
  frc::PWMSparkMax br;

  frc::sim::PWMSim s_fl;
  frc::sim::PWMSim s_fr;
  frc::sim::PWMSim s_bl;
  frc::sim::PWMSim s_br;

  // frc::sim::EncoderSim s_flEncoder;
  // frc::sim::EncoderSim s_frEncoder;
  // frc::sim::EncoderSim s_blEncoder;
  // frc::sim::EncoderSim s_brEncoder;

  // frc::Encoder flEncoder;
  // frc::Encoder frEncoder;
  // frc::Encoder blEncoder;
  // frc::Encoder brEncoder;

  frc::AnalogGyro gyro;

  frc::MecanumDriveKinematics m_kinematics;
  // frc::MecanumDriveOdometry m_odometry;

  frc::Pose2d pose;
};
#endif