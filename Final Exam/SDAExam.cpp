#include<bits/stdc++.h>
using namespace std;

const int N = 1003;
vector<int>adj[N];
int dist[N];

void BFS(int v){
    for(int i = 1 ;i < N ; i++){
        dist[i] = INT_MAX;
    }
    queue<int>q;
    dist[v] = 0;
    q.push( v);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(auto x : adj[current]){
            if(dist[x] > dist[current] + 1){
                dist[x] = dist[current] + 1;
                q.push(x);
            }
        }
    }
}

int main() {
    int Q = 0 , n = 0, m;
    int from , to;
    cin >> Q;
    while(Q--){
        cin >> n >> m;
        while(m--){
            cin >> from >> to;
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
        int index = 0;
        cin >> index;
        BFS(index);
        for(int i = 1 ;i <= n ; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        for(int i = 1 ;i <= n;i ++){
            if(i != index){
                if(dist[i] > 0){
                    cout << dist[i] * 6 << " ";
                }
                else{
                    cout << dist[i] << " ";
                }
            }

        }
        cout << endl;
        for(int i = 0 ;i < n ; i++){
            adj[i].clear();
        }
    }

    return 0;
}
