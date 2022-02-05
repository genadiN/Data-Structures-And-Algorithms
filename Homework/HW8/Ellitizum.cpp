#include <bits/stdc++.h>
using namespace std;
#include<queue>

void input(vector<double>&v, int N){
    double var = 0.0;
    for(int i = 0 ; i < N ; i++){
        cin >> var;
        v.push_back(var);
    }
}

void medians(vector<double>&v , int N){
    priority_queue<double>que;
    priority_queue<double , vector<double> , greater<double> >pri_que;

    double median = v[0];
    que.push(median);

    cout << median << endl;

    for(int i = 1 ; i < N ; i++){
        double var = v[i];
        if(que.size() > pri_que.size()){
            if( var < median){
                pri_que.push(que.top());
                que.pop();
                que.push(var);
            }else{
                pri_que.push(var);
            }
            median = que.top() / 2 + pri_que.top() / 2;
        }else if( que.size() == pri_que.size()){
            if( var < median){
                que.push(var);
                median = que.top();
            }else{
               pri_que.push(var);
               median = pri_que.top();
            }
        }else{
            if(var > median){
                que.push(pri_que.top());
                pri_que.pop();
                pri_que.push(var);
            }else{
                que.push(var);
            }
            median = que.top() / 2 + pri_que.top() / 2;
        }
        printf("%.1f\n" , median);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(1);
    int N = 0;
    cin >> N;
    vector<double>vec;
    input(vec , N);
    medians(vec , N);
    return 0;
}
