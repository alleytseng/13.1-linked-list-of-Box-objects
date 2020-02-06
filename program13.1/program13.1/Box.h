//
//  Box.h
//  program13.1
//
//  Created by 楊為守 on 2020/1/9.
//  Copyright © 2020年 Alley_Tseng. All rights reserved.
//

#ifndef Box_h
#define Box_h

class Box
{
public:
    Box(double length=1.0,double breadth=1.0,double heigth=1.0);//constructer
    //Box();//Call to constructor of 'Box' is ambiguous
    Box(Box &aBox);//copy constructor
    ~Box();
    double volume();
    
    double getlength();
    double getbreadth();
    double getheight();
    
    int comparevolume(Box* pbox);
protected: //private: 設定為保護 確保繼承他的Carton 能使用
    double length;
    double breadth;
    double height;
};

#endif /* Box_h */
