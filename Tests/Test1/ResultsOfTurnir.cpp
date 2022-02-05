#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void inputVector(vector<vector<double>>&arr , int N){
   double input = 0;
    for(int i = 0 ; i < N ; i++ ){
        vector<double>inputVector;
        double constant = 0;
        for(int j = 0 ; j < 3 ; j++){
            if( j < 2){
                cin >> input;
            }
            if( j == 0){
                inputVector.push_back(input);
                constant = input;
            }
            if( j == 1){
                constant *= constant / input;
                inputVector.push_back(constant);
            }
            if( j == 2){
                inputVector.push_back(i + 1);
            }
        }
        arr.push_back(inputVector);
    }
}

void mySort(vector<vector<double>>&arr){
    sort(arr.begin() , arr.end() ,
        [](auto& a , auto& b){
            if(a[1] == b[1]){
                if(a[0] == b[0]){
                    return a[2] > b[2];
                }
                return a[0] > b[0];
            }
            return a[1] > b[1];
         });
    for(auto &x : arr){
        cout << x[2] << " ";
    }
}

int main(){
    int N = 0;
    cin >> N;
    vector<vector<double>>results;
    inputVector(results , N);
    for(auto &x : results){
         cout << x[0] << " " << x[1] << " " << x[2] << endl;
    }
    mySort(results);
return 0;
}
