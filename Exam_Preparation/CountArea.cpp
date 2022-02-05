#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 100005;
int numberOfTests;
int X , Y;
int componentsCounter = 1;
bool visited[N];

void dfs(int v , vector<int>graph[]){
    visited[v] = 1;
    for( auto x : graph[v]){
        if(!visited[x]){
            dfs(x , graph);
        }
    }
}

int main(){
    cin >> numberOfTests;
    for(int i = 0 ; i < numberOfTests ; i++){
        int from , to;
        componentsCounter = 0;
        cin >> X >> Y;
        vector<int>graph[X + 1];
        while(Y--){
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        for(int i = 0 ;i < X ; i++){
            visited[i] = 0;
        }
        for(int i = 0 ;i < X ; i++){
            if(!visited[i]){
                dfs(i , graph);
                componentsCounter++;
            }
        }
        cout << componentsCounter << " ";
    }
    return 0;
}
