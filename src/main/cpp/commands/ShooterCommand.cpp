#include "commands/ShooterCommand.h"
#include <frc/Joystick.h>
#include <frc/smartdashboard/SmartDashboard.h>

ShooterCommand::ShooterCommand(ShooterSubsystem *_subsystem) : subsystem(_subsystem)
{
    
}

void ShooterCommand::Execute() {
    if(rightStick.GetRawButton(7)) {
        power = 1.0/6.0;
    } else if(rightStick.GetRawButton(8)) {
        power = 2.0/6.0;
    } else if(rightStick.GetRawButton(9)) {
        power = 3.0/6.0;
    } else if(rightStick.GetRawButton(10)) {
        power = 4.0/6.0;
    } else if(rightStick.GetRawButton(11)) {
        power = 5.0/6.0;
    } else if(rightStick.GetRawButton(12)) {
        power = 1;
    } else {
        power = 0;
    }

    (*subsystem).Set(power);
    
    frc::SmartDashboard::PutNumber("RPM", (*subsystem).GetRPM());
    
}

void ShooterCommand::End(bool interrupted) {
    (*subsystem).Set(0);
}