#include "RobotContainer.h"
#include "Constants.h"
#include "Controls.h"
#include "frc2/command/CommandScheduler.h"
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/PneumaticsModuleType.h>

RobotContainer::RobotContainer() : driveSubsystem{},
                                   shooterSubsystem{},
                                   intakeSubsystem{},
                                   feedSubsystem{},


                                   teleop{&driveSubsystem},
                                   autoDrive{&driveSubsystem},
                                   intakeCommand{&intakeSubsystem},
                                   outtakeCommand{&intakeSubsystem},
                                   shooterCommand{&shooterSubsystem},
                                   feedCommand{&feedSubsystem}
{
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings()
{
  driveSubsystem.SetDefaultCommand(std::move(teleop));
  shooterSubsystem.SetDefaultCommand(std::move(shooterCommand));
  intakeButton.WhenHeld(std::move(intakeCommand));
  outtakeButton.WhenHeld(std::move(outtakeCommand));
  fireButton.WhenHeld(std::move(feedCommand));
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
}

void RobotContainer::ShuffleBoard()
{
}