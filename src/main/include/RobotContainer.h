#pragma once
#ifndef ROBOT_CONTAINER_H
#define ROBOT_CONTAINER_H

#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/Command.h>

#include "commands/Drive.h"
#include "commands/SolenoidToggle.h"
#include "subsystems/Mecanum.h"
#include "subsystems/ShooterSubsystem.h"
#include "subsystems/HangSubsystem.h"
#include "subsystems/SolenoidSubsystem.h"
#include "subsystems/IntakeSubsystem.h"
#include "subsystems/FeedSubsystem.h"

#include "commands/AutoDrive.h"
#include "commands/IntakeCommand.h"
#include "commands/ShooterCommand.h"
#include "commands/OuttakeCommand.h"
#include "commands/FeedCommand.h"

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


  // commands
  Drive teleop;
  AutoDrive autoDrive;
  IntakeCommand intakeCommand;
  OuttakeCommand outtakeCommand;
  ShooterCommand shooterCommand;
  FeedCommand feedCommand;

  void ConfigureButtonBindings();
};
#endif