#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void input(vector<vector<int>>&arr , int N){
    int var;
    for(int i = 0 ; i < N ; i++){
        vector<int>dates;
        for(int j = 0 ; j < 12 ; j++){
            if( j == 1 || j == 3){
                cin.ignore(1 , '.');
            }else if(j == 5){
                cin.ignore(1 , ' ');
            }else if(j == 7 || j == 9){
                cin.ignore(1 , ':');
            }else if( j % 2 == 0 ){
                cin >> var;
                dates.push_back(var);
            }else if(j == 11){
                dates.push_back(i + 1);
            }

        }
        arr.push_back(dates);
    }
}

void mySort( vector<vector<int>>&arr){
    sort(arr.begin() , arr.end() ,
        [](auto& a , auto& b){
            if(a[5] == b[5]){
                if(a[4] == b[4]){
                    if(a[3] == b[3]){
                        if(a[0] == b[0]){
                            if(a[1] == b[1]){
                                if(a[2] == b[2]){
                                    return a[6] < b[6];
                                }
                                return a[2] < b[2];
                            }
                            return a[1] < b[1];
                         }
                        return a[0] < b[0];
                    }
                    return a[3] < b[3];
                }
                return a[4] < b[4];
            }
            return a[5] < b[5];
        });
        for(auto&x : arr){
            cout << x[6] << endl;
        }
}
int main(){
    int N = 0;
    cin >> N;
    if( N >= 1 && N <= 200000){
      vector<vector<int>>dates;
    input(dates , N);
    mySort(dates);
    }


    return 0;
}
