#include "subsystems/LimitSubsystem.h"
#include "Constants.h"

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