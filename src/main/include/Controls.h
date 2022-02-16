#pragma once

#ifndef CONTROLS_H
#define CONTROLS_H

#include <frc/Joystick.h>
#include <frc2/command/button/JoystickButton.h>


frc::Joystick leftStick{0};
frc::Joystick rightStick{1};
frc::Joystick secondPlayer{2};

frc2::JoystickButton intakeButton{&leftStick, 0};
frc2::JoystickButton outtakeButton{&leftStick, 6};

frc2::JoystickButton fireButton{&rightStick, 0};
frc2::JoystickButton flywheelButton{&rightStick, 5};

#endif