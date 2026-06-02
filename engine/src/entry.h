#pragma once

#include "core/application.h"
#include "core/logger.h"
#include "game_types.h"

// Externally-defined function to create a game.
extern b8 create_game(game* out_game);

// The main entry point of the application
int main(void) {

    // Request game instance from the application.
    game game_inst;
    if (!create_game(&game_inst)) {
        KFATAL("Could not create game!");
        return -1;
    }

    // ensure that the function pointers actually exists
    if (!game_inst.render || !game_inst.update || !game_inst.initialize || !game_inst.on_resize) {
        KFATAL("The game's function pointer must be assigned!");
        return -2;
    }

    // Initializes the application
    if (!application_create(&game_inst)) {
        KINFO("Application failed to create!");
        return 1;
    }

    // Begins the game loop
    if (!application_run()) {
        KINFO("Application did not shutdown gracefully.");
        return 2;
    }

    return 0;
}