#include "subsystems/ShooterSubsystem.h"

#include "Constants.h"

ShooterSubsystem::ShooterSubsystem() : motor{SHOOTER}, encoder{SHOOTER_ENCDOER[0], SHOOTER_ENCDOER[1]}, s_motor{SHOOTER}
{
    encoder.SetDistancePerPulse(1);
}

void ShooterSubsystem::Periodic() {
    if(GetRPM() < GetTargetRPM()) {
        motor.Set(motor.Get() + (GetTargetRPM() - GetRPM()) * 0.05);
    }
}

void ShooterSubsystem::Set(double power)
{
    motor.Set(power);
    s_motor.SetSpeed(power);
}

void ShooterSubsystem::SetRPM(double _rpm) {
    rpm = _rpm;
}

double ShooterSubsystem::Get()
{
    return motor.Get();
}

double ShooterSubsystem::GetRPM() {
    return encoder.GetRate();
}

double ShooterSubsystem::GetTargetRPM() {
    return rpm;
}