#include "subsystems/Swerve.h"
#include "Constants.h"
#include "MathHelper.h"

#include <frc/kinematics/ChassisSpeeds.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/SwerveModuleState.h>
#include <math.h>

Swerve::Swerve() : fl{FRONT_LEFT},
                     fr{FRONT_RIGHT},
                     bl{BACK_LEFT},
                     br{BACK_RIGHT},

                     flRot{FRONT_LEFT_ROT},
                     frRot{FRONT_RIGHT_ROT},
                     blRot{BACK_LEFT_ROT},
                     brRot{BACK_RIGHT_ROT},

                     flEncoder{FRONT_LEFT_ENCODER[0], FRONT_LEFT_ENCODER[1]},
                     frEncoder{FRONT_RIGHT_ENCODER[0], FRONT_RIGHT_ENCODER[1]},
                     blEncoder{BACK_LEFT_ENCODER[0], BACK_LEFT_ENCODER[1]},
                     brEncoder{BACK_RIGHT_ENCODER[0], BACK_RIGHT_ENCODER[1]},

                     flRotEncoder{FRONT_LEFT_ENCODER_ROT[0], FRONT_LEFT_ENCODER_ROT[1]},
                     frRotEncoder{FRONT_RIGHT_ENCODER_ROT[0], FRONT_RIGHT_ENCODER_ROT[1]},
                     blRotEncoder{BACK_LEFT_ENCODER_ROT[0], BACK_LEFT_ENCODER_ROT[1]},
                     brRotEncoder{BACK_RIGHT_ENCODER_ROT[0], BACK_RIGHT_ENCODER_ROT[1]},

                     gyro{GYRO},

                     m_kinematics{FL, FR, BL, BR},
                     m_odometry{m_kinematics, units::radian_t(gyro.GetAngle() * (180 / PI)), frc::Pose2d{0_m, 0_m, 0_rad}},
                     pose{0_m, 0_m, 0_rad}
{
  fr.SetInverted(true);
  br.SetInverted(true);
  frRot.SetInverted(true);
  brRot.SetInverted(true)

  // do i invert the encoders? not sure
  // set distanceperpulse
}

void Swerve::Periodic()
{
  frc::SwerveModuleState wheelSpeeds{units::meters_per_second_t(flEncoder.GetRate()),
                                           units::meters_per_second_t(frEncoder.GetRate()),
                                           units::meters_per_second_t(blEncoder.GetRate()),
                                           units::meters_per_second_t(brEncoder.GetRate())};

  frc::Rotation2d gyroAngle{units::degree_t(-gyro.GetAngle())};

  pose = m_odometry.Update(gyroAngle, wheelSpeeds);
}

void Swerve::Drive(units::meters_per_second_t vx, units::meters_per_second_t vy, units::radians_per_second_t omega)
{
  frc::ChassisSpeeds speeds = frc::ChassisSpeeds::FromFieldRelativeSpeeds(vx, vy, omega, frc::Rotation2d(GetAngleDegrees()));
  frc::SwerveDriveWheelSpeeds wheelSpeeds = m_kinematics.ToWheelSpeeds(speeds);
  wheelSpeeds.Desaturate(MAX_SPEED);
  auto [sfl, sfr, sbl, sbr] = wheelSpeeds;

  fl.Set(sfl / MAX_SPEED);
  fr.Set(sfr / MAX_SPEED);
  bl.Set(sbl / MAX_SPEED);
  br.Set(sbr / MAX_SPEED);
}

void Swerve::DriveVoltages(units::volt_t _fl, units::volt_t _fr, units::volt_t _bl, units::volt_t _br)
{
  fl.SetVoltage(_fl);
  fr.SetVoltage(_fr);
  bl.SetVoltage(_bl);
  br.SetVoltage(_br);
}

void Swerve::DriveJoystick(float lx, float ly, float rx)
{ // in degrees
  Swerve::Drive(units::meters_per_second_t{lx * MAX_SPEED}, units::meters_per_second_t{ly * MAX_SPEED}, units::radians_per_second_t{rx * MAX_ROT_SPEED});
}

// counterclockwise, starting from the right. same as in math.
float Swerve::GetAngle()
{
  float gyroAngle = gyro.GetAngle();
  gyroAngle = std::abs(std::fmod(-gyroAngle + 90, 360));
  return gyroAngle;
}

units::degree_t Swerve::GetAngleDegrees()
{
  return units::degree_t{GetAngle()};
}

frc::Pose2d Swerve::GetPose() {
  return m_odometry.GetPose();
}