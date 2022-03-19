#include "subsystems/LimitSubsystem.h"
#include "Constants.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>

#include <networktables/NetworkTableEntry.h>

nt::NetworkTableEntry firstSwitch;
nt::NetworkTableEntry secondSwitch;

LimitSubsystem::LimitSubsystem() {
    
    firstSwitch = frc::Shuffleboard::GetTab("Telemetry").Add("First Switch", false).WithWidget(frc::BuiltInWidgets::kBooleanBox).GetEntry();
    secondSwitch = frc::Shuffleboard::GetTab("Telemetry").Add("Second Switch", false).WithWidget(frc::BuiltInWidgets::kBooleanBox).GetEntry();
}

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
    bool second = IsSecondPressed();
    
    firstSwitch.SetBoolean(first);
    secondSwitch.SetBoolean(second);
}