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
                                   limitSubsystem{},


                                   teleop{&driveSubsystem},
                                   autoDrive{&driveSubsystem},
                                   intakeCommand{&intakeSubsystem},
                                   outtakeCommand{&intakeSubsystem},
                                   shooterFastCommand{&shooterSubsystem, 4800.0},
                                   shooterSlowCommand{&shooterSubsystem, 3600.0},
                                   shooterStopCommand{&shooterSubsystem, 0.0f},
                                   feedCommand{&feedSubsystem, fireRotations},
                                   feedTwiceCommand{&feedSubsystem, fireTwiceRotations},
                                   limitCommand{&limitSubsystem}
{
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings()
{
  driveSubsystem.SetDefaultCommand(std::move(teleop));
  flywheelFastButton.ToggleWhenPressed(std::move(shooterFastCommand));
  flywheelSlowButton.ToggleWhenPressed(std::move(shooterSlowCommand));
  flywheelStopButton.WhenPressed(std::move(shooterStopCommand));
  intakeButton.WhenHeld(std::move(intakeCommand));
  outtakeButton.WhenHeld(std::move(outtakeCommand));
  fireButton.WhenHeld(std::move(feedCommand));
  // limitCommand.Schedule();
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