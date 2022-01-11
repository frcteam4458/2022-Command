#pragma once

#ifndef AUTO_DRIVE_H
#define AUTO_DRIVE_H

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Mecanum.h"

class AutoDrive : public frc2::CommandHelper<frc2::CommandBase, AutoDrive>
{
public:
    explicit AutoDrive(Mecanum *drive);

    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;

private:
    Mecanum *m_drive;
};
#endif