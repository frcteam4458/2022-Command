#include "subsystems/Mecanum.h"
#include "Constants.h"
#include "MathHelper.h"

#include <frc/kinematics/ChassisSpeeds.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/MecanumDriveWheelSpeeds.h>
#include <math.h>

// note to future programmers: this is the worst file i promise

Mecanum::Mecanum() : fl{FRONT_LEFT},
                     fr{FRONT_RIGHT},
                     bl{BACK_LEFT},
                     br{BACK_RIGHT},

                     flEncoder{FRONT_LEFT_ENCODER[0], FRONT_LEFT_ENCODER[1]},
                     frEncoder{FRONT_RIGHT_ENCODER[0], FRONT_RIGHT_ENCODER[1]},
                     blEncoder{BACK_LEFT_ENCODER[0], BACK_LEFT_ENCODER[1]},
                     brEncoder{BACK_RIGHT_ENCODER[0], BACK_RIGHT_ENCODER[1]},

                     gyro{GYRO},

                     m_kinematics{FL, FR, BL, BR}, // these refer to physical locations set in Constants.h
                     m_odometry{m_kinematics, units::radian_t(0_rad), frc::Pose2d{0_m, 0_m, 0_rad}},
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

  pose = m_odometry.Update(frc::Rotation2d{GetAngleDegrees()}, wheelSpeeds);
}

void Mecanum::Drive(units::meters_per_second_t vx, units::meters_per_second_t vy, units::radians_per_second_t omega)
{
  frc::ChassisSpeeds speeds = frc::ChassisSpeeds::FromFieldRelativeSpeeds(vx, vy, omega, frc::Rotation2d(GetAngleDegrees()));
  frc::MecanumDriveWheelSpeeds wheelSpeeds = m_kinematics.ToWheelSpeeds(speeds);
  wheelSpeeds.Desaturate(MAX_SPEED); // this makes sure nothing is over MAX_SPEED
  auto [sfl, sfr, sbl, sbr] = wheelSpeeds;

  fl.Set(sfl / MAX_SPEED); // dividing by MAX_SPEED normalizes them
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
  Mecanum::Drive(units::meters_per_second_t{lx * MAX_SPEED}, units::meters_per_second_t{ly * MAX_SPEED}, units::radians_per_second_t{rx * MAX_ROT_SPEED});
}

// counterclockwise, starting from the right. same as in math.
float Mecanum::GetAngle()
{
  float gyroAngle = gyro.GetAngle();
  extern float gyroOffset;
  gyroAngle = std::abs(std::fmod((-gyroAngle + 90) + gyroOffset, 360)); // this converts from clockwise starting at north to counterclockwise starting at east, which is more
  return gyroAngle;                                                     // mathematical
}

units::degree_t Mecanum::GetAngleDegrees()
{
  return units::degree_t{GetAngle()};
}

units::radian_t Mecanum::GetAngleRadians()
{
  return units::radian_t{GetAngle() / (180/PI)};
}

frc::Pose2d Mecanum::GetPose()
{
  return m_odometry.GetPose();
}