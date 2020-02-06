//
//  main.cpp
//  program13.1 13.2
//
//  Created by alley on 2020/1/9.
//  Copyright © 2020年 Alley_Tseng. All rights reserved.
//

#include <iostream>
#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */
#include "Box.h"
#include "List.h"
#include "Carton.h"

using namespace std;

inline int random(int num)
{
    return 1+rand()%num;
}
Box* maxBox(Truckload &load)
{
    Box *pbox=load.getFirstBox();
    //cout<<"Box size: "<<pbox->getlength()<<"x"<<pbox->getbreadth()<<"x"<<pbox->getheight()<<endl;
    Box *pNextBox;
    while(pNextBox=load.getNextBox())
    {
        //cout<<"Box size: "<<pNextBox->getlength()<<"x"<<pNextBox->getbreadth()<<"x"<<pNextBox->getheight()<<endl;
        if(pbox->comparevolume(pNextBox)<0)
            pbox=pNextBox;
    }
    return pbox;
}
int main(int argc, const char * argv[]) {
    
    const int dimLimit=100;
    srand( (int)time(NULL));/* 設定亂數種子 */
    
//   Truckload load1;/* add 5 random size boxes into load1, and find the largest one */
/*    for(int i=0;i<5;i++)
        load1.addBox(new Box(random(dimLimit),random(dimLimit),random(dimLimit)));
    Box *pbox = maxBox(load1);*/
    //cout<<"The largest box in the load1 is "<<pbox->getlength()<<"x"<<pbox->getbreadth()<<"x"<<pbox->getheight()<<endl;
    
    
    int boxCount = 6;/* add 6 random size boxes into load2, and find the largest one */
/*    Box boxes[boxCount];
    for(int i=0;i<boxCount;i++)
        boxes[i]=Box(random(dimLimit),random(dimLimit),random(dimLimit));//print "Box constructor" and "Box destructor called."
    Truckload load2(boxes,boxCount);    //create load2 by Box array
    pbox = maxBox(load2);*/
    //cout<<"The largest box in the load2 is "<<pbox->getlength()<<"x"<<pbox->getbreadth()<<"x"<<pbox->getheight()<<endl;
    
    
/*    Truckload load3(load1); //create load3 by copy constructor
    pbox = maxBox(load3);*/
    //cout<<"The largest box in the load3 is "<<pbox->getlength()<<"x"<<pbox->getbreadth()<<"x"<<pbox->getheight()<<endl;
    
//   Box *pnextBox=load1.getFirstBox();/* load1 used "new" to create box, "new" must be "delete" */
/*    while(pnextBox)
    {
        delete pnextBox;
        pnextBox = load1.getNextBox();
    }*/
    
    Carton carton;
    Carton candyCarton(10,20,30);
    Carton copyCarton(candyCarton);//不只要Carton複製建構函數, Box也要呼叫Box的複製建構函數, 否則長寬高會是預設的1
    cout<<"volume of candyCarton is "<<candyCarton.volume()<<endl;
    cout<<"volume of copyCarton is "<<copyCarton.volume()<<endl;
    return 0;
}
