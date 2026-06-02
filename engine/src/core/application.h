#pragma once

#include "defines.h"

struct game;

typedef struct application_config {
    // windows starting posision x axis, if applicable.
    i16 start_pos_x;

    // Windows starting position y axis, if applicable.
    i16 start_pos_y;

    // Windows starting width if applicable.
    i16 start_width;

    // windows starting height if applicable.
    i16 start_height;

    // The application name used in windowing
    char* name;
} application_config;

KAPI b8 application_create(struct game* game_inst);

KAPI b8 application_run();