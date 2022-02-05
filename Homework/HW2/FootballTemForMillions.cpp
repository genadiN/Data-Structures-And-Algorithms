#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void input(vector<char>& arr , int N){
    char variable;
    for(int i = 0 ; i < N ; i++){
        cin >> variable;
        if( (variable >='0' && variable <= '9')
           ||( variable >= 'a' && variable <= 'z')
           ||( variable >= 'A' && variable <= 'Z')){
            arr.push_back(variable);
           }
    }
}

void mySort(vector<char>&arr){
    vector<char>digits;
    vector<char>small;
    vector<char>big;
    for(auto& x : arr){
        if(x >= '0' && x <= '9'){
            digits.push_back(x);
        }else if( x >= 'a' && x <= 'z'){
                small.push_back(x);
         }else{
            big.push_back(x);
         }
    }
    sort(digits.begin() , digits.end());
    sort(small.begin() , small.end());
    sort(big.begin() , big.end());
    for(auto &x : digits){
        cout << x;
    }

    for(auto &x : small){
        cout << x;
    }

    for(auto &x : big){
        cout << x;
    }
}

int main(){
   long N = 30;
   cin >> N;
   vector<char>word;
   input(word , N);
   mySort(word);
return 0;
}
