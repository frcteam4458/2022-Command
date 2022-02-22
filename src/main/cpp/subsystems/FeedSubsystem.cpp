#include "subsystems/FeedSubsystem.h"

#include "Constants.h"

FeedSubsystem::FeedSubsystem() : feedMotor{FEED_MOTOR}, encoder{FEED_ENCODER[0], FEED_ENCODER[1]}, s_feedMotor{FEED_MOTOR}, s_encoder{encoder}
{
    // DISTANCE PER PULSE
    encoder.SetDistancePerPulse(1);
}

void FeedSubsystem::Set(double power)
{
    feedMotor.Set(power);
    s_feedMotor.SetSpeed(power);
}

double FeedSubsystem::GetPosition() {
    return encoder.GetDistance();
}

void FeedSubsystem::SimulationPeriodic() {
    s_encoder.SetDistance(s_feedMotor.GetSpeed() * 0.05);
}