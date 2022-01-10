#pragma once

#include <frc2/command/Command.h>

#include "commands/AutoDrive.h"
#include "subsystems/Mecanum.h"

class RobotContainer
{
public:
  RobotContainer();

  frc2::Command *GetAutonomousCommand();

private:
  Mecanum m_drive;
  AutoDrive m_autoDrive;

  void ConfigureButtonBindings();
};
