/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?
*/
#include <iostream>
using namespace std;

#define size 20
#define SCALE size+1

void printMatrix(long matrix[][SCALE]){
    for(long y=0; y<SCALE; y++){
        for(long x=0; x<SCALE; x++)
            cout << matrix[y][x] << " ";
        cout << "\n";
    }
}

int main(){
    //Matrix definiton
    long matrix [SCALE] [SCALE];
    for(long y=0; y<SCALE; y++)
        for(long x=0; x<SCALE; x++)
            matrix[y][x] = 0;
    
    //Applying Initial values
    for(long y=1; y<SCALE; y++)
        matrix[y][0]=1;
    for(long x=1; x<SCALE; x++)
        matrix[0][x]=1;
 
    //Applying computed values       
    for(long y=1; y<SCALE; y++)
        for(long x=1; x<SCALE; x++)
            matrix[y][x]=matrix[y-1][x] + matrix[y][x-1];
            
    //Prlong matrix
    printMatrix(matrix);
    return 0;
}
