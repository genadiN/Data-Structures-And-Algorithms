#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include<unordered_map>
using namespace std;

int main() {
    int N = 0;
    cin >> N;
    unordered_map<string , int>mp;
    string s;
    vector<string>c;
    for(int i = 0 ; i < N ; i++){
        cin >> s;
        c.push_back(s);
        mp[s] += 1;
    }
    for(int i = 0 ; i < N ; i++){
        cout << mp[c[i]] << " ";
    }
    return 0;
}

