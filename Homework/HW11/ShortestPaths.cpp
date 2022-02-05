#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;

const long long N = 100006;

const long long MAX = 9223372036854775807;

pair<long long , long> dist[N];

vector< pair<long long , long long>> adj[N];

void shortestPaths(long long v){
    for(long long i = 0 ; i < N ; i++){
        dist[i].first = MAX;
        dist[i].second = 0;
    }
    dist[v].first = 0;
    dist[v].second = 1;

    priority_queue< pair<long long, long long> , vector< pair<long long, long long>> ,
                greater<pair<long long , long long>> >que;
    que.push({0 , v});

    while( !que.empty()){
        long long current = que.top().second;
        long long dataCurrent = que.top().first;
        que.pop();

        for(pair<long long , long long> x : adj[current]){
            long long child = x.first;
            long long dataChild = x.second;
            if(dist[child] .first > dataCurrent + dataChild){
                dist[child].first = dataChild + dataCurrent;
                dist[child].second = dist[current].second % (1000000007);
                que.push({dataChild + dataCurrent , child});
            }
            else if(dist[child].first == dataChild + dataCurrent){
                dist[child].second +=dist[current].second % (1000000007 );
            }

        }
    }
}

int main(){
    long long edges = 0 , vertices = 0 , dataCurrent = 0;
    long long start = 0 , finish = 0;
    cin >> vertices >> edges ;
    while( edges > 0){
        cin >> start >> finish >> dataCurrent;
        adj[start].push_back({finish , dataCurrent});
        edges--;
    }

    shortestPaths(1);
    if(dist[vertices].second){
         cout << dist[vertices].first << " " << dist[vertices].second  % (1000000007) ;
    }
    else{
        cout << -1 << " " << 0;
    }

    return 0;
}
