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
                                   shooterFastCommand{&shooterSubsystem, 5400.0},
                                  //  shooterSlowCommand{&shooterSubsystem, 3600.0},
                                   shooterStopCommand{&shooterSubsystem, 0.0},
                                   feedCommand{&feedSubsystem, fireRotations},
                                   feedTwiceCommand{&feedSubsystem, fireTwiceRotations},
                                   limitCommand{&limitSubsystem},
                                   limitWaitCommand{&limitSubsystem},
                                   flywheelWaitCommand{&shooterSubsystem},
                                   fireCommand{&limitSubsystem, intakeCommand, shooterFastCommand, feedCommand, limitWaitCommand, flywheelWaitCommand}
{
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings()
{
  // driveSubsystem.SetDefaultCommand(std::move(teleop));
  flywheelFastButton.WhenPressed(std::move(shooterFastCommand));
  // flywheelSlowButton.WhenPressed(std::move(shooterSlowCommand));
  flywheelStopButton.WhenPressed(std::move(shooterStopCommand));
  intakeButton.WhenHeld(std::move(intakeCommand));
  outtakeButton.WhenHeld(std::move(outtakeCommand));
  fireButton.WhenHeld(std::move(feedCommand));
  // fireButton.WhenHeld(std::move(feedCommand));
  // limitCommand.Schedule();
  // fireButton.WhenPressed(std::move(fireCommand));
  // fireButton.WhenPressed(frc2::ParallelRaceGroup{std::move(intakeCommand), frc2::SequentialCommandGroup{std::move(shooterFastCommand), std::move(flywheelWaitCommand), std::move(limitWaitCommand), std::move(feedCommand), std::move(limitWaitCommand), std::move(feedCommand)}});
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