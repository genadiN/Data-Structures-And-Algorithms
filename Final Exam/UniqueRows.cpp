#include<bits/stdc++.h>
#include<map>

using namespace std;

int main() {
   int N , M , var;
    cin >> N >> M;
    map< vector<int> , int > mp;
    for(int i = 0 ;i < N ; i++){
        vector<int>v;
        for(int j = 0 ; j < M ; j++){
            cin >> var;
            v.push_back(var);
        }
        mp[v] += 1;
    }
    int uniqueRows = 0;
    for(auto x : mp){
        if(x.second == 1){
            uniqueRows++;
        }
    }
    cout << uniqueRows ;
    return 0;
}
