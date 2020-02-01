#include <regex>
#include "Style.h"

static std::regex attribute_regex("(^|\\w|\\-)+\\s*\\:\\s*(^|\\n|\\w|\\(|\\)|\\,|\\.|\\-|\\#)+\\s*\\;");

Style::Style()
{
    data="";
}

Style::Style(const char *str)
{
    data=str;
}
Style::Style(const std::string &str)
{
    data=str;
    parse();
}
Style& Style::operator=(Style other)
{
    std::string temp = other.data;
    other.data = data;
    data = temp;
    parse();

    return *this;
}

Style::operator std::string() const
{
    return data;
}

Style::operator const char*() const
{
    return data.c_str();
}


Attribute &Style::operator[](const std::string &attrName)
{
 
    return attributeMap[attrName];
}

void Style::parseAttribute(const std::string &str)
{

    lexer.readString(str);
    std::vector<Token> tokens = lexer.getTokens();

    std::string name = tokens[0].value;

    std::string value = "";
    //size - 1 because semicolon
    for (int i = 2; i < (int)tokens.size() - 1; i++)
    {
        value += tokens[i].value;
    }

    attributeMap[name] = Attribute(value);
    //std::cout << "attr," << name << "," << value << std::endl;
}

void Style::parse()
{

    std::smatch match;
    try
    {
        std::sregex_iterator next(data.begin(), data.end(), attribute_regex);
        std::sregex_iterator end;
        while (next != end)
        {
            std::smatch match = *next;
           // std::cout << match.str() << "\n";
            parseAttribute(match.str());
            next++;
        }
    }
    catch (std::regex_error &e)
    {
        // Syntax error in the regular expression
        std::cout << e.what() << std::endl;
    }
}