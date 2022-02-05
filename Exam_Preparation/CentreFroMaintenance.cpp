#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int K , T , B;
int N;
vector<int>input;
vector<int>queries;
vector<int>ans;

int main(){
    cin >> K >> T >> B;
    int B1 = B*K;
    cin >> N;
    int var;
    for(int i = 0 ; i < N ; i++){
        cin >> var;
        input.push_back(var);
    }
    for(int i = 0 ; i < N; i += T){
        B1 -= K;
        for(int j = i ; j < i + T ; j++){
            if(j < N){
                queries.push_back(input[j]);
            }
        }
        sort(queries.begin() , queries.end());
        for(int m = 0 ; m < K ; m++){
            ans.push_back(queries[m]);
        }
        for(int e = 0 ; e < K ; e++){
            queries.erase(queries.begin());
        }
        if(i == N - 1 && B1 > 0){
            for(int n = 0 ; n < B1 ; n++){
                ans.push_back(queries[n]);
            }
        }
    }
    for(int i = 0 ; i < B * K ; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
