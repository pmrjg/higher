#include <exception>
#include <iostream>
#include <ostream>

#include "ops/Triangle.h"

int main() {
    Triangle app;

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}