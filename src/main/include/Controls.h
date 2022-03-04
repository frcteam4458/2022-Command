#pragma once

#ifndef CONTROLS_H
#define CONTROLS_H

#include <frc/Joystick.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/XboxController.h>

frc::Joystick leftStick{0};
frc::Joystick rightStick{1};
frc::Joystick thirdStick{2};
frc::XboxController controller{0};

frc2::JoystickButton intakeButton{&thirdStick, 2};
frc2::JoystickButton outtakeButton{&thirdStick, 6};

frc2::JoystickButton feedButton{&thirdStick, 7};

frc2::JoystickButton fireButton{&thirdStick, 1};
frc2::JoystickButton flywheelFastButton{&thirdStick, 3};
frc2::JoystickButton flywheelSlowButton{&thirdStick, 5};
frc2::JoystickButton flywheelStopButton{&thirdStick, 4};

frc2::JoystickButton climbUpButton{&thirdStick, 11};
frc2::JoystickButton climbDownButton{&thirdStick, 10};

frc2::JoystickButton lightButton{&controller, 2};

frc2::JoystickButton servoCloseButton{&thirdStick, 8};
frc2::JoystickButton servoOpenButton{&thirdStick, 9};
#endif