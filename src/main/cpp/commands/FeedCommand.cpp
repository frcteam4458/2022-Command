#include "commands/FeedCommand.h"
#include <frc/Joystick.h>
#include <frc/smartdashboard/SmartDashboard.h>

FeedCommand::FeedCommand(FeedSubsystem *_subsystem) : subsystem(_subsystem)
{
    AddRequirements(subsystem);
}

FeedCommand::FeedCommand(FeedSubsystem *_subsystem, double _rotations) : subsystem(_subsystem)
{
    AddRequirements(subsystem);
    rotations = _rotations;
    finalPosition = subsystem->GetPosition() + rotations;
}

void FeedCommand::Initialize() {
}

void FeedCommand::Execute() {
    subsystem->Set(1);
    // frc::SmartDashboard::PutNumber("feeder", 1);
}


void FeedCommand::End(bool interrupted) {
    subsystem->Set(0);
    // frc::SmartDashboard::PutNumber("feeder", 0);
}

bool FeedCommand::IsFinished() {
    // if(std::isnan(rotations)) {
    //     return true;
    // }

    // if(subsystem->GetPosition() < finalPosition) {
        return false;
    // }

    // return true;
}