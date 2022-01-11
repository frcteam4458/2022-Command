#pragma once
#ifndef INTAKE_H
#define INTAKE_H

#include <frc/motorcontrol/PWMSparkMax.h>

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class Intake : public frc2::CommandHelper<frc2::CommandBase, Intake> {
    public:
        explicit Intake();
        void Execute() override;
        void End(bool interrupted) override;
    private:
        frc::PWMSparkMax intake;
};
#endif