#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

void input(queue<long>&numbers , int N){
    long variable = 0;
    for(int i = 0 ; i < N ; i++){
        cin >> variable;
        numbers.push(variable);
    }
}

void battleBridge(queue<long>&numbers){
    stack<long>pos;
    while(!numbers.empty()){
        if(numbers.front() < 0){
            cout << numbers.front() << " ";
            numbers.pop();
        }else if(numbers.front() > 0){
            pos.push(numbers.front());
            numbers.pop();
        }
        if(!pos.empty() && numbers.front() < 0){
            while(!pos.empty() && numbers.front() < 0){
                if(abs(pos.top() ) > abs(numbers.front())){
                    numbers.pop();
                }else if(abs(pos.top()) == abs(numbers.front())){
                    numbers.pop();
                    pos.pop();
                }else if(abs(pos.top()) < abs( numbers.front() )){
                    pos.pop();
                }
            }
        }
    }
    stack<long>answer;
    while(!pos.empty()){
            answer.push(pos.top());
            pos.pop();
    }
    while(!answer.empty()){
        cout << answer.top() << " ";
        answer.pop();
    }
}

int main(){
    int N = 0;
    cin >> N;
    queue<long>numbers ;
    input(numbers , N);
    battleBridge(numbers);
return 0;
}
