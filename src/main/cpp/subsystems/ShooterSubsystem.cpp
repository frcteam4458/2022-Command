#include "subsystems/ShooterSubsystem.h"

#include "Constants.h"

ShooterSubsystem::ShooterSubsystem() : motor{SHOOTER}, encoder{SHOOTER_ENCDOER[0], SHOOTER_ENCDOER[1]}
{
    encoder.SetDistancePerPulse(1);
}

void ShooterSubsystem::Set(double power)
{
    motor.Set(power);
}

double ShooterSubsystem::GetRPM() {
    return encoder.GetRate();
}