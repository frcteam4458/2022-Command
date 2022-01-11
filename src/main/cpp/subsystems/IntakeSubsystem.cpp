#include "subsystems/IntakeSubsystem.h"
#include "Constants.h"

IntakeSubsystem::IntakeSubsystem() : intake{INTAKE} {

}

void IntakeSubsystem::ToggleIntake() {
	intakeSpeed = !intakeSpeed;
	intake.Set(intakeSpeed);
}