#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

int main() {
    string word = "";
    cin >> word;
    int N = 0 , length = word.length() , counter = 0 ;
    if (length >= 1 && length <= 100){
        cin >> N ;
        char letter;
        cin >> letter;
        if(N >= 1 && N <= 1000000000){
                for( int i = 0 ; i < length ; i++){
                    if(word[i] == letter){
                        counter++;
                    }
                }
                counter = counter * N / length ;
                if( N % length != 0){
                    int finish = N / length;
                    finish = finish * length;
                    finish = N - finish;
                    for ( int i = 0 ; i < finish ; i++){
                        if (word[i] == letter){
                            counter++;
                        }
                    }
                }
        }
    }
    cout << counter;

    return 0;
}
