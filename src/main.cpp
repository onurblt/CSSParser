/*
#include "StyleSheet.h"
#include "utest/utest.h"

#ifdef _MSC_VER
// disable 'conditional expression is constant' - our examples below use this!
#pragma warning(disable : 4127)
#endif

UTEST(css, readString) {

    StyleSheet css;
    css="p{ color: rgb(255,0,0); text-align: center ; } ";
    std::cout<<css["p"]<<std::endl;
    Color color=css["p"]["color"];
    ASSERT_EQ(255,color.r);
    ASSERT_EQ(0,color.g);
    ASSERT_EQ(0,color.b);
    ASSERT_EQ(255,color.a);
    std::string text_align=css["p"]["text-align"];
    ASSERT_STREQ("center",text_align.c_str());
}

UTEST(css, color) {

    StyleSheet css;
    std::string cssText="p{ color: rgb(255,0,0); color2: red ; color3: rgba(255,255,255,0.5) ;";
    cssText+="color4:#0000FF; } ";

    css=cssText;
    Color color=css["p"]["color"];
    ASSERT_EQ(255,color.r);
    ASSERT_EQ(0,color.g);
    ASSERT_EQ(0,color.b);
    ASSERT_EQ(255,color.a);

    Color color2=css["p"]["color2"];
    ASSERT_EQ(255,color2.r);
    ASSERT_EQ(0,color2.g);
    ASSERT_EQ(0,color2.b);
    ASSERT_EQ(255,color2.a);

    Color color3=css["p"]["color3"];
    ASSERT_EQ(255,color3.r);
    ASSERT_EQ(255,color3.g);
    ASSERT_EQ(255,color3.b);
    ASSERT_EQ(127,color3.a);

    Color color4=css["p"]["color4"];
    ASSERT_EQ(0,color4.r);
    ASSERT_EQ(0,color4.g);
    ASSERT_EQ(255,color4.b);
    ASSERT_EQ(255,color4.a);
   

    css["p"]["color5"]="rgb(128,0,128)";
    ASSERT_EQ(128,((Color)css["p"]["color5"]).r);
    ASSERT_EQ(0,((Color)css["p"]["color5"]).g);
    ASSERT_EQ(128,((Color)css["p"]["color5"]).b);
    ASSERT_EQ(255,((Color)css["p"]["color5"]).a);
    
}
UTEST(css, modify_attribute) {

    StyleSheet css;
    css["p"]["size"]=123;
    ASSERT_EQ(123,(int)css["p"]["size"]);

    css["p"]["size"]=35;
    ASSERT_EQ(35,(int)css["p"]["size"]);


}
*/
/*
int main()
{
    StyleSheet css;
    css.readFile("test.css");
    Color color=css["eye"]["color"];
    printf("%d,%d,%d,%d\n",color.r,color.g,color.b,color.a);
    int size=css["eye"]["font-size"];
    printf("%d\n",size);
    color=css["mouth"]["color"];
    printf("%d,%d,%d,%d\n",color.r,color.g,color.b,color.a);


    //system("pause");
    std::getchar();

    return 0;
}



UTEST_MAIN()
*/