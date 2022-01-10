#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Mecanum.h"

class AutoDrive : public frc2::CommandHelper<frc2::CommandBase, Mecanum>
{
public:
    explicit AutoDrive(Mecanum *drive);

    void Initialize() override;
    bool IsFinished() override;

private:
    Mecanum *m_drive;
};