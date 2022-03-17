#include "subsystems/HangSubsystem.h"

#include "Constants.h"

#include <frc/smartdashboard/SmartDashboard.h>

HangSubsystem::HangSubsystem() : climber{CLIMBER}, encoder{ARM_ENCODER}
{
}

void HangSubsystem::Set(double set)
{
    power = set;
    climber.Set(power);
}

void HangSubsystem::Periodic() {
    if(!reset) 
    encoder.Reset();
    reset = true;
    // frc::SmartDashboard::PutNumber("Arm Encoder", encoder.GetDistance());
    double power = HangSubsystem::power;

    if(climber.Get() < 0 && encoder.GetDistance() < CLIMBER_BOTTOM) {
        climber.Set(0);
    }
}

void HangSubsystem::ResetEncoder() { 
    encoder.Reset();
}