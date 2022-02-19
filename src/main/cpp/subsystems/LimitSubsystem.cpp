#include "subsystems/LimitSubsystem.h"
#include "Constants.h"

LimitSubsystem::LimitSubsystem() {}

boolean LimitSubsystem::IsFirstPressed() {
    return first.Get();
}

boolean LimitSubsystem::IsSecondPressed() {
    return second.Get();
}

bolean LimitSubsystem::IsBothPressed() {
    return first.Get() && second.Get();
}