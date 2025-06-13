#include "lexer.h"
#include <cctype>
#include <string>
#include <vector>

// Keywords recognized by the lexer: if, else, while, for, return, function, var, let, const

enum Type { IDENTIFIER, NUMBER, STRING, SYMBOL, ERROR };

std::vector<Token> Lexer::tokenize(const std::string& code) {
    std::vector<Token> tokens;
    size_t pos = 0;

    while (pos < code.size()) {
        // Skip whitespace
        if (std::isspace(code[pos])) {
            pos++;
            continue;
        }

        // Identifier
        if (std::isalpha(code[pos]) || code[pos] == '_') {
            size_t start = pos;
            while (pos < code.size() && (std::isalnum(code[pos]) || code[pos] == '_')) {
                pos++;
            }
            tokens.push_back(Token(Token::IDENTIFIER, code.substr(start, pos - start)));
        }

        // Number
        else if (std::isdigit(code[pos])) {
            size_t start = pos;
            while (pos < code.size() && std::isdigit(code[pos])) {
                pos++;
            }
            tokens.push_back(Token(Token::NUMBER, code.substr(start, pos - start)));
        }

        // String
        else if (code[pos] == '"') {
            size_t start = pos + 1;
            while (pos < code.size() && code[pos] != '"') {
                pos++;
            }
            tokens.push_back(Token(Token::STRING, code.substr(start, pos - start)));
            pos++; // Skip the closing quote
        }

        // Symbol or unrecognized character
        else {
            // List of valid single-character symbols (customize as needed)
            std::string validSymbols = ";:,.(){}[]+-*/=<>";
            if (validSymbols.find(code[pos]) != std::string::npos) {
                tokens.push_back(Token(Token::SYMBOL, std::string(1, code[pos])));
            } else {
                // Use the ERROR value from the local enum Type, not Token::ERROR
                tokens.push_back(Token(Token::ERROR, std::string(1, code[pos])));
            }
            pos++;
        }
    }

    return tokens;
}