#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include<unordered_map>
using namespace std;


int main() {


int N = 0 , var = 0 , sum = 0;
    cin >> N;
    vector<int>numbers;
    unordered_map<int , int>mp;
    for(int i = 0 ; i < N ; i++){
        cin >> var;
        mp[var] += 1;
    }

    for(auto x : mp){
        if(x.second % 2 != 0){
            sum += x.first * x.second;
        }
    }
    cout << sum ;
    return 0;
}
