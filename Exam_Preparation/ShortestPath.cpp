#include<iostream>
#include<unordered_set>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int NN = 10000;
vector<int> g[NN];
int dist[NN];
unordered_set<int> locked;

void bfs(int start){
    dist[start]++;
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(auto x : g[current]){
            if(!dist[x] && !locked.count(x)){
                dist[x] = dist[current] + 1;
                q.push(x);
            }
        }
    }
}

int main(){
    int N = 0 , M = 0;
    int from = 0 , to = 0 , c ,sum = 0;
    vector<int> path;
    cin >> N >> M;
    while(M--){
        cin >> from >> to;
        g[from].push_back(to);
    }

    int pathSize = 0;
    cin >> pathSize;
    for(int i = 0 ; i < pathSize ; i++){
        cin >> c;
        locked.insert(c);
        path.push_back(c);
    }
    from = path[0];
    locked.erase(from);
    for(int i = 1 ;i < pathSize ; i++){
        for(int j = 0 ; j < N; j++){
            dist[j] = 0;
        }

        to = path[i];
        locked.erase(to);
        bfs(from);
        sum += dist[to] - 1;

        if(!dist[to]){
            cout << -1;
            return 0;
        }
        from = to;
    }
    cout << sum ;
    return 0;
}
