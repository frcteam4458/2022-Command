#include "subsystems/HangSubsystem.h"

#include "Constants.h"

HangSubsystem::HangSubsystem() : leftArm{LEFT_ARM}, rightArm{RIGHT_ARM}
{}

void HangSubsystem::Set(double set)
{
    leftArm.Set(set);
    rightArm.Set(set);
}