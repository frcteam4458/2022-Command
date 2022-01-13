#include "RobotContainer.h"
#include "Constants.h"
#include "frc2/command/CommandScheduler.h"

RobotContainer::RobotContainer() : m_autoDrive(),
                                   m_teleop(&m_drive),
                                   m_intakeCommand{&m_drive},

                                   leftStick{0},
                                   rightStick{1},
                                   secondPlayer{2},
                                   
                                   intakeButton{&leftStick, 0}
{
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings()
{
  m_drive.SetDefaultCommand(m_teleop);
  intakeButton.WhileHeld(m_intakeCommand);
}

frc2::Command *RobotContainer::GetAutonomousCommand()
{
  // make this choose from shuffleboard input
  return &m_autoDrive;
}

frc2::Command *RobotContainer::GetTeleopCommand()
{
  // same as above
  return &m_teleop;
}