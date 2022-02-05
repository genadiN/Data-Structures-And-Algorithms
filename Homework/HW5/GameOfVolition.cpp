#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

void input(vector<long>&num , int N){
    long variable = 0;
    for(int i = 0 ; i < N ; i++){
        cin >> variable;
        num.push_back(variable);
    }
}

bool check( vector<long>&num){
    for(int i = 1 ; i < num.size() ; i++){
        if(num[i] > num[i - 1]){
            return false;
        }
    }
    return true;
}

bool isIncrease(vector<long>&num){
    for(int i = 1 ; i < num.size(); i++){
        if( num[i] < num[i - 1]){
            return false;
        }
    }
    return true;
}
long game(vector<long>&numbers){
    long counter = 0;
    if( isIncrease(numbers)){
        return 1;
    }
    while(check(numbers) == false){
        bool flag = false;
        for(int i = 1 ; i < numbers.size(); i++){
            if(numbers[i]  > numbers[i - 1]){
                numbers.erase(numbers.begin() + i);
            }
        }
        counter++;
    }
    return counter;
}

int main(){
    int N = 0;
    cin >> N;
    vector<long>que;
    input(que , N);
    cout << game(que );
return 0;
}
