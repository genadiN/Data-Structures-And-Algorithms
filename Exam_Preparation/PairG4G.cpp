#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int T = 0, var, N = 0, maxSum = 0;
    vector<int>negative;
    vector<int>positive;
    cin >> T;
    for(int i = 0 ;i < T ; i++){
        maxSum = 0;
        negative.clear();
        positive.clear();
        cin >> N;
        for(int i = 0 ;i < N ; i++){
            cin >> var;
            if(var <= 0){
                negative.push_back(abs ( var ) );
            }
            if(var > 0){
                positive.push_back(var);
            }
        }
        if(negative.size() > 0){
            sort(negative.begin() , negative.end());
            for(int i = negative.size() - 1 ; i >= 0 ; i -= 2 ){
                if( i > 0){
                    if(negative[i - 1] == 1 ){
                        maxSum += negative[i];
                    }else{
                        maxSum += negative[i] * negative[i - 1];
                    }
                }
                if(negative.size() % 2 != 0 && i == 0){
                    maxSum -= negative[i];
                }
            }

        }
        if(positive.size() > 0){
            sort(positive.begin() , positive.end());
            for(int i = positive.size() - 1 ; i >= 0 ; i -= 2){
                if( i > 0){
                    if(positive[i - 1] == 1 ){
                        maxSum += positive[i] + positive[i - 1];
                    }else{
                        maxSum += positive[i] * positive[i - 1];
                    }
                }
                if(positive.size() % 2 != 0 && i == 0){
                    maxSum += positive[i];
                }
            }
        }
        cout << maxSum << endl;
    }
    return 0;
}
