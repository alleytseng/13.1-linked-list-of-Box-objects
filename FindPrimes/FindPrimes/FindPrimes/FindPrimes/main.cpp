//
//  main.cpp
//  FindPrimes: 使用動態記憶體配置找質數
//
//  Created by 楊為守 on 2019/12/5.
//  Copyright © 2019年 Alley_Tseng. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int inputNum = 0;
    cout << "How many primes do you want to show?\n";
    cin>>inputNum;
//    int primes[inputNum];
//    int *p = primes;
    int *p =new int[inputNum];
    *p = 2;
    *(p+1) = 3;
    *(p+2) = 5;
    int primesNum = 3;
    int candidate = 5;
    while(primesNum<inputNum)
    {
        bool isPrime = true;
        candidate = candidate+2;
        for(int i = 1;i<primesNum && isPrime == true;i++)
        {
            isPrime = candidate % *(p+i);
        }
        if(isPrime)
        {
            *(p+primesNum) = candidate;
            primesNum++;
        }
    }
    for(int i=0;i<inputNum;i++)
    {
        if(i%5==0)
            cout<<endl;
        cout<<setw(5)<<*(p+i);/*<iomanip>*/
    }cout<<endl;
    delete []p;
    return 0;
}
