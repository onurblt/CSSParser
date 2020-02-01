#ifndef __ATTRIBUTE_H__
#define __ATTRIBUTE_H__

#include <fstream>
#include <iostream>
#include <streambuf>
#include <string>
#include "Lexer.h"
#include "Color.h"

class Attribute
{
    public:
    Attribute();
    Attribute(const int &i);
    Attribute(const float &f);
    Attribute(const char *str);
    Attribute(const std::string &str);
    Attribute(const Color &color);

    virtual ~Attribute();
    

    Attribute& operator=(Attribute other);
    operator int() const;
    operator float() const;
    operator std::string() const; 
    operator const char*() const; 
    operator Color() const;
    friend std::ostream& operator<< (std::ostream& stream, const Attribute& attribute)
    {
        stream<<attribute.data;
        return stream;
    }
   friend std::ofstream& operator<< (std::ofstream& stream, const Attribute& attribute)
    {
        stream<<attribute.data;
        return stream;
    }
    /*
    friend std::istream & operator >> (std::istream &stream,  Attribute &attribute)
    {
        stream>>attribute.data;
        return stream;
    }
       friend std::ifstream& operator>> (std::ifstream& stream, const Attribute& attribute)
    {
        stream>>attribute.data;
        return stream;
    }
    */

private:
    std::string data;
};

#endif