#include "subsystems/HangSubsystem.h"

#include "Constants.h"

HangSubsystem::HangSubsystem() : climber{CLIMBER}, encoder{ARM_ENCODER}
{
}

void HangSubsystem::Set(double set)
{
    power = set;
}

void HangSubsystem::Periodic() {
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