//
//  Carton.cpp
//  program13.1
//
//  Created by 楊為守 on 2020/2/5.
//  Copyright © 2020年 Alley_Tseng. All rights reserved.
//

#include "Carton.h"
#include <string.h>
#include <iostream>
using namespace std;

Carton::Carton(char *pStr)
{
    pMertirial = new char[strlen(pStr)+1];
    strcpy(pMertirial, pStr);
    cout<<"Carton constructor 1."<<endl;
    //cout<<"Mertirial:"<<pMertirial<<endl;
}
Carton::Carton(Carton &aCarton):Box(aCarton)//copy constructor, 如果沒有寫Box(aCarton)不會去呼叫Box的copy constructor, 會呼叫預設建構函數
{
    pMertirial = new char[strlen(aCarton.pMertirial)+1];
    strcpy(pMertirial, aCarton.pMertirial);
    cout<<"Carton copy constructor."<<endl;
}

Carton::Carton(double lv,double bv, double hv, char *pStr)//:Box( lv, bv, hv)
{
    length = lv;
    breadth = bv;
    height = hv;
    pMertirial = new char[strlen(pStr)+1];
    strcpy(pMertirial, pStr);
    cout<<"Carton constructor 2."<<endl;
}
Carton::~Carton()
{
    delete [] pMertirial;
}
