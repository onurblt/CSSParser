# CSSParser
a CSSParser for C++ with CC0 license

* Used SFML for color
* Easy to use

# Example

```c++
#include "styleSheet.h"
...
StyleSheet css;
css.readFile("test.css");
sf::Color color=css.styleMap["eye"].getAs<sf::Color>("color");
printf("%d,%d,%d,%d\n",color.r,color.g,color.b,color.a);
...
int size=css.styleMap["eye"].getAs<int>("font-size");
printf("%d\n",size);
```
