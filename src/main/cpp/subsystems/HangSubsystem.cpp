#include "subsystems/HangSubsystem.h"

#include "Constants.h"

HangSubsystem::HangSubsystem() : climber{CLIMBER}
{}

void HangSubsystem::Set(double set)
{
    climber.Set(set);
}