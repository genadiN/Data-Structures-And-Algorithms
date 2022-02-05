#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

void dfs(vector<vector<int>> &graph , int node , vector<bool> &visited , vector<int>& traverse){
    if(!visited[node]){
        visited[node] = true;
        for( int child : graph[node]){
            dfs(graph , child , visited , traverse);
        }
        traverse.push_back(node);
    }
}

void findGraphComponents(vector<vector<int>>& graph , vector<int>& nodesByComponents){
    int counter = 0;
    vector<bool> visited(graph.size());
    vector<int> traverse;
    for(int node = 0 ; node < graph.size() ; node++){
        dfs(graph , node, visited, traverse);
        counter++;
        for(int traverseNode : traverse){
            nodesByComponents[traverseNode] = counter;
        }
        traverse.clear();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int vertices = 0 , edges = 0;
    cin >> vertices >> edges;

    vector<vector<int>> graph( vertices + 1 , vector<int>());
    while(edges){
        int start = 0 , finish = 0;
        cin >> start >> finish;
        graph[start].push_back(finish);
        graph[finish].push_back(start);
        edges--;
    }

    int queries = 0;
    cin >> queries;

    vector<int> nodeByComponent(graph.size());
    findGraphComponents(graph , nodeByComponent);

    while(queries){
        int source = 0 , destination = 0;
        cin >> source >> destination;
        if(nodeByComponent[source] == nodeByComponent[destination]){
            printf("1 ");
        }else{
            cout << printf("0 ");
        }
        queries--;
    }
    return 0;
}
