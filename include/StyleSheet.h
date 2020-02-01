#ifndef STYLESHEET_H_INCLUDED
#define STYLESHEET_H_INCLUDED

#include <map>
#include "Style.h"

class StyleSheet
{
public:
    StyleSheet();
    StyleSheet(const char *str);
    StyleSheet(const std::string &str);

    ~StyleSheet();

    StyleSheet &operator=(StyleSheet other);
    operator std::string() const;
    operator const char *() const;

    bool readFile(const std::string &fileName);
    bool writeFile(const std::string &fileName);

    Style &operator[](const std::string &styleName);

    friend std::ostream &operator<<(std::ostream &stream, const StyleSheet &stylesheet)
    {
        for (std::map<std::string, Style>::const_iterator it = stylesheet.styleMap.begin(); it != stylesheet.styleMap.end(); it++)
        {
            stream << it->first;
            stream << " ";
            stream << "{";
            stream << "\n";
            stream << it->second;
            stream << "}";
            stream << "\n\n";
        }
        return stream;
    }
    friend std::ofstream &operator<<(std::ofstream &stream, const StyleSheet &stylesheet)
    {
        for (std::map<std::string, Style>::const_iterator it = stylesheet.styleMap.begin(); it != stylesheet.styleMap.end(); it++)
        {
            stream << it->first;
            stream << " ";
            stream << "{";
            stream << "\n";
            stream << it->second;
            stream << "}";
            stream << "\n\n";
        }
        return stream;
    }
    /*
    friend std::istream & operator >> (std::istream &stream,  StyleSheet &stylesheet)
    {
        stream>>stylesheet.data;
        return stream;
    }
    friend std::ifstream& operator>> (std::ifstream& stream, const StyleSheet& stylesheet)
    {
        stream>>stylesheet.data;
        return stream;
    }
*/
private:
    bool readString();
    //void require(TokenType type);

    Lexer lexer;
    std::vector<Token> tokens;
    std::map<std::string, Style> styleMap;

    std::string data;
};

#endif // STYLESHEET_H_INCLUDED
