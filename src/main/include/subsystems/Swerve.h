#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <frc/kinematics/SwerveDriveOdometry.h>

#include <frc/AnalogGyro.h>
#include <frc/Encoder.h>

class Swerve : public frc2::SubsystemBase {
  public:
    Swerve();
    void Periodic() override;
    void Drive(units::meters_per_second_t vx, units::meters_per_second_t vy, units::radians_per_second_t omega);
    void DriveJoystick(float lx, float ly, float rx);
    void DriveVoltages(units::volt_t fl, units::volt_t fr, units::volt_t bl, units::volt_t br);

    float GetAngle();
    units::degree_t GetAngleDegrees();

    frc::Pose2d GetPose();

  private:
    frc::PWMSparkMax fl;
    frc::PWMSparkMax fr;
    frc::PWMSparkMax bl;
    frc::PWMSparkMax br;

    frc::PWMSparkMax flRot;
    frc::PWMSparkMax frRot;
    frc::PWMSparkMax blRot;
    frc::PWMSparkMax brRot;

    frc::Encoder flEncoder;
    frc::Encoder frEncoder;
    frc::Encoder blEncoder;
    frc::Encoder brEncoder;

    frc::Encoder flRotEncoder;
    frc::Encoder frRotEncoder;
    frc::Encoder blRotEncoder;
    frc::Encoder brRotEncoder;

    frc::AnalogGyro gyro;

    frc::SwerveDriveKinematics m_kinematics;
    frc::SwerveDriveOdometry m_odometry;

    frc::Pose2d pose;
};
