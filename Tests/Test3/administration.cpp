#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;


int main() {
    int n = 0 , var = 0, counter = 0;
    cin >> n;
    map < int , int> mp;
    vector<int>vec;
    for(int i = 0 ; i < n ; i++){
        cin >> var;
        vec.push_back(var);
        mp[var] +=1;
    }
    for(int i = 0 ; i < n ; i++){
        if(mp[ vec[i] ] == 1){
            cout << vec[i] << " ";
            mp[ vec[i] ] == 0;
            counter++;
        }
    }
    if(counter < n){
      for(int i = 0 ; i < n - counter ; i++){
            if(mp[ vec[i] ] > 0){
                cout << vec[i] << " ";
                mp[vec[i]] = 0;
            }
      }
    }

    return 0;
}


