#include<iostream>
#include<queue>
#include<vector>

using namespace std;

priority_queue<int , vector<int> , greater<int>> pq;

int main(){
    int K , T , requests;
    int N;
    int completeRequests = 0;
    cin >> K >> T >> requests;
    cin >> N;
    for(int i = 1 ; i <= N ; i++){
        int num;
        cin >> num;
        pq.push(num);
        if(completeRequests == requests)continue;

        if( i % T == 0){
            for(int j = 0 ; j < K && !pq.empty(); j++){
                cout << pq.top() << " ";
                pq.pop();
            }
            completeRequests++;
        }
    }
    while(completeRequests++ < requests){
        for(int j = 0 ; j < K ; j++){
            cout << pq.top() << " ";
            pq.pop();
        }
    }
    return 0;
}
