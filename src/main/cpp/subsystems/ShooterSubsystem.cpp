#include "subsystems/ShooterSubsystem.h"

#include "Constants.h"

ShooterSubsystem::ShooterSubsystem() : motor{SHOOTER}
{
    motor.SetInverted(true);
}

void ShooterSubsystem::Set(double power)
{
    motor.Set(power);
}

void ShooterSubsystem::Zero()
{
    motor.Set(0);
}