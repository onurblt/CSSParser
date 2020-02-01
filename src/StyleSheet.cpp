#include <regex>
#include "StyleSheet.h"

static std::regex style_regex("(^|\\w|\\-)+\\s*\\{(\\s|\\n|\\w|\\(|\\)|\\,|\\.|\\:|\\;|\\-|\\#)*\\}");

StyleSheet::StyleSheet() {
    data="";
}
StyleSheet::StyleSheet(const char *str)
{
    data=str;
}


StyleSheet::StyleSheet(const std::string &str)
{
    data=str; 
    readString();
}
StyleSheet::~StyleSheet() {
        styleMap.clear();
        tokens.clear();
}
StyleSheet& StyleSheet::operator=(StyleSheet other)
{
    std::string temp = other.data;
    other.data = data;
    data = temp;
    readString();
    return *this;
}
StyleSheet::operator const char*() const
{
    return data.c_str();
}


StyleSheet::operator std::string() const
{
    return data;

}

bool StyleSheet::readFile(const std::string &fname)
{
    styleMap.clear();
    tokens.clear();
    //if(!lexer.readFile(fname)) {
    //    return false;
    //}

    std::ifstream file(fname);
    if (file.bad())
    {
        file.close();
        return false;
    }
    data=std::string((std::istreambuf_iterator<char>(file)),
                       std::istreambuf_iterator<char>());

    assert(data.length() > 0);

    file.close();
    return readString();
   
}

bool StyleSheet::writeFile(const std::string &fileName)
{
    std::ofstream file(fileName);
    if(file.bad())
    {
        file.close();
        return false;
    }
    file<<*this;
    
    file.close();
    return true;
}
bool StyleSheet::readString()
{
    styleMap.clear();
    tokens.clear();

    std::smatch match;
    try
    {
        std::sregex_iterator next(data.begin(), data.end(), style_regex);
        std::sregex_iterator end;
        while (next != end)
        {
            std::smatch match = *next;
            //std::cout << match.str() << "\n";
            lexer.readString(match.str());
            std::vector<Token> tokens=lexer.getTokens();
            std::string name = tokens[0].value;
            std::string other="";
            for (size_t i = 1; i < tokens.size(); i++)
            {
               other+=tokens[i].value;
            }
            
            styleMap[name]=other;
            //std::cout<< ((std::string)styleMap[name])<<std::endl;
            next++;
        }
    }
    catch (std::regex_error &e)
    {
        // Syntax error in the regular expression
        std::cout << e.what() << std::endl;
        return false;
    }
    return true;
}


Style &StyleSheet::operator[](const std::string &styleName)
{
    return styleMap[styleName];
}