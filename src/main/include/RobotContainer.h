#pragma once
#ifndef ROBOT_CONTAINER_H
#define ROBOT_CONTAINER_H

#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/Command.h>

#include "commands/Drive.h"
#include "commands/Intake.h"
#include "commands/SolenoidToggle.h"
#include "subsystems/Mecanum.h"
#include "subsystems/ShooterSubsystem.h"
#include "subsystems/SolenoidSubsystem.h"

#include "commands/AutoDrive.h"
#include "commands/ShooterCommand.h"

class RobotContainer
{
public:
  RobotContainer();

  frc2::Command *GetAutonomousCommand();
  frc2::Command *GetTeleopCommand();
  void ShuffleBoard();

private:
  Mecanum drive;
  ShooterSubsystem shooter;
  SolenoidSubsystem solenoidSubsystem;

  Drive teleop;
  AutoDrive autoDrive;
  ShooterCommand shooterCommand;
  SolenoidToggle solenoidToggle;


  frc::Joystick leftStick;
  frc::Joystick rightStick;
  frc::Joystick secondPlayer;

  frc2::JoystickButton intakeButton;
  frc2::JoystickButton solenoidToggleButton;

  void ConfigureButtonBindings();
};
#endif