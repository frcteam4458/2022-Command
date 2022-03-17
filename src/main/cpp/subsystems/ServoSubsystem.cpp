#include "subsystems/ServoSubsystem.h"
#include "Constants.h"
#include <frc/smartdashboard/SmartDashboard.h>

ServoSubsystem::ServoSubsystem() : servo(SERVO)
{}


void ServoSubsystem::Set(double set) {
    servo.Set(set);
}

double ServoSubsystem::Get() {
    return servo.Get();
}

void ServoSubsystem::Periodic() {
    // frc::SmartDashboard::PutNumber("Servo Positon", Get());
}