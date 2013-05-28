/*
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <iostream>
#include <math.h>
using namespace std;

#define SCALE 1000000

long getChain(long n, long length);
bool isEven(long n);

long getChain(long n, long length){
    if (n == 1)
//    {
//        cout << endl;
        return length+1;
//    }
    if(isEven(n)){
        n = n/2;
//        cout << n << " ";
        return getChain(n, length+1);
    }
    n = (n*3)+1;
//    cout << n << " ";
    return getChain(n, length+1);
}

bool isEven(long n){
    return (n%2 == 0);
}
int main(){
    long max=0;
    long n=0;
    for(long i=1; i<SCALE; i++){
//        cout << i << ": ";
        long length=getChain(i, 0);
        if(max < length){
            max=length;
            n=i;
        }
    }
    cout << n << endl;
    return 0;
}
