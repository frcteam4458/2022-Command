#include "RobotContainer.h"
#include "Constants.h"
#include "Controls.h"
#include "frc2/command/CommandScheduler.h"
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/PneumaticsModuleType.h>

#include <frc2/command/WaitCommand.h>

#include <functional>

RobotContainer::RobotContainer() : driveSubsystem{},
                                   shooterSubsystem{},
                                   intakeSubsystem{},
                                   feedSubsystem{},
                                   limitSubsystem{},
                                   hangSubsystem{},
                                   lightSubsystem{},
                                   servoSubsystem{},

                                   teleop{&driveSubsystem},
                                   autoDrive{&driveSubsystem},
                                   intakeCommand{&intakeSubsystem},
                                   outtakeCommand{&intakeSubsystem, &feedSubsystem},
                                   shooterFastCommand{&shooterSubsystem, 1.0f},
                                   shooterSlowCommand{&shooterSubsystem, 0.75f},
                                   shooterStopCommand{&shooterSubsystem, 0.0f},
                                   feedCommand{&feedSubsystem, fireRotations},
                                   feedTwiceCommand{&feedSubsystem, fireTwiceRotations},
                                   limitCommand{&limitSubsystem},
                                   limitWaitCommand{&limitSubsystem},
                                   flywheelWaitCommand{&shooterSubsystem},
                                  //  fireCommand{&limitSubsystem, intakeCommand, shooterFastCommand, feedCommand, limitWaitCommand, flywheelWaitCommand},
                                   climbUpCommand{&hangSubsystem},
                                   climbDownCommand{&hangSubsystem}, // lock it from going down at 1.0x
                                   climbCommand{&hangSubsystem},
                                   lightCommand{&lightSubsystem},
                                   fireCommand{std::move(intakeCommand), frc2::ConditionalCommand{frc2::SequentialCommandGroup{frc2::WaitCommand{0.5_s}, frc2::ParallelRaceGroup{std::move(feedCommand), frc2::WaitCommand{0.5_s}}, frc2::WaitCommand{1_s}, frc2::ParallelRaceGroup{std::move(feedCommand), frc2::WaitCommand{0.5_s}}}, frc2::SequentialCommandGroup{frc2::WaitCommand{0.25_s}, frc2::ParallelRaceGroup{std::move(feedCommand), frc2::WaitCommand{0.5_s}}}, [this]() { return limitSubsystem.IsBothPressed(); } }},
                                   autoCommand{std::move(shooterFastCommand), frc2::WaitCommand{3_s}, std::move(fireCommand), frc2::WaitCommand{1_s}, std::move(shooterStopCommand), std::move(autoDrive).WithTimeout(3_s)},
                                   servoOpenCommand{&servoSubsystem, 0.0},
                                   servoCloseCommand{&servoSubsystem, 1.0}
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
  // fireButton.WhenPressed(std::move(fireCommand));
  fireButton.WhenPressed(frc2::ParallelRaceGroup{std::move(intakeCommand), frc2::SequentialCommandGroup{frc2::WaitCommand{units::second_t{0.1}}, frc2::ParallelRaceGroup{std::move(feedCommand), frc2::WaitCommand{units::second_t{1}}}, frc2::WaitCommand{units::second_t{1}}, frc2::ParallelRaceGroup{std::move(feedCommand), frc2::WaitCommand{units::second_t{0.5}}}}});
  climbUpButton.WhenHeld(frc2::SequentialCommandGroup{std::move(servoOpenCommand), frc2::WaitCommand{0.1_s}, std::move(climbUpCommand)});
  // climbDownButton.WhenHeld(frc2::ConditionalCommand{std::move(climbDownCommand), frc2::WaitCommand{0_s}, [this]() {return servoSubsystem.Get() == 0.5;}}); // disable down when servo is at 1.0
  climbDownButton.WhenHeld(frc2::SequentialCommandGroup{std::move(servoCloseCommand), frc2::WaitCommand{0.1_s}, std::move(climbDownCommand)});
  lightButton.ToggleWhenPressed(std::move(lightCommand));
  
  servoCloseButton.WhenPressed(std::move(servoCloseCommand));
  servoOpenButton.WhenPressed(std::move(servoOpenCommand));
}

frc2::Command *RobotContainer::GetAutonomousCommand()
{
  // make this choose from shuffleboard input

  return &autoCommand;
}

frc2::Command *RobotContainer::GetTeleopCommand()
{
  // same as above
  return &teleop;
}

void RobotContainer::ShuffleBoard()
{
}