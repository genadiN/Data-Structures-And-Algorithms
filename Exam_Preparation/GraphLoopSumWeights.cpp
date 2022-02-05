#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

pair<int , pair<int , int> > edges[500000];

int depth[100000] , parent[100000];

void Union(int l , int r){
    if(depth[l] < depth[r]){
        parent[l] = r;
    }
    else{
        parent[r] = l;
        if(depth[l] == depth[r]){
            depth[l]++;
        }
    }
}

int Find(int v){
    if(parent[v] == v){
        return v;
    }

    return Find(parent[v]);
}

int main(){
    int from, to , weight , N , M;
    cin >> N >> M;
    for(int i = 0 ; i < M ; i++){
        cin >> from >> to >> weight;
        edges[i] = {weight , {from , to} };
    }
    for(int i = 0 ; i < N ; i++){
        parent[i] = i;
        depth[i] = 0;
    }

    int sum = 0;
    sort(edges , edges + M);
    for(int i = M - 1 ; i >= 0 ; i--){
        from = edges[i].second.first;
        to = edges[i].second.second;
        weight = edges[i].first;

        int fromP = Find(from) , toP = Find(to);
        if(fromP != toP){
            Union(fromP , toP);
        }
        else{
            sum += weight;
        }
    }
    cout << sum;
    return 0;
}
