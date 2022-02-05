#include<iostream>
#include<unordered_set>
#include<queue>

using namespace std;

queue<int> q;
unordered_set<int> s;

int main(){
    int N = 0 , number = 0;
    cin >> N ;
    int subLength = 1;
    while(N--){
        cin >> number;

        if(!s.count(number)){
            s.insert(number);
        }else{
            while(q.front() != number){
                s.erase(q.front());
                q.pop();
            }
            q.pop();
        }
        q.push(number);
        int currentSubLength = q.size();
        subLength = max(subLength , currentSubLength);
    }

    cout << subLength << endl;
    return 0;
}

