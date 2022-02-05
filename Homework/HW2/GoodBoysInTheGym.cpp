#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void input(vector<vector<double>>&arr, int N){
    double variable;
    for ( int i = 0 ; i < N ; i++){
        vector<double> v1;
         for( int j = 0 ; j < 4 ; j++){
             if(j == 0 ){
                cin >> variable;
                v1.push_back(variable);
             }
             if(j == 1){
                cin>>variable;
                v1.push_back(variable);
             }
             if(j == 2){
                 v1.push_back(i + 1);
             }
             if( j == 3){
                 v1.push_back(0);
             }
         }
    arr.push_back(v1);
    }
}

void mySort(vector<vector<double>>&arr){
    for( auto& x : arr){
        x[3] = x[0] * x[0] / x[1];
    }
    sort(arr.begin() , arr.end() ,
        [](auto& a , auto& b){
            if(a[3] == b[3]){
                return a[0] > b[0];
            }
            return a[3] > b[3];
         });
     for(auto& x : arr){
        cout << x[2] << " ";
     }
}

int main() {
    int N ;
    cin >> N;
    vector<vector<double>>arr ;
    input(arr , N);
    mySort(arr);

    return 0;
}
