#include<cmath>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int M , N , K , time , kg;
const int maxN = 1000001;
int times[maxN];
vector< pair<int , pair<int , int> > > Graph[maxN];

int Dijkstra(int currentKg){
    for(int i = 0 ; i < maxN ; i++){
        times[i]= INT_MAX;
    }

    pair<int, pair<int , int> >x;
    times[1] = 0;
    priority_queue< pair< int, pair<int, int>> , vector< pair<int, pair<int , int>>> , greater<pair<int, pair<int, int>>>> que;
    que.push({0, {1 , 0} });

    while(!que.empty()){
        int current = que.top().second.first;
        que.pop();

        for(auto x : Graph[current]){
            int child = x.first;
            int cost = x.second.first;
            int kg = x.second.second;

            if(kg <= currentKg && times[child] > times[current] + cost){
                times[x.first] = times[current] + cost;
                que.push({ times[x.first] , {x.first , kg } });
            }
        }
    }
    return times[M];
}


int main(){
    cin >> N >> M >> K;

    int result = INT_MAX;
    int MIN = INT_MAX;
    int MAX = 0;

    int mid , m;
    int start , finish;

    while(N){
        cin >> start >> finish >> kg >> time;
        if(finish != 1)Graph[start].push_back({finish, {time , kg} });
        MIN = min(MIN , kg);
        MAX = max(MAX , kg);
        N--;
    }

    while(MIN <= MAX){
        mid = MIN + ( MAX - MIN ) /2;
        int m = Dijkstra(mid);

        if( m > K){
            MIN = mid + 1;
        }else{
            MAX = mid - 1;
            result = min(result , mid);
        }
    }

    if(result == INT_MAX) {
        cout << "-1";
    }else{
        cout << result;
    }
    return 0;
}
