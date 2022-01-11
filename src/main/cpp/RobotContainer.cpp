#include "RobotContainer.h"

RobotContainer::RobotContainer() : m_autoDrive(&m_drive),
                                   m_teleop(&m_drive)
{
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings()
{
}

frc2::Command *RobotContainer::GetAutonomousCommand()
{
  return &m_autoDrive;
}

frc2::Command *RobotContainer::GetTeleopCommand()
{
  return &m_teleop;
}