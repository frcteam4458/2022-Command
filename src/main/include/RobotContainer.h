#pragma once
#ifndef ROBOT_CONTAINER_H
#define ROBOT_CONTAINER_H

#include <frc2/command/Command.h>

#include "commands/Drive.h"
#include "commands/AutoDrive.h"
#include "subsystems/Mecanum.h"

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

  void ConfigureButtonBindings();
};
#endif