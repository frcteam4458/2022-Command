#include "subsystems/ShooterSubsystem.h"

#include "Constants.h"

ShooterSubsystem::ShooterSubsystem() : motor{SHOOTER}, encoder{SHOOTER_ENCDOER[0], SHOOTER_ENCDOER[1]}, s_motor{SHOOTER}
{
    encoder.SetDistancePerPulse(1);
}

void ShooterSubsystem::Set(double power)
{
    motor.Set(power);
    s_motor.SetSpeed(power);
}

double ShooterSubsystem::Get()
{
    return motor.Get();
}

double ShooterSubsystem::GetRPM() {
    return encoder.GetRate();
}