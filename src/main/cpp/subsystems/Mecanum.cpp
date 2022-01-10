#include "subsystems/Mecanum.h"
#include "Constants.h"
#include "MathHelper.h"

#include <frc/kinematics/ChassisSpeeds.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/MecanumDriveWheelSpeeds.h>
#include <math.h>

Mecanum::Mecanum() : fl{FRONT_LEFT},
                     fr{FRONT_RIGHT},
                     bl{BACK_LEFT},
                     br{BACK_RIGHT},

                     flEncoder{FRONT_LEFT_ENCODER[0], FRONT_LEFT_ENCODER[1]},
                     frEncoder{FRONT_RIGHT_ENCODER[0], FRONT_RIGHT_ENCODER[1]},
                     blEncoder{BACK_LEFT_ENCODER[0], BACK_LEFT_ENCODER[1]},
                     brEncoder{BACK_RIGHT_ENCODER[0], BACK_RIGHT_ENCODER[1]},

                     gyro{GYRO},

                     m_kinematics{FL, FR, BL, BR},
                     m_odometry{m_kinematics, units::radian_t(gyro.GetAngle() * (180 / PI)), frc::Pose2d{0_m, 0_m, 0_rad}},
                     pose{0_m, 0_m, 0_rad}
{
  fr.SetInverted(true);
  br.SetInverted(true);

  // do i invert the encoders? not sure
  // set distanceperpulse
}

void Mecanum::Periodic()
{
  frc::MecanumDriveWheelSpeeds wheelSpeeds{units::meters_per_second_t(flEncoder.GetRate()),
                                           units::meters_per_second_t(frEncoder.GetRate()),
                                           units::meters_per_second_t(blEncoder.GetRate()),
                                           units::meters_per_second_t(brEncoder.GetRate())};

  frc::Rotation2d gyroAngle{units::degree_t(-gyro.GetAngle())};

  pose = m_odometry.Update(gyroAngle, wheelSpeeds);
}

void Mecanum::Drive(units::meters_per_second_t vx, units::meters_per_second_t vy, units::degrees_per_second_t omega)
{
  frc::ChassisSpeeds speeds = frc::ChassisSpeeds::FromFieldRelativeSpeeds(units::meters_per_second_t(vx * MAX_SPEED), units::meters_per_second_t(vy * MAX_SPEED),
                                                                          units::degrees_per_second_t(omega * MAX_ROT_SPEED),
                                                                          frc::Rotation2d(units::degree_t(std::fmod(GetAngle(), 360.0f))));
  frc::MecanumDriveWheelSpeeds wheelSpeeds = m_kinematics.ToWheelSpeeds(speeds);
  wheelSpeeds.Desaturate(MAX_SPEED);
  auto [sfl, sfr, sbl, sbr] = wheelSpeeds;

  fl.Set(sfl / MAX_SPEED);
  fr.Set(sfr / MAX_SPEED);
  bl.Set(sbl / MAX_SPEED);
  br.Set(sbr / MAX_SPEED);
}

void Mecanum::DriveVoltages(units::volt_t _fl, units::volt_t _fr, units::volt_t _bl, units::volt_t _br)
{
  fl.SetVoltage(_fl);
  fr.SetVoltage(_fr);
  bl.SetVoltage(_bl);
  br.SetVoltage(_br);
}

void Mecanum::DriveJoystick(float lx, float ly, float rx)
{ // in degrees
  Mecanum::Drive(units::meters_per_second_t{MAX_SPEED}, units::meters_per_second_t{ly * MAX_SPEED}, units::meters_per_second_t{rx * MAX_ROT_SPEED});
}

// counterclockwise, starting from the right. same as in math.
float Mecanum::GetAngle()
{
  float gyroAngle = gyro.GetAngle();
  gyroAngle = std::abs(std::fmod(-gyroAngle + 90, 360));
  return gyroAngle;
}