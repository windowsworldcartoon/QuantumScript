#pragma once
#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <string>

class Token {
public:
    enum Type { IDENTIFIER, SYMBOL, NUMBER, STRING, ERROR }; // Add ERROR here
    Token(Type type, std::string value) : type_(type), value_(value) {}
    Type type_;
    std::string value_;
};

class Lexer {
public:
    std::vector<Token> tokenize(const std::string& code);
};

#endif  // LEXER_H