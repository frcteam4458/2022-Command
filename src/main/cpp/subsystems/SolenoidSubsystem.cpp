#include "subsystems/SolenoidSubsystem.h"

#include "Constants.h"

SolenoidSubsystem::SolenoidSubsystem(frc::PneumaticsModuleType moduleType) : leftSolenoid{moduleType, LEFT_SOLENOID},
                                                                             rightSolenoid{moduleType, RIGHT_SOLENOID}
{

}

void SolenoidSubsystem::Set(bool set)
{
    leftSolenoid.Set(set);
    rightSolenoid.Set(set);
}

bool SolenoidSubsystem::Toggle()
{
    leftSolenoid.Toggle();
    rightSolenoid.Toggle();

    return leftSolenoid.Get();
}