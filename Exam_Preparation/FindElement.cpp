#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main(){
    int N = 0;
    cin >> N ;
    unordered_map<int, int>fromBegining;
    unordered_map<int, int>fromEnding;
    vector<int> v;
    int var;
    for(int i = 0 ;i < N ; i++){
        cin >> var;
        v.push_back(var);
    }
    for(int i = 0 ; i< N ; i++){
        if(fromBegining[ v[i] ] == 0){
            fromBegining[v[i]] = i + 1;
        }
    }
    for(int i = N - 1 ; i >= 0 ; i--){
        if(fromEnding[ v[i] ] == 0){
            fromEnding[ v[i] ] = i + 1;
        }
    }
    int queries = 0;
    cin >> queries;
    for(int i = 0 ; i < queries ; i++){
        cin >> var;

        auto lower = lower_bound(v.begin() , v.end() , var);
        int start = lower - v.begin();

        if(v[start] != var) {
            cout << start <<"\n";
        }else{
            auto upper = upper_bound(v.begin() , v.end(), var);
            int end = upper - v.begin() - 1;
            cout << << " " << end << "\n";
        } start
    }

    return 0;
}
