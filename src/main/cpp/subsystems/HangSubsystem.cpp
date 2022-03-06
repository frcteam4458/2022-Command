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
    frc::SmartDashboard::PutNumber("Arm Encoder", encoder.GetDistance());
    return;
    double power = HangSubsystem::power;

    if(power > 0) {
        if(CLIMBER_TOP < encoder.GetDistance()) {
            climber.Set(0);
        } else {
            climber.Set(power);
        }
    }

    if(power < 0) {
        if(encoder.GetDistance() < CLIMBER_BOTTOM) {
            climber.Set(0);
        } else {
            climber.Set(power);
        }
    }
}

void HangSubsystem::ResetEncoder() { 
    encoder.Reset();
}