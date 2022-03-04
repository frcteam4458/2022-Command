#include "subsystems/LimitSubsystem.h"
#include "Constants.h"
#include <frc/smartdashboard/SmartDashboard.h>

LimitSubsystem::LimitSubsystem() {}

bool LimitSubsystem::IsFirstPressed() {
    return !first.Get();
    // return false;
}

bool LimitSubsystem::IsSecondPressed() {
    return !second.Get();
    // return false;
}

bool LimitSubsystem::IsBothPressed() {
    return !first.Get() && !second.Get();
    // return false;
}

void LimitSubsystem::Periodic() {
    frc::SmartDashboard::PutBoolean("First Switch", IsFirstPressed());
    frc::SmartDashboard::PutBoolean("Second Switch", IsSecondPressed());
}