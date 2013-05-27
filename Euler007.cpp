/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/
#include <iostream>
#include <math.h>
using namespace std;

#define SCALE 10001

bool isPrime(long n){
    for(long i=2; i<=sqrt(n); i++)
        if(n%i == 0)
            return false;
    return true;
}

int main(){
    int counter = 1;
    long n = 2;
    while(counter != SCALE){
        n++;
        if(isPrime(n))
            counter++;
    }
    cout << n << endl;

    return 0;
}
