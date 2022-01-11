#include "commands/Intake.h"
#include "Constants.h"

Intake::Intake() : intake{INTAKE} {}

void Intake::Execute()
{
    intake.Set(1);
}

void Intake::End(bool interrupted)
{
    intake.Set(0);
}