#include "subsystems/ShooterSubsystem.h"

#include "Constants.h"

#include <frc/smartdashboard/SmartDashboard.h>

ShooterSubsystem::ShooterSubsystem() : motor{SHOOTER}, encoder{SHOOTER_ENCDOER}, s_motor{SHOOTER}, s_encoder{encoder}
{
    encoder.SetDistancePerRotation(1);
}

void ShooterSubsystem::Periodic() {
    motor.Set(1);
    frc::SmartDashboard::PutNumber("Flywheel Power", motor.Get());
    encoderRpm = (encoder.GetDistance() - encoderPrev)/0.02*60;

    encoderPrev = encoder.GetDistance();

    if(GetRPM() != GetTargetRPM()) {
        motor.Set(motor.Get() + (GetTargetRPM() - GetRPM()) * 0.00005);
        s_motor.SetSpeed(motor.Get());
    }

    frc::SmartDashboard::PutNumber("Shooter Encoder", encoder.GetDistance());
    frc::SmartDashboard::PutNumber("RPM", encoderRpm);
    frc::SmartDashboard::PutNumber("Target RPM", rpm);
}

void ShooterSubsystem::SimulationPeriodic() {
    distance += motor.Get()*1.8; // so motor=1 makes 5000rpm
    s_encoder.SetDistance(distance);
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
    return encoderRpm;
}

double ShooterSubsystem::GetTargetRPM() {
    return rpm;
}