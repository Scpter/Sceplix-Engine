#include <core/logger.h>
#include <core/asserts.h>

// Test
#include <platform/platform.h>

int main(void) {
    KFATAL("A test message: %f", 3.14f);
    KERROR("Error test message: %f", 3.14f);
    KWARN("Warn test message: %f", 3.14f);
    KINFO("Info test message: %f", 3.14f);
    KDEBUG("Debug test message: %f", 3.14f);
    KTRACE("Trace test message: %f", 3.14f);
    // KASSERT(1 == 0);

    platform_state state;
    if (platform_startup(&state, "Sceplix Engine First Run", 100, 100, 1280, 720)) {
        while (TRUE) {
           platform_pump_messages(&state);
        }
    }
    platform_shutdown(&state);

    return 0;
}