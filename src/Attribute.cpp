
#include <assert.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "Attribute.h"

std::map<std::string, Color> predefinedColors = {
    {"aqua", Color(0, 255, 255)},
    {"azure", Color(240, 255, 255)},
    {"beige", Color(245, 245, 220)},
    {"bisque", Color(255, 228, 196)},
    {"black", Color(0, 0, 0)},
    {"blue", Color(0, 0, 255)},
    {"brown", Color(165, 42, 42)},
    {"chartreuse", Color(127, 255, 0)},
    {"chocolate", Color(210, 105, 30)},
    {"coral", Color(255, 127, 80)},
    {"cornsilk", Color(255, 248, 220)},
    {"crimson", Color(220, 20, 60)},
    {"cyan", Color(0, 255, 255)},
    {"fuchsia", Color(255, 0, 255)},
    {"gainsboro", Color(220, 220, 220)},
    {"gold", Color(255, 215, 0)},
    {"gray", Color(128, 128, 128)},
    {"grey", Color(128, 128, 128)},
    {"green", Color(0, 128, 0)},
    {"indigo", Color(75, 0, 130)},
    {"ivory", Color(255, 255, 240)},
    {"khaki", Color(240, 230, 140)},
    {"lavender", Color(230, 230, 250)},
    {"lime", Color(0, 255, 0)},
    {"linen", Color(250, 240, 230)},
    {"magenta", Color(255, 0, 255)},
    {"maroon", Color(128, 0, 0)},
    {"moccasin", Color(255, 228, 181)},
    {"navy", Color(0, 0, 128)},
    {"olive", Color(128, 128, 0)},
    {"orange", Color(255, 165, 0)},
    {"orchid", Color(218, 112, 214)},
    {"peru", Color(235, 233, 63)},
    {"pink", Color(255, 192, 203)},
    {"plum", Color(221, 160, 221)},
    {"purple", Color(128, 0, 128)},
    {"red", Color(255, 0, 0)},
    {"salmon", Color(250, 128, 114)},
    {"sienna", Color(160, 82, 45)},
    {"silver", Color(192, 192, 192)},
    {"snow", Color(255, 250, 250)},
    {"tan", Color(210, 180, 140)},
    {"thistle", Color(216, 191, 216)},
    {"tomato", Color(255, 99, 71)},
    {"turquoise", Color(64, 224, 208)},
    {"violet", Color(238, 130, 238)},
    {"wheat", Color(245, 222, 179)},
    {"white", Color(245, 245, 245)},
    {"yellow", Color(255, 255, 0)}};

Attribute::Attribute()
{
    data = "";
}
Attribute::~Attribute()
{
}

Attribute::Attribute(const int &i)
{
    try
    {
        data = std::to_string(i);
    }
    catch (const std::exception &e)
    {
        //std::cerr << e.what() << '\n';
        data = "";
    }
}
Attribute::Attribute(const float &f)
{
    try
    {
        data = std::to_string(f);
    }
    catch (const std::exception &e)
    {
        //std::cerr << e.what() << '\n';
        data = "";
    }
}
Attribute::Attribute(const std::string &str)
{
    data = str;
}

Attribute::Attribute(const char *str)
{
    data = str;
}
Attribute::Attribute(const Color &color)
{
    data = "rgba(";
    data += std::to_string(color.r);
    data += ",";
    data += std::to_string(color.g);
    data += ",";
    data += std::to_string(color.b);
    data += ",";
    data += std::to_string(color.a);
    data += ")";
}

Attribute::operator std::string() const
{
    return data;
}

Attribute::operator const char *() const
{
    return data.c_str();
}
Attribute::operator float() const
{
    try
    {
        return std::stof(data);
    }
    catch (const std::exception &e)
    {
        //std::cerr << e.what() << '\n';
    }
    return 0.0f;
}

Attribute::operator int() const
{
    try
    {
        return std::stoi(data);
    }
    catch (const std::exception &e)
    {
        //std::cerr << e.what() << '\n';
    }
    return 0;
}
Attribute::operator Color() const
{
    try
    {
        Lexer lexer;
        lexer.readString(data);
        std::vector<Token> tokens = lexer.getTokens();

        if (tokens[0].value == "rgba")
        {
            int r = std::stoi(tokens[2].value);
            int g = std::stoi(tokens[4].value);
            int b = std::stoi(tokens[6].value);
            int a = std::stof(tokens[8].value) * 255.0f;
            return Color(r, g, b, a);
        }
        else if (tokens[0].value == "rgb")
        {
            int r = std::stoi(tokens[2].value);
            int g = std::stoi(tokens[4].value);
            int b = std::stoi(tokens[6].value);
            return Color(r, g, b);
        }
        else if (tokens[0].type == TK_SHARP)
        {
            std::string hex = "";
            for (size_t i = 1; i < tokens.size(); i++)
            {
                hex += tokens[i].value;
            }

            unsigned int color = std::stoi(hex, 0, 16);
            unsigned int red = (color >> 16) & 0xFF;
            unsigned int green = (color >> 8) & 0xFF;
            unsigned int blue = (color)&0xFF;
            return Color(red, green, blue);
        }
        else
        {
            std::string cpy = tokens[0].value;
            std::transform(cpy.begin(), cpy.end(), cpy.begin(), ::tolower);

            //std::cout<<"val,"<<cpy<<std::endl;
            if (predefinedColors.find(cpy) != predefinedColors.end())
            {
                return predefinedColors[cpy];
            }
        }
    }
    catch (const std::exception &e)
    {
        //std::cerr << e.what() << '\n';
    }
    return Color();
}
Attribute &Attribute::operator=(Attribute other)
{
    std::string temp = other.data;
    other.data = data;
    data = temp;
    return *this;
}
