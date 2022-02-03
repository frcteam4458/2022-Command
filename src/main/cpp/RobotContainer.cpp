#include "RobotContainer.h"
#include "Constants.h"
#include "frc2/command/CommandScheduler.h"
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/PneumaticsModuleType.h>

RobotContainer::RobotContainer() : drive{},
                                   shooter{},
                                   solenoidSubsystem{frc::PneumaticsModuleType::CTREPCM},

                                   teleop{&drive},
                                   autoDrive{&drive},
                                   shooterCommand{&shooter},
                                   solenoidToggle{&solenoidSubsystem},
                                   
                                   leftStick{0},
                                   rightStick{1},
                                   secondPlayer{2},
                                   
                                   intakeButton{&leftStick, 0},
                                   solenoidToggleButton{&leftStick, 1}
{
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings()
{
  // drive.SetDefaultCommand(teleop);
  // intakeButton.WhileHeld(intakeCommand);
  
  solenoidToggleButton.WhenPressed(solenoidToggle);
}


frc2::Command *RobotContainer::GetAutonomousCommand()
{
  // make this choose from shuffleboard input
  return &autoDrive;
}

frc2::Command *RobotContainer::GetTeleopCommand()
{
  // same as above
  return &teleop;
  // return &shooterCommand;
}

void RobotContainer::ShuffleBoard()
{
}