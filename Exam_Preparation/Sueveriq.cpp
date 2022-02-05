#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

const int NN = 2000;
bool hasValidEdge[NN][NN];
vector<pair<pair<int,int> , int>> edges;

int N , M , from , to  , weight , queries , forbiddenNumberLen;
unordered_set<int> forbidden;

int main(){
    cin >> N >> M;
    while(M--){
        cin >> from >> to >> weight;
        edges.push_back( { {from, to} , weight} );
    }
    cin >> forbiddenNumberLen;
    while(forbiddenNumberLen--){
        cin >> N;
        forbidden.insert(N);
    }

   M = edges.size();
   for(int i = 0 ; i < M ; i++){
        if(forbidden.count(edges[i].second)){
            continue;
        }

        hasValidEdge[edges[i].first.first][edges[i].first.second] = true;

   }

    cin >> queries;
    while(queries--){
         int pathLen = 0;
        bool isPathPossible = true;

        cin >> pathLen;
        cin >> from;
        for(int i = 1 ; i < pathLen ; i++){
            cin >> to;

            if(!hasValidEdge[from][to]){
                isPathPossible = false;
            }
            from = to;
        }
        cout << isPathPossible;
    }

    return 0;
}
