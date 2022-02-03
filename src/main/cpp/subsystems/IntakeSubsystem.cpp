#include "subsystems/IntakeSubsystem.h"

#include "Constants.h"

IntakeSubsystem::IntakeSubsystem() : intakeMotor{INTAKE} {}

void IntakeSubsystem::Set(double set)
{
    intakeMotor.Set(set);
}