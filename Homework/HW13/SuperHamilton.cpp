#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
bool visited[N];
int parent[N];
int adjMat[N][N];
vector<int>adjacencyList[N];
int  numberOfVertices, numberOfEdges;
int destination;
int hamiltonPaths = 0, hamiltonCycles = 0;

void dfs(int v, int treeSize ){
        if (treeSize == destination ) {
                hamiltonPaths++;
                cout << "Hamilton path\n";
                if (adjMat[v][0]) {
                        hamiltonCycles++;
                        cout << "Hamilton cycle\n";
                }
                while (v != -1){
                        cout << v << " ";
                        v = parent[v];
                }
                cout << "\n\n";
                return;
        }
    visited[v] = 1;
        for (auto neighbour : adjacencyList[v]){
                if (!visited[neighbour]) {
                        parent[neighbour] = v;
                        dfs(neighbour, treeSize + 1);
                }
        }
                visited[v] = 0;
}

int main()
{
    int from = 0, to = 0;
    int rows = 0 , cows = 0 , start ;
    cin >> rows >> cows;
    char a ;
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cows ; j++){
            cin >> a;
            if( a == '-' ){
                if(i != j){
                adjacencyList[i].push_back(j);
                adjacencyList[j].push_back(i);
                adjMat[i][j] = 1;
                adjMat[j][i] = 1;
                }
            }
            if( a == 's'){
                    start = j;
            }
            if(a == 'e'){
                destination = j;
            }
        }
    }
    cout << destination << start << endl;
    numberOfVertices = cows ;

    parent[start] = -1;
    dfs(start,1);

    cout << hamiltonPaths << " " << hamiltonCycles;

return 0;
}

/*
5 8
0 1
0 2
0 4
1 2
1 4
2 3
2 4
3 4
*/

