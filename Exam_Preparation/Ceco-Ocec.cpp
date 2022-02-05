#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<unordered_map>

using namespace std;

int main(){
    int N = 0;
    string a;
    string b;
    vector<int>aa ;
    vector<int>bb;
    unordered_map<int , int>mp;
    cin >> N;
    int sum = 0 , counter = 0;
    for(int i = 0 ; i < N ; i++){
        cin >> a >> b;
        sum = 0;
        for(int j = 0 ; j < b.length() ; j++){
            bb.push_back( int(b[j] - 'A') + 1 );
        }
        for(int j = 0 ; j < a.length() ; j++){
            aa.push_back( int(a[j] - 'A') + 1 );
        }

        sort(aa.begin() , aa.end() );
        sort(bb.begin() , bb.end() );
         for(auto x : aa){
            cout << x << " ";
        }
        cout << endl;
        for(auto x : bb){
            cout << x << " ";
        }
        cout << endl;

        for(int k = 0 ; k < aa.size() ; k++){
            auto upper = upper_bound(bb.begin() , bb.end() , aa[k] ) ;
            cout << upper - bb.begin();
            //bb.erase(bb.begin() +( upper - bb.begin()));
        }
        cout << sum << endl;
    }
    int aaa = int('A');
    cout << aaa;
    return 0;
}
