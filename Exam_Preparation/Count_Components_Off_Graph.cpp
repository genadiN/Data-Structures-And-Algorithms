#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 100000;

bool visited[N];

void dfs(int v , vector<int>graph[]){
    visited[v] = 1;
    for( auto x : graph[v] ){
        if(!visited[x]){
            dfs(x, graph);
        }
    }
}

int main(){
    int queries = 0;
    cin >> queries;
    while(queries--){
        int X = 0 , Y = 0;
        cin >> X >> Y;
         vector<int>g[X + 1];
        while(Y--){
            int from = 0 , to = 0;
            cin >> from >> to;
            g[from].push_back(to);
            g[to].push_back(from);
        }
        int counter = 0;
        for(int i = 0 ; i < N ; i++){
            visited[i] = 0;
        }
        for(int i = 0 ; i < X ; i++){
            if(!visited[i]){
                dfs(i , g);
                counter++;
            }
        }

        cout << counter << " ";
    }

    return 0;
}
