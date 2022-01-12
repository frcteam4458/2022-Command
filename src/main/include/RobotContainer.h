#pragma once
#ifndef ROBOT_CONTAINER_H
#define ROBOT_CONTAINER_H

#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/Command.h>

#include "commands/Drive.h"
#include "commands/AutoDrive.h"
#include "subsystems/Mecanum.h"

#include "commands/Intake.h"

class RobotContainer
{
public:
  RobotContainer();

  frc2::Command *GetAutonomousCommand();
  frc2::Command *GetTeleopCommand();

private:
  Mecanum m_drive;
  AutoDrive m_autoDrive;
  Drive m_teleop;

  Intake m_intakeCommand;

  frc::Joystick leftStick;
  frc::Joystick rightStick;
  frc::Joystick secondPlayer;

  frc2::JoystickButton intakeButton;

  void ConfigureButtonBindings();
};
#endif