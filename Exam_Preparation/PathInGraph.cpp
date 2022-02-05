#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1000005;

vector<int> g[N];
int visited[N];
int component = 1;

void dfs(int v){
    visited[v] = component;
    for(auto x : g[v]){
        if(!visited[x]){
            dfs(x);
        }
    }
}

int main(){
    int N = 0 , M = 0;
    cin >> N >> M;
    int from = 0 , to = 0;
    while(M--){
        cin >> from >> to;
        g[from].push_back(to);
        g[to].push_back(from);
    }

    for(int i = 1 ;i <= N ; i++){
        if(!visited[i]){
            dfs(i);
            component++;
        }else{
            continue;
        }
    }

    int querie;
    cin >> querie;
    while(querie--){
        cin >> from >> to;
        if(visited[from] == visited[to]){
            printf("%d " , 1);
        }else{
            printf("%d ", 0);
        }
    }
}
