#include "RobotContainer.h"
#include "Constants.h"
#include "Controls.h"
#include "frc2/command/CommandScheduler.h"
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/PneumaticsModuleType.h>

#include <frc2/command/WaitCommand.h>

RobotContainer::RobotContainer() : driveSubsystem{},
                                   shooterSubsystem{},
                                   intakeSubsystem{},
                                   feedSubsystem{},
                                   limitSubsystem{},
                                   hangSubsystem{},
                                   lightSubsystem{},

                                   teleop{&driveSubsystem},
                                   autoDrive{&driveSubsystem},
                                   intakeCommand{&intakeSubsystem},
                                   outtakeCommand{&intakeSubsystem, &feedSubsystem},
                                   shooterFastCommand{&shooterSubsystem, 1.0f},
                                   shooterSlowCommand{&shooterSubsystem, 3000.0},
                                   shooterStopCommand{&shooterSubsystem, 0.0f},
                                   feedCommand{&feedSubsystem, fireRotations},
                                   feedTwiceCommand{&feedSubsystem, fireTwiceRotations},
                                   limitCommand{&limitSubsystem},
                                   limitWaitCommand{&limitSubsystem},
                                   flywheelWaitCommand{&shooterSubsystem},
                                   fireCommand{&limitSubsystem, intakeCommand, shooterFastCommand, feedCommand, limitWaitCommand, flywheelWaitCommand},
                                   climbUpCommand{&hangSubsystem},
                                   climbDownCommand{&hangSubsystem},
                                   climbCommand{&hangSubsystem},
                                   lightCommand{&lightSubsystem}
{
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings()
{
  flywheelFastButton.WhenPressed(std::move(shooterFastCommand));
  flywheelSlowButton.WhenPressed(std::move(shooterSlowCommand));
  flywheelStopButton.WhenPressed(std::move(shooterStopCommand));
  intakeButton.ToggleWhenPressed(std::move(intakeCommand));
  outtakeButton.WhenHeld(std::move(outtakeCommand));
  feedButton.WhenHeld(std::move(feedCommand));
  fireButton.WhenPressed(frc2::ParallelRaceGroup{std::move(intakeCommand), frc2::SequentialCommandGroup{frc2::WaitCommand{units::second_t{0.25}}, frc2::ParallelRaceGroup{std::move(feedCommand), frc2::WaitCommand{units::second_t{1}}}, frc2::WaitCommand{units::second_t{0.5}}, frc2::ParallelRaceGroup{std::move(feedCommand), frc2::WaitCommand{units::second_t{0.5}}}}});
  climbUpButton.WhenHeld(std::move(climbUpCommand));
  climbDownButton.WhenHeld(std::move(climbDownCommand));
  lightButton.ToggleWhenPressed(std::move(lightCommand));
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