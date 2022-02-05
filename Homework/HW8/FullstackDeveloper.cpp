#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Task {
public:
    int index;
    int minStartTime;
    int duration;

    Task(int index, int minStartTime, int duration) {
        this->index = index;
        this->minStartTime = minStartTime;
        this->duration = duration;
    }

    friend bool operator<(const Task& lhs, const Task& rhs)
    {
        if(lhs.minStartTime == rhs.minStartTime) {
            if(lhs.duration == rhs.duration) {
                return lhs.index > rhs.index;
            } else return lhs.duration > rhs.duration;
        } else return lhs.minStartTime > rhs.minStartTime;
    }

    friend bool operator>(const Task& lhs, const Task& rhs)
    {
        if(lhs.duration == rhs.duration) {
            return lhs.index > rhs.index;
        } else return lhs.duration > rhs.duration;
    }
};

int main() {
    int n;
    cin >> n;

    vector<Task> tasks;

    int t;
    int f;
    for(int i = 0; i < n; i++) {
        cin >> t;
        cin >> f;
        tasks.push_back(Task(i, t, f));
    }

    priority_queue<Task> sortedTasks (tasks.begin(), tasks.end());

    priority_queue<Task, vector<Task>, greater<Task>> possibleTasks;

    int currentTime = sortedTasks.top().minStartTime;
    int tasksExecuted = 0;

    while(tasksExecuted < n) {
        while(!sortedTasks.empty()) {
            if(sortedTasks.top().minStartTime <= currentTime) {
                possibleTasks.push(sortedTasks.top());
                sortedTasks.pop();
            } else break;
        }

        if(!possibleTasks.empty()) {
            cout << possibleTasks.top().index << " ";
            tasksExecuted += 1;
            currentTime += possibleTasks.top().duration;
            possibleTasks.pop();
        } else {
            currentTime += 1;
        }
    }

    return 0;
}
