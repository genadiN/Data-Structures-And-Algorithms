#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

vector<vector<int>>adj;

void init(int n){
    for(int i = 0 ; i < n ; i++){
        adj[i][i] = 1;
    }
}

void add(int u , int v){
    adj[u][v] = 1;
    adj[v][u] = 1;
}

bool isPath(int N , vector<vector<int>>& edges, int s , int d){
    int i, j , x, y;
    if(N == 1)return true;
    vector<int> adjj[N];
    for(int i = 0 ; i < edges.size() ; i++){
        x = edges[i][0] ;
        y = edges[i][1];
        adjj[x].push_back(y);
        adjj[y].push_back(x);
    }
    queue<int>q;
    vector<int> vis(N , 0);
    q.push(s);
    vis[s] = 1;
    while(!q.empty()){
        x = q.front();
        q.pop();
        for(auto X: adjj[x]){
            if(vis[X] == 0){
                q.push(X);
                if(X == d)return true;
                vis[X] = 1;
            }
        }
    }
    return false;
}
int main(){
    int N = 0 , M = 0 ;
    cin >> N >> M;
    adj = vector<vector<int>>( N + 1 , vector<int>( N + 1 , 0));
    while( M ){
        int from, to;
        cin >> from >> to;
        add(from , to);
        M--;
    }
    int questions = 0;
    cin >> questions;
    while(questions){
        int type, s, d;
        cin >> type >> s >> d;
        if(type == 1){
            cout << isPath(N , adj , s , d);
        }
        if(type == 2){
            add(s ,  d);

        }
        questions--;
    }
    return 0;
}


/*
9 8
1 2
3 4
5 6
7 8
9 5
7 2
8 2
6 9
6
1 1 8
1 6 2
2 7 1
1 4 7
2 2 3
1 4 7
*/
