#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set>

using namespace std;

void input(vector<int>&vec , int n){
    int variable = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> variable;
        vec.push_back(variable);
    }
}

int mask( vector<int>&vec , int n){
    set<int> result;
    for(auto x : vec){
       for(int j = 0 ; j <= x; j++){
           if( (j & x) == j && result.count(j) == 0){
                result.insert(j);
           }
        }
    }
    return result.size();
}

int main(){
    int n = 0;
    cin >> n;
    vector<int>v;
    input( v , n);
    cout << mask(v , n) << endl;
return 0;
}
