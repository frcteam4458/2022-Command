#pragma once
#ifndef SERVO_SUBSYSTEM_H
#define SERVO_SUBSYSTEM_H

#include <frc2/command/SubsystemBase.h>
#include <frc/Servo.h>
#include "Constants.h"

class ServoSubsystem : public frc2::SubsystemBase
{
public:
    ServoSubsystem();

    void Set(double set);
    double Get();
    void Periodic() override;
    
    frc::Servo servo;
};
#endif