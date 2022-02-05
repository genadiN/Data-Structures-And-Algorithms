#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

vector<vector<long>>adj;


void add(long u , long v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isTherePath(long source , long destination){
    if(source == destination){
        return true;
    }
    long N = (long)adj.size();

    vector<bool> visited(N , false);
    queue<long>q;

    visited[source] = true;
    q.push(source);
    while(!q.empty()){
        source = q.front();
        q.pop();
        for(auto neighbour: adj[source]){
            if( neighbour == destination){
                return true;
            }
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long N = 0 , M = 0;
    cin >> N >> M;
    adj = vector<vector<long>>(N + 1);
    while( M ){
        long from, to;
        cin >> from >> to;
        add(from , to);
        M--;
    }
    long queries = 0;
    cin >> queries;
    while( queries ){
        long type, s, d;
        cin >> type >> s >> d;
        if(type == 1){
            cout << isTherePath(s , d);
        }
        if(type == 2){
            add(s ,  d);
        }
        queries--;
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
