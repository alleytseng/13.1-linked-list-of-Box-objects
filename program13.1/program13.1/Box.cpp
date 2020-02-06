//
//  Box.cpp
//  program13.1
//
//  Created by 楊為守 on 2020/1/9.
//  Copyright © 2020年 Alley_Tseng. All rights reserved.
//

#include <stdio.h>
#include "Box.h"
#include <iostream>
using namespace std;
Box::Box(double alength,double abreadth,double aheigth)
{
    cout<<"Box constructor.\n";
    length = alength>0?alength:1.0;
    breadth = abreadth>0?abreadth:1.0;
    height = aheigth>0?aheigth:1.0;
}
/*Box::Box()//ambiguous to above Box constructor
{
    cout<<"Box constructor no argument\n";
}*/
Box::Box(Box &aBox):length(aBox.length), breadth(aBox.breadth), height(aBox.height)
{
    cout<<"Box copy constructor.\n";
}
Box::~Box()
{
    //cout<<"Box destructor called."<<endl;
}
double Box::volume()
{
    return length*breadth*height;
}
double Box::getlength()
{
    return length;
}

double Box::getbreadth()
{
    return breadth;
}

double Box::getheight()
{
    return height;
}

int Box::comparevolume(Box *pbox)//bigger than pbox: return 1, equal: return 0, smaller: return -1
{
    double volume1=volume();
    double volume2=(*pbox).volume();
    return volume1>volume2?1:(volume1==volume2?0:-1);
}





