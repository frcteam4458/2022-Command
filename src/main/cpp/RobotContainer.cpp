#include "RobotContainer.h"

RobotContainer::RobotContainer() : m_autoDrive(&m_drive)
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
