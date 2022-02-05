#include<bits/stdc++.h>

using namespace std;

const int N = 100001;
int dist[N];

vector<pair<int , int >> adj[N];

void shortestPaths(int v){
    for(int i = 0 ; i < N ; i++){
        dist[i] = INT_MAX;
    }
    dist[v] = 0;

    priority_queue< pair<int , int>, vector< pair<int, int>>, greater<pair<int, int>> >que;
    que.push({0 , v});

    while(!que.empty()){
        int current = que.top().second;
        int dataCurrent = que.top().first;
        que.pop();

        if(dataCurrent > dist[current]){
            continue;
        }

        for(pair<int, int> neighbour : adj[current]){
            int child = neighbour.first;
            int dataChild = neighbour.second;

            if(dist[child] > dataCurrent + dataChild){
                dist[child] = dataCurrent + dataChild;
                que.push( { dataCurrent + dataChild , child } );
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int edges = 0 , vertices = 0 , dataCurrent = 0;
    int start = 0 , finish = 0;
    cin >> vertices >> edges;
    while(edges ){
        cin >> start >> finish >> dataCurrent;
        adj[start].push_back({finish , dataCurrent});
        adj[finish].push_back({start , dataCurrent});
        edges--;
    }
    int v = 0;
    cin >> v;
    shortestPaths(v);
    for(int i = 1; i <= vertices ; i++){
        if(i != v){
            if(dist[i] == INT_MAX){
                cout << "-1 ";
            }else{
                cout << dist[i] << " ";
            }

        }
    }
    return 0;

}
