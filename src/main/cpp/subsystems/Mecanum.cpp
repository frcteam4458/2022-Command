#include "subsystems/Mecanum.h"
#include "Constants.h"
#include "MathHelper.h"

#include <frc/kinematics/ChassisSpeeds.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/MecanumDriveWheelSpeeds.h>
#include <math.h>
#include <frc/shuffleboard/Shuffleboard.h>

#include <frc/drive/MecanumDrive.h>
#include <wpi/StringMap.h>

#include <frc2/command/PrintCommand.h>

#include <frc/smartdashboard/SmartDashboard.h>

#include <frc/Encoder.h>

// note to future programmers: this is the worst file i promise

Mecanum::Mecanum() : fl{FRONT_LEFT}, s_fl{FRONT_LEFT},
                     fr{FRONT_RIGHT}, s_fr{FRONT_RIGHT},
                     bl{BACK_LEFT}, s_bl{BACK_LEFT},
                     br{BACK_RIGHT}, s_br{BACK_RIGHT},

                     flEncoder{FRONT_LEFT_ENCODER[0], FRONT_LEFT_ENCODER[1]},
                     frEncoder{FRONT_RIGHT_ENCODER[0], FRONT_RIGHT_ENCODER[1]},
                     blEncoder{BACK_LEFT_ENCODER[0], BACK_LEFT_ENCODER[1]},
                     brEncoder{BACK_RIGHT_ENCODER[0], BACK_RIGHT_ENCODER[1]},

                     gyro{1},

                     m_kinematics{FL, FR, BL, BR}, // these refer to physical locations set in Constants.h
                     m_odometry{m_kinematics, units::radian_t(0_rad), frc::Pose2d{0_m, 0_m, 0_rad}},
                     m_predictedOdometry{m_kinematics, units::radian_t(0_rad), frc::Pose2d{0_m, 0_m, 0_rad}},
                     pose{0_m, 0_m, 0_rad}
{
  
  fl.SetInverted(true);
  bl.SetInverted(true);
  // wpi::outs() << "sfidsjsdoi";
  // do i invert the encoders? not sure
  // set distanceperpulse
  
}

void Mecanum::Periodic()
{
  // frc::MecanumDriveWheelSpeeds wheelSpeeds{units::meters_per_second_t(flEncoder.GetRate()),
  //                                          units::meters_per_second_t(frEncoder.GetRate()),
  //                                          units::meters_per_second_t(blEncoder.GetRate()),
  //                                          units::meters_per_second_t(brEncoder.GetRate())};

  // pose = m_odometry.Update(frc::Rotation2d{GetAngleDegrees()}, wheelSpeeds);

  
  // frc::Shuffleboard::SelectTab("Telemetry");
  // frc::MecanumDrive drive{fl, bl, fr, bl};
  // frc::Shuffleboard::GetTab("Telemetry").Add("Mecanum Drivebase", drive).WithWidget(frc::BuiltInWidgets::kMecanumDrive);
  frc::SmartDashboard::PutNumber("Yaw: ", gyro.GetYaw());
  frc::SmartDashboard::PutNumber("GetAngleDegrees(): ", GetAngleDegrees().value());
  frc::SmartDashboard::PutNumber("Pitch: ", gyro.GetPitch());
  frc::SmartDashboard::PutNumber("Roll: ", gyro.GetRoll());
  frc::SmartDashboard::PutNumber("Front Left Encoder: ", flEncoder.GetDistance());
  frc::SmartDashboard::PutNumber("Front Right Encoder: ", frEncoder.GetDistance());
  frc::SmartDashboard::PutNumber("Back Left Encoder: ", blEncoder.GetDistance());
  frc::SmartDashboard::PutNumber("Back Right Encoder: ", brEncoder.GetDistance());
// m_predictedOdometry.GetPose().Rotation
}

double angle = 0;

void Mecanum::Drive(units::meters_per_second_t vx, units::meters_per_second_t vy, units::radians_per_second_t omega)
{
  frc::ChassisSpeeds speeds = frc::ChassisSpeeds::FromFieldRelativeSpeeds(vy, vx, omega, frc::Rotation2d(units::degree_t(0.0f)));
  frc::MecanumDriveWheelSpeeds wheelSpeeds = m_kinematics.ToWheelSpeeds(speeds);
  
  wheelSpeeds.Desaturate(MAX_SPEED); // this makes sure nothing is over MAX_SPEED
  angle += (omega.value()/20)*(180/PI);
  frc::SmartDashboard::PutNumber("Predicted Angle Delta: ", (omega.value()/20)*(180/PI));
  frc::SmartDashboard::PutNumber("Predicted Angle:", angle);

  double correction = 0;

  if(GetAngleDegrees().value() < angle) { // too far right
    // correction = abs(GetAngleDegrees().value() - angle)/4;
    correction = 1;
  } else { // too far left
    // correction = -abs(GetAngleDegrees().value() - angle)/4;
    correction = -1;
  }

  // correction = 0;

  correction *= (abs(GetAngle() - angle))/10;

  fl.Set(wheelSpeeds.frontLeft.value() + correction / MAX_SPEED.value()); // dividing by MAX_SPEED normalizes them
  fr.Set(wheelSpeeds.frontRight.value() - correction / MAX_SPEED.value());
  bl.Set(wheelSpeeds.rearLeft.value() + correction / MAX_SPEED.value());
  br.Set(wheelSpeeds.rearRight.value() - correction / MAX_SPEED.value());
  
  s_fl.SetSpeed(-wheelSpeeds.frontLeft / MAX_SPEED);
  s_fr.SetSpeed(wheelSpeeds.frontRight / MAX_SPEED);
  s_bl.SetSpeed(-wheelSpeeds.rearLeft / MAX_SPEED);
  s_br.SetSpeed(wheelSpeeds.rearRight / MAX_SPEED);
}

void Mecanum::DriveVoltages(units::volt_t _fl, units::volt_t _fr, units::volt_t _bl, units::volt_t _br)
{
  fl.SetVoltage(_fl);
  fr.SetVoltage(_fr);
  bl.SetVoltage(_bl);
  br.SetVoltage(_br);
}

void Mecanum::DriveJoystick(float lx, float ly, float rx)
{
  Mecanum::Drive(units::meters_per_second_t{lx * MAX_SPEED}, units::meters_per_second_t{ly * MAX_SPEED}, units::radians_per_second_t{rx * MAX_ROT_SPEED});
  
  // lx /= 4;
  // fl.Set(ly + lx + 2 * rx);
  // fr.Set(ly - lx - 2 * rx);
  // bl.Set(ly - lx + 2 * rx);
  // br.Set(ly + lx - 2 * rx);

  // s_fl.SetSpeed(ly + lx + 2 * rx);
  // s_fr.SetSpeed(ly - lx - 2 * rx);
  // s_bl.SetSpeed(ly - lx + 2 * rx);
  // s_br.SetSpeed(ly + lx - 2 * rx);
}

// // counterclockwise, starting from the right. same as in math.
float Mecanum::GetAngle()
{
  float gyroAngle = gyro.GetYaw();
  // extern float gyroOffset;
  // gyroAngle = std::abs(std::fmod((-gyroAngle + 90) + gyroOffset, 360)); // this converts from clockwise starting at north to counterclockwise starting at east, which is more
  return gyroAngle;
  // return 0;                                                     // mathematical
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
  // return m_odometry.GetPose();
  return frc::Pose2d{0_m, 0_m, 0_rad};
}