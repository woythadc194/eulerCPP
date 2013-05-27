/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <iostream>
using namespace std;

#define SCALE 20

int main(){
    int multi, n;
    bool found;
    
    multi=0;
    n=SCALE;
    found=false;
    
    while(!found){
        n++;
        while(multi < SCALE){ 
            multi++;
            if(n%multi != 0)
                break;
            if(multi == SCALE)
                found=true;
        }
        multi=0;
    }
    cout << n << endl;    
    return 0;
}
