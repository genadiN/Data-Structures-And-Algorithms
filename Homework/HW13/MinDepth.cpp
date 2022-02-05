#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<climits>

using namespace std;

vector<int> g[int(1e7)];
vector<int> rate;
vector<int>result;
queue<int>nextForVisit;
stack<int>last;
int vertices;

void minimalDepth(){
    for(int i = 0 ; i < rate.size() ; i++){
        if(rate[i] == 1){
            nextForVisit.push(i);
        }
    }
    nextForVisit.push(-1);
    while(!nextForVisit.empty()){
        int v = nextForVisit.front();
        nextForVisit.pop();
        last.push(v);
        if(v == -1){
            if(!nextForVisit.empty() && nextForVisit.front() != -1){
                nextForVisit.push(-1);
            }
            continue;
        }
        rate[v] = 0;
        for(auto x : g[v]){
            rate[x]--;
            if(rate[x] == 1){
                nextForVisit.push(x);
            }
        }
    }
    while(!last.empty() && last.top() == -1){
        last.pop();
    }
    while(!last.empty() && last.top() != -1){
        result.push_back(last.top());
        last.pop();
    }
    sort(result.begin() , result.end());
    for(int i = 0 ; i < result.size() ; i++){
        cout << result[i] << " ";
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> vertices;
    rate.resize(vertices , 0);
    while(vertices - 1){
         int from , to;
         cin >> from >> to;
         g[from].push_back(to);
         g[to].push_back(from);
         rate[from]++;
         rate[to]++;
        vertices--;
    }
    minimalDepth();
}
