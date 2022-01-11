#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMSparkMax.h>

class IntakeSubsystem : public frc2::SubsystemBase {
	public:
		IntakeSubsystem();
		void ToggleIntake();
	private:
		frc::PWMSparkMax intake;
		bool intakeSpeed = 0;
};