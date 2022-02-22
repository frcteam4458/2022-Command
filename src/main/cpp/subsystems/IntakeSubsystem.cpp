#include "subsystems/IntakeSubsystem.h"

#include "Constants.h"

IntakeSubsystem::IntakeSubsystem() : intakeMotor{INTAKE}, s_intakeMotor{INTAKE} {}

void IntakeSubsystem::Set(double set)
{
    intakeMotor.Set(set);
    s_intakeMotor.SetSpeed(set);
}