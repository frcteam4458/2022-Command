#include <frc/geometry/Translation2d.h>

#pragma once
#ifndef CONSTANTS_H
#define CONSTANTS_H

const int FRONT_LEFT = 0;
const int FRONT_RIGHT = 0;
const int BACK_LEFT = 0;
const int BACK_RIGHT = 0;

const int FRONT_LEFT_ENCODER[] = {0, 0};
const int FRONT_RIGHT_ENCODER[] = {0, 0};
const int BACK_LEFT_ENCODER[] = {0, 0};
const int BACK_RIGHT_ENCODER[] = {0, 0};

const int GYRO = 0;

const int INTAKE = 0;
const int ELEVATOR = 0;
const int FLY_WHEEL = 0;

const float PI = 3.141592653589;

const frc::Translation2d FL{0_m, 0_m};
const frc::Translation2d FR{0_m, 0_m};
const frc::Translation2d BL{0_m, 0_m};
const frc::Translation2d BR{0_m, 0_m};

const units::meters_per_second_t MAX_SPEED{3.0f};
const units::radians_per_second_t MAX_ROT_SPEED{PI/2.0f};

const units::meters_per_second_t ENCODER_DISTANCE_PER_PULSE{0.1f};
#endif