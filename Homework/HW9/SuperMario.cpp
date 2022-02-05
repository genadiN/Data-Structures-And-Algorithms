#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

void input(vector<long>&v , int N){
    long var = 0;
    for(int i = 0 ; i < N ; i++){\
        cin >> var;
        v.push_back(var);
    }
}

long destroyedDoors(vector<long>&k , vector<long>&d , int N ){
    long counter = 0 , destroyed = 0;
    unordered_map<long , long >mp;
   for(auto x : k){
    mp[x] += 1;
    if(mp[d[counter]] == 0){
        destroyed++;
    }else{
        mp[d[counter]]--;
    }
    counter++;
   }

    return destroyed;
}

int main(){
    int N = 0;
    cin >> N;
    vector<long>keys;
    vector<long>doors;
    input(keys , N);
    input(doors , N);
    cout << destroyedDoors(keys , doors , N) ;
    return 0;
}
