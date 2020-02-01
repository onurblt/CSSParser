# CSSParser
a CSSParser(WIP) for C++ with CC0 license

* Easy to use
* Doesnt support selectors yet

# Example

```c++
#include "StyleSheet.h"


int main()
{

    StyleSheet css;

    //load a CSS file
    css.readFile("examples/example1.css");
    
    //Or simply assign a CSS string
    css="h1 {color: #36CFFF; text-align: center;}  body {background-color: lightblue;} p {font-family: verdana;font-size:20px;}";

    
    //accessing
    std::cout<<css<<std::endl;
    std::cout<<css["h1"]<<std::endl;
    std::cout<<css["h1"]["color"]<<std::endl;
    std::cout<<css["p"]["font-size"]<<std::endl;

    //manipulating
    css["p"]["font-size"]="35px";
    std::cout<<css["p"]["font-size"]<<std::endl;

    //write to file
    css.writeFile("examples/out1.css");

    return 0;
}


```
