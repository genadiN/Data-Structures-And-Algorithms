#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int main(){
    int n = 0 , m = 0;
    cin >> n >> m;
    int var = 0;
    vector<int>a;
    vector<int>b;
    for(int i = 0; i < n ; i++){
        cin >> var;
        a.push_back(var);
    }

    sort(a.begin() , a.end());
    for(int i = 0 ; i < m ; i++){
        cin >> var;
        auto lower = lower_bound(a.begin() , a.end() , var);
        int numberOffSmallElements = lower - a.begin();
        cout << numberOffSmallElements << " ";
    }
}

