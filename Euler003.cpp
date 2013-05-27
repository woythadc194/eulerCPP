/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

//prototypes
#include <iostream>
#include <math.h>
using namespace std;

//declared functions
bool isPrime(int d);

//methods
int main(){
    //vars
    long n;
    int divisor;
    bool found;
    
    //statements
    found = false;
    n = 600851475143;
    divisor = (int)sqrt(n);
    while(!found){
        if((n%divisor==0) && isPrime(divisor))
            found=true;
        if(!found)
            divisor--;
    }
    cout << divisor << endl;
    return 0;
}

bool isPrime(int d){
    for(int i=2; i<sqrt(d); i++)
        if(d%i==0)
            return false;
    return true;
}
