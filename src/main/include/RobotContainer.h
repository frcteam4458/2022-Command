#pragma once
#ifndef ROBOT_CONTAINER_H
#define ROBOT_CONTAINER_H

#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/Command.h>

#include "commands/Drive.h"
#include "commands/Intake.h"
#include "subsystems/Mecanum.h"

#include "commands/AutoDrive.h"

class RobotContainer
{
public:
  RobotContainer();

  frc2::Command *GetAutonomousCommand();
  frc2::Command *GetTeleopCommand();

private:
  Mecanum drive;

  Intake intakeCommand;
  Drive m_teleop;

  AutoDrive autoDrive;

  frc::Joystick leftStick;
  frc::Joystick rightStick;
  frc::Joystick secondPlayer;

  frc2::JoystickButton intakeButton;

  void ConfigureButtonBindings();
};
#endif