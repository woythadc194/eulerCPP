/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

//Prototypes
#include <iostream>
#include <sstream>
using namespace std;


bool isPalindrome(int n){
    ostringstream ss;    //create a stringstream
    ss << n;            //add number to the stream
    string s = ss.str();//return a string of int

    string t = "";
    for(int i=s.length()-1; i>=0; i--)
        t += s.at(i);
    return s==t;
}

int main(){
    //Variables
    int pal, prod;

    //Statements
    pal=0;
    for(int a=100; a<1000; a++)
        for(int b=100; b<1000; b++){
            prod = (int)a*b;
            if(isPalindrome(prod))
                if(pal<prod)
                    pal=prod;
        }
    cout << pal << endl;
    return 0;
}
