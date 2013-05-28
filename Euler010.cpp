/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/
#include<iostream>
#include<math.h>
using namespace std;

#define SCALE 2000000

bool isPrime(int n){
    for(int i=2; i<=sqrt(n); i++)
        if(n%i == 0)
            return false;
    return true;
}

int main(){
    long sum = 0;
    for(int i=2; i<SCALE; i++)
        if(isPrime(i))
            sum +=i;
    cout << sum << endl;
    return 0;
}
