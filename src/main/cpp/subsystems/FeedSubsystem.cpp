#include "subsystems/FeedSubsystem.h"

#include "Constants.h"

FeedSubsystem::FeedSubsystem() : feedMotor{FEED_MOTOR}, encoder{FEED_ENCODER[0], FEED_ENCODER[1]}, s_feedMotor{FEED_MOTOR}, s_encoder{encoder}
{
    // DISTANCE PER PULSE
}

void FeedSubsystem::Set(double power)
{
    feedMotor.Set(power);
    s_feedMotor.SetSpeed(power);
}

double FeedSubsystem::GetPosition() {
    return encoder.GetDistance();
}