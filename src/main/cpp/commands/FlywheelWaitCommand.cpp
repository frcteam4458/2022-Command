#include "commands/FlywheelWaitCommand.h"
#include <math.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "Constants.h"
FlywheelWaitCommand::FlywheelWaitCommand(ShooterSubsystem *_subsystem) : subsystem(_subsystem) {}

bool FlywheelWaitCommand::IsFinished() {
    if(subsystem->GetRPM() * (1 - FLYWHEEL_PERCENT_MARGIN) < subsystem->GetTargetRPM() && subsystem->GetTargetRPM() < subsystem->GetRPM() * (1 + FLYWHEEL_PERCENT_MARGIN)) return true;
    return false;
}

void FlywheelWaitCommand::End(bool interrupted) {

}