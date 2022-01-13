#include "RobotContainer.h"
#include "Constants.h"
#include "frc2/command/CommandScheduler.h"
#include <frc/shuffleboard/Shuffleboard.h>

RobotContainer::RobotContainer() : drive{},
                                   intakeCommand{},
                                   m_teleop{&drive},
                                   autoDrive{&drive},

                                   leftStick{0},
                                   rightStick{1},
                                   secondPlayer{2},
                                   
                                   intakeButton{&leftStick, 0}
{
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings()
{
  // m_drive.SetDefaultCommand(m_teleop);
  // intakeButton.WhileHeld(m_intakeCommand);
}

frc2::Command *RobotContainer::GetAutonomousCommand()
{
  // make this choose from shuffleboard input
  // return &m_autoDrive;
  return nullptr;
}

frc2::Command *RobotContainer::GetTeleopCommand()
{
  // same as above
  // return &m_teleop;
  return nullptr;
}

void RobotContainer::ShuffleBoard()
{
}