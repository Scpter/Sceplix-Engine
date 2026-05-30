#include <core/logger.h>
#include <core/asserts.h>

int main(void) {
    KFATAL("A test message: %f", 3.14f);
    KERROR("Error test message: %f", 3.14f);
    KWARN("Warn test message: %f", 3.14f);
    KINFO("Info test message: %f", 3.14f);
    KDEBUG("Debug test message: %f", 3.14f);
    KTRACE("Trace test message: %f", 3.14f);
    KASSERT(1 == 0);
    return 0;
}