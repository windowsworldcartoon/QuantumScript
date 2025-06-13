#include "interpreter.h"
#include <iostream>

Interpreter::Interpreter() {
    // Initialization code if needed
}

void Interpreter::interpret(const std::vector<std::string>& tokens) {
    // Simple demonstration: print each token
    for (const auto& token : tokens) {
        std::cout << "Interpreting token: " << token << std::endl;
    }
}