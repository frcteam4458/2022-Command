#include "commands/ShooterCommand.h"
#include <frc/Joystick.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <algorithm>

ShooterCommand::ShooterCommand(ShooterSubsystem *_subsystem) : subsystem(_subsystem)
{
    power = subsystem->Get();
    AddRequirements(subsystem);
}

ShooterCommand::ShooterCommand(ShooterSubsystem *_subsystem, float _power)
{
    power = _power;
}

ShooterCommand::ShooterCommand(ShooterSubsystem *_subsystem, double _rpm)
{
    rpm = _rpm;
}

void ShooterCommand::Execute() {
    if(rpm == -2) {
        subsystem->Set(power);
        frc::SmartDashboard::PutNumber("RPM", (*subsystem).GetRPM());
        return;
    }

    error = rpm - subsystem->GetRPM();
    subsystem->Set(std::clamp(subsystem->Get() + 0.05 * error, -1.0, 1.0));

}

void ShooterCommand::End(bool interrupted) {
    // (*subsystem).Set(0);
}