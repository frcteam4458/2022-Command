
#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

#include "Global.h"

#include <frc/DutyCycleEncoder.h>
#include <wpi/PortForwarder.h>

#include <frc/shuffleboard/Shuffleboard.h>

void Robot::RobotInit()
{
  m_container.ShuffleBoard();
  wpi::PortForwarder::GetInstance().Add(5800, "photonvision.local", 5800);

  
}

void Robot::RobotPeriodic()
{
  frc2::CommandScheduler::GetInstance().Run();
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::AutonomousInit()
{
  // m_autonomousCommand = m_container.GetAutonomousCommand();

  // if (m_autonomousCommand != nullptr) // just makes sure the autonomous exists
  // {
  //   m_autonomousCommand->Schedule();
  // }

  m_container.GetAutonomousCommand()->Schedule();
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit()
{
  if (m_autonomousCommand != nullptr)
  {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }
  m_container.GetTeleopCommand()->Schedule();
  m_container.GetShooterIdleCommand()->Schedule();
  m_container.GetLightCommand()->Schedule();

  
}

void Robot::TeleopPeriodic()
{
}



void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main()
{
  return frc::StartRobot<Robot>();
}
#endif
