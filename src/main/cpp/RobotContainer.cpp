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


                                   teleop{&driveSubsystem},
                                   autoDrive{&driveSubsystem},
                                   intakeCommand{&intakeSubsystem},
                                   outtakeCommand{&intakeSubsystem, &feedSubsystem},
                                   shooterFastCommand{&shooterSubsystem, 1.0f},
                                   shooterSlowCommand{&shooterSubsystem, 0.7f},
                                   shooterStopCommand{&shooterSubsystem, 0.0f},
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
  flywheelSlowButton.WhenPressed(std::move(shooterSlowCommand));
  flywheelStopButton.WhenPressed(std::move(shooterStopCommand));
  intakeButton.WhenHeld(std::move(intakeCommand));
  outtakeButton.WhenHeld(std::move(outtakeCommand));
  fireButton.WhenHeld(std::move(feedCommand));
  fireButton.WhenHeld(std::move(intakeCommand));
  // fireButton.WhenHeld(std::move(feedCommand));
  // limitCommand.Schedule();
  // fireButton.WhenPressed(std::move(fireCommand));
  // fireButton.WhenPressed(frc2::ParallelRaceGroup{std::move(intakeCommand), frc2::SequentialCommandGroup{std::move(shooterFastCommand), std::move(flywheelWaitCommand), std::move(limitWaitCommand), std::move(feedCommand), std::move(limitWaitCommand), std::move(feedCommand)}});
  frc2::JoystickButton{&thirdStick, 7}.WhenPressed(frc2::ParallelRaceGroup{std::move(intakeCommand), frc2::SequentialCommandGroup{frc2::WaitCommand{units::second_t{2}}, frc2::ParallelRaceGroup{std::move(feedCommand), frc2::WaitCommand{units::second_t{0.5}}}, frc2::WaitCommand{units::second_t{1}}, frc2::ParallelRaceGroup{std::move(feedCommand), frc2::WaitCommand{units::second_t{0.5}}}}});
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