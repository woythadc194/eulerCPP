/*
The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 552 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include <iostream>
#include <math.h>
using namespace std;

#define SCALE 100

int main(){
    int sumOfSqu, squOfSum, n;
    
    sumOfSqu = squOfSum = n = 0;
    while(n<SCALE){
        n++;
        sumOfSqu += (int)pow(n, 2);
        squOfSum += n; 
    }
    squOfSum = pow(squOfSum, 2);
    cout << (squOfSum-sumOfSqu) << endl;
    return 0;
}
