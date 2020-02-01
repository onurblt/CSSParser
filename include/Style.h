#ifndef STYLE_H_INCLUDED
#define STYLE_H_INCLUDED

#include <string>
#include <map>
#include <vector>
#include "Attribute.h"




class Style {
public:
    Style() ;
    Style(const char *str);
    Style(const std::string &str);
    
    Attribute &operator[](const std::string &attrName);
    Style& operator=(Style other);
    operator std::string() const; 
    operator const char*() const; 

    friend std::ostream& operator<< (std::ostream& stream, const Style& style)
    {
         for (std::map<std::string,Attribute>::const_iterator it=style.attributeMap.begin();it!=style.attributeMap.end(); it++)
        {
            stream<<"\t";
            stream<<it->first;
            stream<<":";
            stream<<" ";
            stream<<it->second;
            stream<<" ";
            stream<<";";
            stream<<"\n";
        }
        
        return stream;
    }
   friend std::ofstream& operator<< (std::ofstream& stream, const Style& style)
    {
        for (std::map<std::string,Attribute>::const_iterator it=style.attributeMap.begin();it!=style.attributeMap.end(); it++)
        {
           stream<<"\t";
            stream<<it->first;
            stream<<":";
            stream<<" ";
            stream<<it->second;
            stream<<" ";
            stream<<";";
            stream<<"\n";
        }
        
        return stream;
    }
    /*
    friend std::istream & operator >> (std::istream &stream,  Style &style)
    {
        stream>>style.data;
        return stream;
    }
    friend std::ifstream& operator>> (std::ifstream& stream, const Style& style)
    {
        stream>>style.data;
        return stream;
    }
*/
private:
    std::map<std::string,Attribute> attributeMap;
    Lexer lexer;
    void parseAttribute(const std::string &str);
    std::string data;

    void parse();

};



#endif // STYLE_H_INCLUDED
