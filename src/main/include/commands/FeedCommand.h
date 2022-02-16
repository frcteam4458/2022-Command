#pragma once
#ifndef FEED_COMMAND_H
#define FEED_COMMAND_H

#include "subsystems/FeedSubsystem.h"

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class FeedCommand : public frc2::CommandHelper<frc2::CommandBase, FeedCommand>
{
public:
    explicit FeedCommand(FeedSubsystem *_subsystem);

    void Execute() override;
    void End(bool interrupted) override;

private:
    FeedSubsystem *subsystem;
};
#endif