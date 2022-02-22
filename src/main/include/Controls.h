#pragma once

#ifndef CONTROLS_H
#define CONTROLS_H

#include <frc/Joystick.h>
#include <frc2/command/button/JoystickButton.h>


frc::Joystick leftStick{0};
frc::Joystick rightStick{1};
frc::Joystick thirdStick{2};

frc2::JoystickButton intakeButton{&thirdStick, 2};
frc2::JoystickButton outtakeButton{&thirdStick, 6};

frc2::JoystickButton fireButton{&thirdStick, 1};
frc2::JoystickButton flywheelFastButton{&thirdStick, 3};
frc2::JoystickButton flywheelSlowButton{&thirdStick, 5};
frc2::JoystickButton flywheelStopButton{&thirdStick, 4};

#endif