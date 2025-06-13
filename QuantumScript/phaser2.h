#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include <vector>
#include <string>

class Node {
public:
    enum Type {
        EXPR,
        DECL,
        FUNC,
        BLOCK,
        IDENTIFIER,
        LITERAL,
        BINARY_EXPR,
        UNARY_EXPR,
        CALL_EXPR,
        IF_STMT,
        WHILE_STMT,
        FOR_STMT,
        RETURN_STMT
    };
    Node(Type type) : type_(type) {}
    Type type_;
    // ...
};

class Parser {
public:
    Node* parse(const std::vector<Token>& tokens);
};

#endif  // PARSER_H
