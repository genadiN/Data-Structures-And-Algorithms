#include<bits/stdc++.h>
using namespace std;

int main() {
    long N = 0 , M = 0 , var = 0;
    cin >> N >> M;
    set<vector<long>>s;
    for(int i = 0 ;i < N ; i++){
        vector<long>v;
        for(long i = 0 ;i < M ; i++){
            cin >> var;
            v.push_back(var);
        }
        if(s.count(v) == 0){

            s.insert(v)
        }else{
            s.erase(v);
        }
    }
    cout << s.size();
    return 0;
}
