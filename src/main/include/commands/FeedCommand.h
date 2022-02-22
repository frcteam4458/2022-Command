#pragma once
#ifndef FEED_COMMAND_H
#define FEED_COMMAND_H

#include "subsystems/FeedSubsystem.h"

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "Constants.h"
#include <math.h>
#include <cmath>

class FeedCommand : public frc2::CommandHelper<frc2::CommandBase, FeedCommand>
{
public:
    explicit FeedCommand(FeedSubsystem *_subsystem);
    explicit FeedCommand(FeedSubsystem *_subsystem, double _rotations);

    void Initialize() override;
    void Execute() override;
    void End(bool interrupted) override;
    bool IsFinished() override;

private:
    FeedSubsystem *subsystem;
    double finalPosition = 0;
    double rotations = NAN;
};
#endif