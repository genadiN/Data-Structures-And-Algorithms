#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<set>
#include<queue>
#include <algorithm>
using namespace std;
const int N = 2000005;
vector<int>g[N];
int from , to;
int counter;

void Bfs(int v){
    queue<int>q;
    q.push(v);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(auto x : g[current]){
            counter += x;
            q.push(x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m , t;
    cin >> m >> t;
    set<int>s;
    while(m--){
        cin >> from >> to;
        g[from].push_back(to);
    }
    for(int i = 0 ; i < t ; i++){
        int edge;
        cin >> edge;
        Bfs(edge);
        printf("%d\n" , counter);
        counter = 0;
    }
    return 0;
}

