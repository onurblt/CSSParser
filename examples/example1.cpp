#include "StyleSheet.h"


int main()
{

    StyleSheet css;

    //load a CSS file
    css.readFile("examples/example1.css");
    
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


