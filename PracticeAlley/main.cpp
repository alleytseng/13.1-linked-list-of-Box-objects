//
//  main.cpp
//  PracticeAlley
//
//  Created by 楊為守 on 2019/10/22.
//  Copyright © 2019年 WeiShou_Yang. All rights reserved.
//

#include <iostream>
using namespace std;

void bubbleSort(int *pointer, const int maxNum)
{
    /*for(int i=0;i<maxNum;i++)
        cout<<*(pointer+i)<<"\t";*/
    cout<<endl;
    bool swap = 0;
    int run = 0;
    do{
        swap = 0;
        for(int i=0;i<maxNum-1-run;i++)
        {
            if((*(pointer+i)) > (*(pointer+i+1)))
            {
                swap = 1;
                int tmp = *(pointer+i);
                *(pointer+i) = *(pointer+i+1);
                *(pointer+i+1) =tmp;
            }
        }
        run++;
/*        for(int i=0;i<maxNum;i++)
            cout<<*(pointer+i)<<"\t";
        cout<<endl;*/
    }while(swap==1);//cout<<"Run number:"<<run<<endl;

}

void insertionSort(int *pointer,const int maxNum)
{
    for(int i=1;i<maxNum;i++)
    {
        int currentIndex=i;
        while(currentIndex>0 && *(pointer+currentIndex) < *(pointer+currentIndex-1))
        {
            int tmp = *(pointer+currentIndex);
            *(pointer+currentIndex)= *(pointer+currentIndex-1);
            *(pointer+currentIndex-1) = tmp;
            currentIndex--;
        }
    }
    
}

void quickSort(int *pointer,const int minNum,const int maxNum)
{
    int left = minNum+1;
    int right = maxNum-1;
    while(left<right)
    {
        while(left<maxNum-1 && *(pointer+left)<*(pointer+minNum))
            left++;
        while(right>minNum && *(pointer+right)>*(pointer+minNum))
            right--;
        if(left<right)
        {
            int tmp = *(pointer+right);
            *(pointer+right) = *(pointer+left);
            *(pointer+left) = tmp;
        }
        else
            break;
    }
    if(*(pointer+right)<*(pointer+minNum))
    {
        int tmp = *(pointer+right);
        *(pointer+right)=*(pointer+minNum);
        *(pointer+minNum)=tmp;cout<<endl;
    }
    for(int i=0;i<maxNum;i++)
     cout<<*(pointer+i)<<"\t";
     cout<<endl;
    if(right-2>minNum)
        quickSort(pointer,minNum,right);
    if(right+2<maxNum)
        quickSort(pointer,right+1,maxNum);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    const int maxNum=10;
    //int datas[maxNum]={7,2,3,6,8,10,1,4,9,5};
    int datas[maxNum]={10,1,8,7,6,5,4,3,2,9};
    cout<<"Unsorted Data: ";
    for(int i=0;i<maxNum;i++)
        cout<<datas[i]<<"\t";
    //bubbleSort(datas,maxNum);
    //insertionSort(&datas[0],maxNum);//call by address?
    quickSort(datas,0,maxNum);
    //foo();
    cout<<"  Sorted Data: ";
    for(int i=0;i<maxNum;i++)
        cout<<datas[i]<<"\t";
    cout << "\nHello, World!\n";
    return 0;
}
