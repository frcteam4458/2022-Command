#pragma once
#ifndef ROBOT_CONTAINER_H
#define ROBOT_CONTAINER_H

#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/Command.h>

#include "commands/Drive.h"
#include "subsystems/Mecanum.h"
#include "subsystems/HangSubsystem.h"
#include "subsystems/IntakeSubsystem.h"
#include "subsystems/FeedSubsystem.h"
#include "subsystems/LimitSubsystem.h"
#include "subsystems/LightSubsystem.h"
#include "subsystems/ServoSubsystem.h"

#include "commands/AutoDrive.h"
#include "commands/IntakeCommand.h"
#include "commands/ShooterCommand.h"
#include "commands/OuttakeCommand.h"
#include "commands/FeedCommand.h"
#include "commands/LimitCommand.h"
#include "commands/LimitWaitCommand.h"
#include "commands/FlywheelWaitCommand.h"
#include "commands/ClimbUpCommand.h"
#include "commands/ClimbDownCommand.h"
#include "commands/ClimbCommand.h"
#include "commands/LightCommand.h"
#include "commands/ServoCommand.h"

#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/ConditionalCommand.h>
#include <frc2/command/InstantCommand.h>

class RobotContainer
{
public:
  RobotContainer();

  frc2::Command *GetAutonomousCommand();
  frc2::Command *GetTeleopCommand();
  frc2::Command *GetLightCommand();
  frc2::Command *GetShooterIdleCommand();
  void ShuffleBoard();

private:

  // subsystems
  Mecanum driveSubsystem;
  ShooterSubsystem shooterSubsystem;
  IntakeSubsystem intakeSubsystem;
  FeedSubsystem feedSubsystem;
  LimitSubsystem limitSubsystem;
  HangSubsystem hangSubsystem;
  LightSubsystem lightSubsystem;
  ServoSubsystem servoSubsystem;

  // commands
  Drive teleop;
  AutoDrive autoDrive;
  IntakeCommand intakeCommand;
  OuttakeCommand outtakeCommand;
  ShooterCommand shooterFastCommand;
  ShooterCommand shooterSlowCommand;
  ShooterCommand shooterStopCommand;
  ShooterCommand shooterReverseCommand;
  ShooterCommand autoShootCommand;
  FeedCommand feedCommand;
  FeedCommand feedTwiceCommand;
  LimitCommand limitCommand;
  LimitWaitCommand limitWaitCommand;
  FlywheelWaitCommand flywheelWaitCommand;
  ClimbUpCommand climbUpCommand;
  ClimbDownCommand climbDownCommand;
  ClimbCommand climbCommand;
  LightCommand lightCommand;
  frc2::ParallelRaceGroup fireCommand;
  frc2::SequentialCommandGroup autoCommand;
  ServoCommand servoOpenCommand;
  ServoCommand servoCloseCommand;

  // frc2::ParallelRaceGroup fireCommand;

  void ConfigureButtonBindings();

  int x =0;
};
#endif