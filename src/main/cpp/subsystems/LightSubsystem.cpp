#include "subsystems/LightSubsystem.h"

#include "Constants.h"

LightSubsystem::LightSubsystem() : light{LIGHT} {}

void LightSubsystem::Set(double set)
{
    light.Set(set);
}

void LightSubsystem::Periodic() {
    // light.Set(0.005);
}