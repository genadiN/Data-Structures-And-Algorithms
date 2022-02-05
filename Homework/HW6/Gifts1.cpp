#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int start[1000001];
int endd[1000001];

vector<int>order;
vector<int>numbers[1000001];
int visited[1000001];

void numberOfNodes(int a , int& b){
    visited[a] = 1;
    b++;
    start[a] = b;
    order.push_back(a);
    for(vector<int>:: iterator it = numbers[a].begin();
        it!= numbers[a].end(); it++){
            if(!visited[*it]){
                numberOfNodes(*it , b);
            }
    }
    endd[a] = b;
}

void print(int N){
    vector<int>ans;
    int counter = 0;
    for(int i = 0 ; i < N ; i++){
        if(start[i] != endd[i]){
            counter = 0;
            for(int j = start[i] + 1; j <= endd[i] ; j++){
                counter++;
            }
            cout<< counter << " ";
        }else if(start[i] == endd[i]){
            cout << "0 " ;
        }

    }
}

int main(){
    int N = 0 , x = 0 , y = 0 , c = 0;
    cin >> N;
    for(int i = 1 ; i < N ; i++){
        cin >> x >> y;
        numbers[x].push_back(y);
    }
    numberOfNodes(0 , c);
    print(N);
return 0;
}

