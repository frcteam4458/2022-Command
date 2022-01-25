#include <frc/geometry/Translation2d.h>
#include <units/length.h>
#include <units/velocity.h>
#include <units/acceleration.h>
#include <units/angular_velocity.h>

#pragma once
#ifndef CONSTANTS_H
#define CONSTANTS_H

const int FRONT_LEFT = 0;
const int FRONT_RIGHT = 1;
const int BACK_LEFT = 2;
const int BACK_RIGHT = 3;

const int FRONT_LEFT_ENCODER[] = {0, 1};
const int FRONT_RIGHT_ENCODER[] = {2, 3};
const int BACK_LEFT_ENCODER[] = {4, 5};
const int BACK_RIGHT_ENCODER[] = {6, 7};

const int GYRO = 0;

const int INTAKE = 4;
const int ELEVATOR = 0;
const int FLY_WHEEL = 0;

const float PI = 3.141592653589;

const frc::Translation2d FL{.254_m, 0.305_m};
const frc::Translation2d FR{.254_m, -0.305_m};
const frc::Translation2d BL{-.254_m, 0.305_m};
const frc::Translation2d BR{-.254_m, -0.305_m};

const units::meters_per_second_t MAX_SPEED{3.0f};
// const units::meters_per_second_squared_t MAX_ACCEL{1.0f};
const units::radians_per_second_t MAX_ROT_SPEED{PI * 2.0f};

const units::meter_t ENCODER_DISTANCE_PER_PULSE{0.001196947f};
#endif