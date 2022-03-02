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

#include "commands/AutoDrive.h"
#include "commands/IntakeCommand.h"
#include "commands/ShooterCommand.h"
#include "commands/OuttakeCommand.h"
#include "commands/FeedCommand.h"
#include "commands/LimitCommand.h"
#include "commands/LimitWaitCommand.h"
#include "commands/FlywheelWaitCommand.h"
#include "commands/FireCommand.h"
#include "commands/ClimbUpCommand.h"
#include "commands/ClimbDownCommand.h"
#include "commands/ClimbCommand.h"
#include "commands/LightCommand.h"

class RobotContainer
{
public:
  RobotContainer();

  frc2::Command *GetAutonomousCommand();
  frc2::Command *GetTeleopCommand();
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

  // commands
  Drive teleop;
  AutoDrive autoDrive;
  IntakeCommand intakeCommand;
  OuttakeCommand outtakeCommand;
  ShooterCommand shooterFastCommand;
  ShooterCommand shooterSlowCommand;
  ShooterCommand shooterStopCommand;
  FeedCommand feedCommand;
  FeedCommand feedTwiceCommand;
  LimitCommand limitCommand;
  LimitWaitCommand limitWaitCommand;
  FlywheelWaitCommand flywheelWaitCommand;
  FireCommand fireCommand;
  ClimbUpCommand climbUpCommand;
  ClimbDownCommand climbDownCommand;
  ClimbCommand climbCommand;
  LightCommand lightCommand;

  void ConfigureButtonBindings();
};
#endif