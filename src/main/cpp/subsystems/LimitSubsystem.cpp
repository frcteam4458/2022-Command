#include "subsystems/LimitSubsystem.h"
#include "Constants.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>

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
    bool first = IsFirstPressed();
    bool second = IsFirstPressed();
    // frc::Shuffleboard::GetTab("Telemetry").Add("First Switch", first).WithWidget(frc::BuiltInWidgets::kBooleanBox);
    // frc::Shuffleboard::GetTab("Telemetry").Add("Second Switch", second).WithWidget(frc::BuiltInWidgets::kBooleanBox);
}