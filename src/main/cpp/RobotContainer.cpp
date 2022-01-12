#include "RobotContainer.h"

RobotContainer::RobotContainer() : m_autoDrive(&m_drive),
                                   m_teleop(&m_drive),

                                   leftStick{0},
                                   rightStick{1},
                                   secondPlayer{2},
                                   
                                   intakeButton{&leftStick, 0}
{
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings()
{
  intakeButton.WhileHeld(m_intakeCommand);
}

frc2::Command *RobotContainer::GetAutonomousCommand()
{
  return &m_autoDrive;
}

frc2::Command *RobotContainer::GetTeleopCommand()
{
  return &m_teleop;
}