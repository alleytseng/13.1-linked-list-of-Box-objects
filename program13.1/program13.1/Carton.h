//
//  Carton.hpp
//  program13.1
//
//  Created by 楊為守 on 2020/2/5.
//  Copyright © 2020年 Alley_Tseng. All rights reserved.
//

#ifndef Carton_h
#define Carton_h

#include <stdio.h>
#include "Box.h"
class Carton: public Box
{
public:
    Carton(char *pString = "Carboard");
    Carton(Carton &aCorton);
    Carton(double lv,double bv, double hv, char *pString = "Carboard");
    ~Carton();
private:
    char *pMertirial;
};
#endif /* Carton_hpp */
