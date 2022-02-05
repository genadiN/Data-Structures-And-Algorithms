#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

const int MAX_CHAR = 256;
void answer(string word){
    const int length = word.length();
    int letterCheck[MAX_CHAR];
    int result[MAX_CHAR];

    for(int i = 0 ; i < MAX_CHAR ; i++){
        letterCheck[i] = 0;
        result[i] = length;
    }

    for(int i = 0 ; i < length ; i++){
        char letter = word[i];
        ++letterCheck[letter];

        if(letterCheck[letter] == 1 && letter != ' '){
            result[letter] = i;
        }else if(letterCheck[letter] == 2){
            result[letter] = length;
        }
    }
    sort(result , result + MAX_CHAR);
    for(int i = 0 ; i < MAX_CHAR && result[i] != length ; i++){
        cout << result[i] << " ";
    }
}

int main(){
    string word;
    cin >> word;
    answer(word);
return 0;
}
