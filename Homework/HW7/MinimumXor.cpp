#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 0;
    set<long>s;
    cin >> n;
    s.insert(0);
    long minXor = 2147483647;
    long var = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> variable;
        if(s.count(variable) == 0){
            s.insert(variable);
        }
    }
}
