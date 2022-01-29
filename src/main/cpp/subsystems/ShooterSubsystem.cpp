#include "subsystems/ShooterSubsystem.h"

#include "Constants.h"

ShooterSubsystem::ShooterSubsystem() : motor{SHOOTER} //left{LEFT_SHOOTER}, right{RIGHT_SHOOTER}
{
    motor.SetInverted(true);
}

void ShooterSubsystem::Set(double power)
{
    motor.Set(power);
}

// void ShooterSubsystem::SetLeft(double power)
// {
//     left.Set(power);
// }

// void ShooterSubsystem::SetRight(double power)
// {
//     right.Set(power);
// }

void ShooterSubsystem::Zero()
{
    // left.Set(0);
    // right.Set(0);
    motor.Set(0);
}