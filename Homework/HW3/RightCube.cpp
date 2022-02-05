#include<iostream>

using namespace std;

unsigned long long recursiveCube(unsigned long long number , unsigned long long counter , unsigned long long i , unsigned long long j){
    if(number < 8){
        return counter + number;
    }
    else{
        i++;
        j = i + 1;
        if(j * j * j > number ){
            return recursiveCube( number - i*i*i , ++counter , 0 , 0);
        }else if (i * i * i == number ){
            return( number - i * i * i, ++counter, 0 , 0);
        }else{
            return recursiveCube( number ,counter , i  , j);
        }
    }
}

int main(){
    unsigned long long n = 0 , counter = 0 , i = 0 , j = 0;
    cin >> n;
    cout << recursiveCube( n, counter , i , j ) << endl;

return 0;
}
