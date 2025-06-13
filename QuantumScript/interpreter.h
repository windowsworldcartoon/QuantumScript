#pragma once
#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include <vector>

class Interpreter {
public:
    Interpreter();
    void interpret(const std::vector<std::string>& tokens);
};

#endif // INTERPRETER_H