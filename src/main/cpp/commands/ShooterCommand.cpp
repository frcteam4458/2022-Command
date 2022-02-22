#include "commands/ShooterCommand.h"
#include <frc/Joystick.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <algorithm>
#include <math.h>

ShooterCommand::ShooterCommand(ShooterSubsystem *_subsystem) : subsystem(_subsystem)
{
    power = subsystem->Get();
    AddRequirements(subsystem);
}

ShooterCommand::ShooterCommand(ShooterSubsystem *_subsystem, float _power) : subsystem(_subsystem)
{
    power = _power;
}

ShooterCommand::ShooterCommand(ShooterSubsystem *_subsystem, double _rpm) : subsystem(_subsystem)
{
    rpm = _rpm;
}

void ShooterCommand::Initialize() {
    subsystem->SetRPM(rpm);
}

bool ShooterCommand::IsFinished() {
    // if(abs(subsystem->GetRPM() - subsystem->GetTargetRPM()) < subsystem->GetTargetRPM()*0.025) {
        return true;
    // }
    // return false;
}

void ShooterCommand::End(bool interrupted) {
    
}