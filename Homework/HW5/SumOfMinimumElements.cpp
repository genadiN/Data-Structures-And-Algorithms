#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>

using namespace std;

struct Node{
    long data;
    long minimum;
};

void insertStack(stack<Node>&stack2 , long variable){
    Node other;
    other.data = variable;
    if(stack2.empty()){
        other.minimum = variable;
    }else{
        Node front = stack2.top();
        other.minimum = min(variable , front.minimum);
    }
    stack2.push(other);
    return;
}

void deleteElement( stack<Node>& stack1 , stack<Node>& stack2){
    if(stack1.size()){
        stack1.pop();
    }else{
        while(!stack2.empty()){
            Node variable = stack2.top();
            insertStack(stack1 , variable.data);
            stack2.pop();
        }
        stack1.pop();
    }
}

int minimumElement( stack<Node>&stack1 , stack<Node>&stack2){
    long minimumE = 9223372036854775807; // MAX LONG VALLUE
    if(stack1.size()){
        minimumE = min(minimumE , stack1.top().minimum);
    }
    if(stack2.size()){
        minimumE = min(minimumE , stack2.top().minimum);
    }
    return minimumE;
}

long sum(long arr[] , long d , long N){
    long sum = 0;
    stack<Node>stack1 , stack2;
    for(long i = 0 ; i < d - 1; i++){
        insertStack(stack2 , arr[i]);
    }
    for(long i = 0 ; i <= N - d; i++){
        if( i - 1 >= 0){
            deleteElement(stack1 , stack2);
        }
        insertStack(stack2 , arr[i + d - 1]);
        sum += minimumElement(stack1 , stack2);
    }
    return sum;
}
int main(){
    long N = 0 , d = 0;
    cin >> N >> d;
    long arr[N];
    for(long i = 0 ; i < N ; i++){
        cin >> arr[i];
    }
    cout << sum(arr , d , N);
return 0;
}
