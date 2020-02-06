//
//  List.h
//  program13.1
//
//  Created by 楊為守 on 2020/1/9.
//  Copyright © 2020年 Alley_Tseng. All rights reserved.
//

#ifndef List_h
#define List_h

#include "Box.h"
class Truckload
{
public:
    Truckload(Box *box=0,int count=1);
    Truckload(const Truckload &load); //copy constructor
    ~Truckload();
    Box* getFirstBox();
    Box* getNextBox();
    void addBox(Box *pBox);
private:
    class Package /* 巢狀類別, Package 專門給Truckload 使用 */
    {
    public:
        Package(Box *pNewBox);
        void setNext(Package *pPackage);
    //private://or getFirstBox can't use
        Box *pbox;
        Package *pNext;//自己型態的指標 
    };
    Package *pHead;
    Package *pCurrent;
    Package *pTail;
};

#endif /* List_h */
