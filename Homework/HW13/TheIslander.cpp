#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

const int N = 10000;
int rate[N];
int edges = 0 , vertices = 0;
vector<string> eulier;
unordered_map<int, vector<int>> g;

void dfs(int i , vector<bool>& visited){
    visited[i] = true;
    for(auto x : g[i]){
        if(!visited[x]){
            dfs(x , visited);
        }
    }
}

bool isConnected(int v ){
    if(v == 0){
        return true;
    }
    vector<bool>visited(N + 1, false);
    auto x = g.begin();
    for(x; x != g.end(); x++){
        if(g[(*x).first].size() != 0)break;
    }
    dfs((*x).first, visited);
    for(auto x : g){
        if(!visited[ (x).first ] && g[ x.first ].size() > 0){
            return false;
        }
    }
    return true;
}

int main(){
    int start = 0 , finish = 0;
    int queries = 0;

    cin >> queries;

    while(queries--){
        int numberRate = 0;
        cin >> vertices >> edges;
        for(int i = 0 ; i < N ; i++){
            rate[i] = 0;
        }
        while(edges){
            cin >> start >> finish;
            g[start].push_back(finish);
            g[finish].push_back(start);
            rate[start]++;
            rate[finish]++;
            edges--;
        }
        for(int i = 0 ; i < N ; i++){
            if(rate[i] % 2 != 0)numberRate++;
        }
        if(!isConnected(vertices) )eulier.push_back("none\n");
        else if(numberRate == 0) eulier.push_back("ecycle\n");
        else if(numberRate == 0 || numberRate == 2)eulier.push_back("epath\n");
        else eulier.push_back("none\n");
    }

    for(int i = 0 ; i < eulier.size() ; i++){
        cout << eulier[i];
    }
}
