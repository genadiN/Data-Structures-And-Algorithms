#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

void input(vector<long>&v , long N){
    long var = 0;
    for(long i = 0 ; i < N ; i++){
        cin >> var;
        v.push_back(var);
    }
}

long triplesAnimals(vector<long>&v , long N , long K){
    map<long  , long >kg;
    long index = 0 , counter = 0;
    for(auto x : v){
        kg[index++] = x;
    }
    for(long x = 0 ; x < N - 2 ; x++){
        for(long y = x + 1 ; y < N - 1 ; y++){
            for(long z = y + 1 ; z < N ; z++){
                long long first = kg[y] / K;
                long long second = kg[z] / K;
                if(first == kg[x] && kg[y] == second ){
                    counter++;
                }
            }
        }
    }
    return counter;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long N = 0 , K = 0;
    cin >> N >> K;
    vector<long>v;
    input(v , N);
    printf("%d" , triplesAnimals(v , N , K));
    return 0;
}
