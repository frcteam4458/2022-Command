#include <frc/geometry/Translation2d.h>

#pragma once

const int FRONT_LEFT = 0;
const int FRONT_RIGHT = 0;
const int BACK_LEFT = 0;
const int BACK_RIGHT = 0;

const int FRONT_LEFT_ENCODER[] = {0, 0};
const int FRONT_RIGHT_ENCODER[] = {0, 0};
const int BACK_LEFT_ENCODER[] = {0, 0};
const int BACK_RIGHT_ENCODER[] = {0, 0};

const int GYRO = 0;

const float PI = 3.141592653589;

frc::Translation2d FL{0_m, 0_m};
frc::Translation2d FR{0_m, 0_m};
frc::Translation2d BL{0_m, 0_m};
frc::Translation2d BR{0_m, 0_m};

constexpr units::meters_per_second_t MAX_SPEED{3.0f};
constexpr units::radians_per_second_t MAX_ROT_SPEED{PI/2.0};

constexpr units::meters_per_second_t ENCODER_DISTANCE_PER_PULSE{0.1f};