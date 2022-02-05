#include<iostream>

using namespace std;

int graph[1000][1000];

int main(){
    int N = 0 , M = 0;
    int from = 0 , to = 0 , weight = 0;
    int pathLen = 0;
    cin >> N >> M;
    for(int i = 0 ; i < M ; i++){
        cin >> from >> to >> weight;ä
        graph[from][to] = weight;
        graph[to][from] = weight;
    }
    cin >> pathLen >> from;
    int sumPath = 0;
    for(int i = 1 ; i < pathLen ; i++){
        cin >> to;
        if(graph[from][to]){
            sumPath += graph[from][to];
        }else{
            cout << "-1";
            return 0;
        }
        from = to;
    }
    cout << sumPath;
}
