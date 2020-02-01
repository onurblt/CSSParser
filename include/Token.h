#ifndef TOKEN_H
#define TOKEN_H

#include <string>

// TokenType enum holds entries for all possible distinct tokens
// in our grammar and special control tokens
typedef enum  {
    TK_INVALID,        // invalid input. Useful for error handling
    TK_IDENTIFIER,     // identifier like: foo or bar
    TK_BOOL_LITERAL,
    TK_BRACE_OPEN,      // {
    TK_BRACE_CLOSE,     // }
    TK_PAREN_OPEN,      // (
    TK_PAREN_CLOSE,     // )
    TK_COMMA,          // ,
    TK_COLON,          // :
    TK_SEMICOLON,      // ;
    TK_SHARP,      // #
    TK_INTEGER_LITERAL, // 1, 23, 435, -12, 0
    TK_FLOAT_LITERAL,   // 1.1, -45.2, -.5
    TK_STRING_LITERAL,  // "hello world!"
    TK_END_OF_INPUT      // end of the input. Stop lexing further

} TokenType;


// Token structure represents a very simple Token that is returned from
// the lexer. This here holds the token TokenType and its textual value
class Token {
public:
    Token() {

    }
    ~Token() {

    }

    TokenType   type;
    std::string value;
    int         line, column;


    static std::string typeToStr(const TokenType &ttype) {
        if(ttype==TK_INVALID) {
            return "TK_INVALID";
        } else if(ttype==TK_IDENTIFIER) {
            return "TK_IDENTIFIER";
        } else if(ttype==TK_BOOL_LITERAL) {
            return "TK_BOOL_LITERAL";
        } else if(ttype==TK_BRACE_OPEN) {
            return "TK_BRACE_OPEN";
        } else if(ttype==TK_BRACE_CLOSE) {
            return "TK_BRACE_CLOSE";
        } else if(ttype==TK_PAREN_OPEN) {
            return "TK_PAREN_OPEN";
        } else if(ttype==TK_PAREN_CLOSE) {
            return "TK_PAREN_CLOSE";
        } else if(ttype==TK_COMMA) {
            return "TK_COMMA";
        } else if(ttype==TK_COLON) {
            return "TK_COLON";
        } else if(ttype==TK_SEMICOLON) {
            return "TK_SEMICOLON";
        } else if(ttype==TK_INTEGER_LITERAL) {
            return "TK_INTEGER_LITERAL";
        } else if(ttype==TK_FLOAT_LITERAL) {
            return "TK_FLOAT_LITERAL";
        } else if(ttype==TK_STRING_LITERAL) {
            return "TK_STRING_LITERAL";
        } else if(ttype==TK_END_OF_INPUT) {
            return "TK_END_OF_INPUT";
        }

        return "undefined";
    }

};

#endif
