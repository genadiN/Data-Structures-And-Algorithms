#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_set>
using namespace std;

vector<int>graph[2000];
vector<int> rate;
int vertex, edges, K , T;
unordered_set<int>s;
vector<int>path;

bool isPath(){
    bool found = false;
    for(int i = 0 ; i < path.size() - 1; i++ ){
        found = false;
        int j = i +1;
        for(auto x : graph[path[i] ]){
            if(path[j] == x.first)
                if(s.find(x.second) == s.end()){
                    found = true;
                    break;
                }
        }
        if(!found){
            return false;
        }
    }
    return true;
}

int main() {
    cin >> vertex >> edges;
    while(edges--){
        int from , to , w;
        cin >> from >> to >> w;
        graph[from].push_back({to , w});
    }
    cin > K;
    while(K--){
        int n = 0;
        cin >> n;
        s.insert(n);
    }
    cin >> T;
    for(int i = 0 ; i < T ; i++){
        int nodes;path..clear();
        cin >> nodes;
        while(nodes--){
            int g;
            cin >> g;
            path.push_back(g);
        }
        if(isPath()){
            cout << 1;
        }else{
            cout << 0;
        }
    }
    return 0;
}

