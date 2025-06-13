#include "lexer.h"
#include "interpreter.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    Lexer lexer;
    Interpreter interpreter;

    if (argc > 1) {
        // Script mode: read from .qs file
        std::ifstream file(argv[1]);
        if (!file) {
            std::cerr << "Could not open file: " << argv[1] << std::endl;
            return 1;
        }
        std::string code((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        auto tokens = lexer.tokenize(code);
        std::vector<std::string> tokenValues;
        for (const auto& token : tokens) {
            tokenValues.push_back(token.value_);
        }
        interpreter.interpret(tokenValues);
    } else {
        // Interactive mode (REPL)
        std::cout << "QuantumScript CLI (type 'exit' to quit)" << std::endl;
        std::string line;
        while (true) {
            std::cout << ">>> ";
            if (!std::getline(std::cin, line) || line == "exit") break;
            auto tokens = lexer.tokenize(line);
            std::vector<std::string> tokenValues;
            for (const auto& token : tokens) {
                tokenValues.push_back(token.value_);
            }
            interpreter.interpret(tokenValues);
        }
    }
    return 0;
}