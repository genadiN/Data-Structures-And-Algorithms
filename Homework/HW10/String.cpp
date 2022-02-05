#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

string getOrder(vector<string>& words){
    map<char , int> deg;
    map<char , vector<char> > graph;

    for(auto& word : words){
        for(char& j : word){
            deg[j] = 0;
        }
    }
    for(int i = 0 ;i < (int)words.size() - 1 ; i++){
        int commonLength = min((int)words[i].size() , (int)words[i + 1].size());
        for(int j = 0 ; j < commonLength ; j++){
            char a = words[i][j];
            char b = words[i + 1][j];
            if( a != b){
                graph[a].push_back(b);
                ++deg[b];
                break;
            }
        }
    }

    string r;
    queue<char> queue;
    auto it = deg.begin();
    while( it != deg.end()){
        if(it -> second == 0){
            queue.push(it -> first);
        }
        it++;
    }

    while(!queue.empty()){
        char x = queue.front();
        queue.pop();
        r += x;

        auto s = graph[x].begin();
        while( s != graph[x].end()){
            --deg[*s];
            if(deg[*s] == 0){
                queue.push(*s);
            }
            ++s;
        }
    }
    if( r.size() == deg.size()){
        return r;
    }
    return "";
}


int main(){
    int n;
    cin >> n;
    vector<string> words(n);
    for(auto &word : words){
        cin >> word;
    }

    string order = getOrder(words);
    for(char i : order){
        cout << i << " ";
    }

    return 0;
}
