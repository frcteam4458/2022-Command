#include "subsystems/LimitSubsystem.h"
#include "Constants.h"
#include <frc/smartdashboard/SmartDashboard.h>

LimitSubsystem::LimitSubsystem() {}

bool LimitSubsystem::IsFirstPressed() {
    return first.Get();
}

bool LimitSubsystem::IsSecondPressed() {
    return second.Get();
}

bool LimitSubsystem::IsBothPressed() {
    return first.Get() && second.Get();
}

void LimitSubsystem::Periodic() {
    frc::SmartDashboard::PutBoolean("First Switch", IsFirstPressed());
    frc::SmartDashboard::PutBoolean("Second Switch", IsSecondPressed());
}