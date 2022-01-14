#include "RobotContainer.h"
#include "Constants.h"
#include "frc2/command/CommandScheduler.h"
#include <frc/shuffleboard/Shuffleboard.h>

RobotContainer::RobotContainer() : //drive{},
                                   //intakeCommand{},
                                   //teleop{&drive},
                                   //autoDrive{&drive},

                                   leftStick{0},
                                   rightStick{1},
                                   secondPlayer{2},
                                   
                                   intakeButton{&leftStick, 0}
{
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings()
{
  // drive.SetDefaultCommand(teleop);
  // intakeButton.WhileHeld(intakeCommand);
}

frc2::Command *RobotContainer::GetAutonomousCommand()
{
  // make this choose from shuffleboard input
  return nullptr;
}

frc2::Command *RobotContainer::GetTeleopCommand()
{
  // same as above
  return nullptr;
}

void RobotContainer::ShuffleBoard()
{
}