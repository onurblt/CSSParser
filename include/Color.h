#ifndef __COLOR_H__
#define __COLOR_H__


class Color
{
    public:
   Color()
    {
        r=255;
        g=255;
        b=255;
        a=255;
    }

    Color(const unsigned char &r_,const unsigned char &g_,const unsigned char & b_,const unsigned char &a_=255)
    {
        r=r_;
        g=g_;
        b=b_;
        a=a_;
    }
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;


 // static  Color White=Color(255,255,255);
};


  

#endif