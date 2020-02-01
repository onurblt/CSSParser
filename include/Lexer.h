#ifndef LEXER_H
#define LEXER_H

#include <assert.h>
#include <iostream>
#include <fstream>
#include <streambuf>
#include "Token.h"


class Lexer {
public:
    Lexer() {
        source = "";
        pos = 0;
        start = 0;
        line = 0;
    }

    ~Lexer() {


    }

    inline Token next() {
        // length of the source code.
        int len = source.length();

        // return the end token if this is an empty string
        if (len == 0) {
            Token token;
            token.type = TK_END_OF_INPUT;
            return token;

        }

        // loop while current position index is smaller than the
        // length of the input source.
        while (pos < len) {

            // get current character
            char ch = source[pos];
            char next = pos + 1 < (int)source.length() ? source[pos + 1] : '\0';
            // Set the current token start position and advance the position
            // to point to the next character
            start = pos++;

            // skip if current character is a white space or a new line
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') {
                if (ch == '\n') {
                    line++;
                }
                continue;

            }
            // deal with comments. Comments start with //
            // so check first that next character exists and is not the end of
            // source, secondly test that next character is /
            // (m_pos points to the next character already beacues we incremented it)
            if (ch == '/' && pos < len && next == '/') {
                // skip everything until we encounter either end of string
                // or a new line
                while (++pos < len && source[pos] != '\n');
                line++;
                continue;
            }

            // if this is a alphabetic character
            if (isalpha(ch) || ch=='-')
                return identifier();

            // is the character a number ?
            if (isdigit(ch))
                return number();


            if (ch == '\"' || ch == '\'') {
                return string();
            }


            // match the possible operator
            // if none match then in default set it to invalid
            TokenType type;
            switch (ch) {

            case '{':
                type = TK_BRACE_OPEN;
                break;
            case '}':
                type = TK_BRACE_CLOSE;
                break;
            case '(':
                type = TK_PAREN_OPEN;
                break;
            case ')':
                type = TK_PAREN_CLOSE;
                break;
            case ',':
                type = TK_COMMA;
                break;
            case ':':
                type = TK_COLON;
                break;
            case ';':
                type = TK_SEMICOLON;
                break;
            case '#':
                type=TK_SHARP;
                break;
            default:
                type = TK_INVALID;
                break;
            }
            Token token;
            token.type = type;
            token.value = std::string(source, start, pos - start);
            return token;
        }

        // done iterating through the string. Return EndOfInput Token
        Token token;
        token.type = TK_END_OF_INPUT;
        return token;

    }

    inline Token identifier() {
        // read while position is within the string and
        // next character is a alpha numeric
        while (pos < (int)source.length() && isalnum(source[pos]) || source[pos]=='-') {
            pos++;
        }

        std::string lexeme(source, start, pos - start);

        TokenType type;
        type = TokenType::TK_IDENTIFIER;


        Token token;
        token.type = type;
        token.value = lexeme;

        return token;
    }
    inline Token number() {
        // read while position is within the string and
        // next character is a number
        bool isfloat = false;
        while (pos < (int)source.length() && (isdigit(source[pos]) || source[pos]=='.')) {
            if (source[pos] == '.') {
                if (isfloat) {
                    //ERR_SYNTAX_ERROR
                }

                isfloat = true;
            }
            pos++;
        }
        // Done. Create new token
        Token token;

        token.type = isfloat?TK_FLOAT_LITERAL : TK_INTEGER_LITERAL;
        token.value = std::string(source, start, pos - start);

        return token;
    }

    Token string() {
        // read while position is within the string and
        // next character is a number
       // bool started = false;
        while (pos < (int)source.length()) {
            if (source[pos] == '\'' || source[pos] == '\"') {
                pos++;
                break;
            }
            pos++;
        }
        // Done. Create new token
        Token token;

        token.type = TK_STRING_LITERAL;
        token.value = std::string(source, start+1, pos - start-2);

        return token;
    }

    const int &getLine() const {
        return line;

    }
    inline bool readFile (const std::string& fname) {
        source = "";
        pos = 0;
        start = 0;
        line = 0;

        std::ifstream file(fname);
        if(file.bad()) {
            file.close();
            return false;
        }
        std::string str((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());

        assert(str.length()>0);
        source=str;

        file.close();
        return true;
    }
    inline bool readString (const std::string& str) {
        source = "";
        pos = 0;
        start = 0;
        line = 0;

        assert(str.length()>0);

        source =str;

        return true;
    }

    std::vector<Token> getTokens()
    {
         std::vector<Token> tokens;
        Token tok=next();
        while(tok.type!=TK_END_OF_INPUT) {
            tokens.push_back(tok);
            tok = next();
        }

        return tokens;
    }


private:


    // hold the source code we are lexing
    std::string source;

    // current read position
    int pos;

    // current token start position
    int start;

    int line;


};


#endif
