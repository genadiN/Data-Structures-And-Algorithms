#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>

using namespace std;

int longestCommonSubstring(string first, string second, int fLength, int sLength)
{
    int matrix[2][sLength + 1] , counter = 0;
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0  ; j < sLength + 1 ; j++){
            matrix[i][j] = 0;
        }
    }
    for (int i = 1; i <= fLength ; i++) {
        for (int j = 1; j <= sLength ; j++) {
            if (first[i - 1] == second[j - 1]) {
                matrix[i % 2][j] = matrix[ ( i - 1 ) % 2][ j - 1] + 1;
                if (matrix[i % 2][j] > counter)
                    counter = matrix[i % 2][j];
            }
            else
                matrix[i % 2][j] = 0;
        }
    }
    return cogenadiniunter;
}

int main(){
    string first , second;
    cin >> first >> second;
    int fLength = first.length(), sLength = second.length();
    cout << longestCommonSubstring( first , second , fLength , sLength ) ;
    return 0;
}

