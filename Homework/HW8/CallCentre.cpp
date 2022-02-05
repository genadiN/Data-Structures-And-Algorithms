#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void input(vector<vector<long>>&v , int N){
    long var = 0;
    for(int i = 0 ; i < N ; i++){
        vector< long > vec;
        for(int j = 0 ; j < 4 ; j++){
            if ( j < 2){
                cin >> var;
                vec.push_back(var);
            }else if (j == 2){
                vec.push_back(i);
            }else {
                vec.push_back(0);
            }
        }
        v.push_back(vec);
    }
}

void calls(vector<vector<long>>&v , int N , int K){
    long call = 1;
    for(int i = 0 ; i < N ; i++){
        long var = v[i][0] % K;
        cout << var << endl;
        if (var == i + 1){
            v[i][3] += 1;
        }
        else if( v[i][0] % K < v[i][0] && v[i][0] > v[var - 1][0] + v[var - 1][1]){
            v[var - 1][3]++;
        }
        else {
           for(int j = 0 ; j < (i + 1)% K ; j++ ){
               if ( (j + 1) % K == (j + 1)){
                v[i][3]++;
               }
           }
        }
    }
    for(auto x : v){
        cout << x[0] << " " << x[1] << " "
            << x[2] << " " << x[3] << endl;
    }
}

int main(){
    int N  , K;
    vector<vector<long>>v;
    cin >> N >> K;
    input(v , N);
    calls(v , N , K);
   return 0;
}
