#include "subsystems/FeedSubsystem.h"

#include "Constants.h"

FeedSubsystem::FeedSubsystem() : feedMotor{FEED_MOTOR}
{}

void FeedSubsystem::Set(double power)
{
    feedMotor.Set(power);
}