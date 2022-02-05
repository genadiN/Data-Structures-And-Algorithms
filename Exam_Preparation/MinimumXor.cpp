#include<bits/stdc++.h>
#include<iostream>

using namespace std;

const int IINT_MAX = 2 * 1000000;

int minXor(vector<int>&v ){
    int minXorr = 2000000 , xorr ;
    sort(v.begin() , v.end());
    int size = v.size();
    for(int i = 0 ;i < size - 1 ; i++){
        if(v[i] != v[i + 1])
        xorr = v[i] ^ v[i + 1];
        minXorr = min(minXorr , xorr);
    }
    return minXorr;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 0 ,var = 0;
    cin >> n;
    vector<int>v;
    v.push_back(0);
    for(int i = 0 ;i < n ; i++){
        cin >> var;
        v.push_back(var);
        cout << minXor(v) << endl;
    }
}
