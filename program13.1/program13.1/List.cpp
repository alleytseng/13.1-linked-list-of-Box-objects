//
//  List.cpp
//  program13.1
//
//  Created by 楊為守 on 2020/1/9.
//  Copyright © 2020年 Alley_Tseng. All rights reserved.
//

#include <stdio.h>
#include "List.h"
#include "Box.h"
#include <iostream>
using namespace std;

Truckload::Truckload(Box *pbox,int count)
{
    //cout<<"Truckload constructor."<<endl;
    pHead=pCurrent=pTail=0;
    if(pbox != 0)
    {
        for(int i=0;i<count;i++)
            addBox(pbox+i);
    }
}
Truckload::Truckload(const Truckload &load)
{
    //cout<<"copy Truckload constructor."<<endl;
    pHead=pCurrent=pTail=0;
    if(load.pHead==0)
        return;
    Package *ptmp;
    ptmp=load.pHead;
    do{
        addBox(ptmp->pbox);
    }while(ptmp=ptmp->pNext);
    
}
Truckload::~Truckload()
{
    //cout<<"Truckload destructor."<<endl;
    //int i=0;
    pCurrent=pHead->pNext;
    while(pCurrent)
    { //i++;
        delete pHead;
        pHead = pCurrent;
        pCurrent = pHead->pNext;
    }//cout<<"\n### delete "<< i+1 <<" times \n\n";
    delete pHead;
}
void Truckload::addBox(Box *pBox)
{
    Package *pPackage = new Package(pBox);
    if(pHead)
        pTail->pNext = pPackage;//pTail->setNext(pPackage);
    else
        pHead = pPackage;
    pTail = pPackage;
    //delete pPackage in Truckload destructor
}
Box* Truckload::getFirstBox()
{
    pCurrent=pHead;
    return pCurrent->pbox;
}
Box* Truckload::getNextBox()
{
    if(pCurrent)
        pCurrent=pCurrent->pNext;
    else
        pCurrent=pHead;
    return pCurrent?pCurrent->pbox:0;
}
Truckload::Package::Package(Box *pNewBox):pbox(pNewBox),pNext(0)
{
}
void Truckload::Package::setNext(Package *pPackage)
{
    pNext=pPackage;
}
