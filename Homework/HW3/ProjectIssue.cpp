#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_COMPLEXITY = 2 * 1000000000;

int getRightPosition(vector<int> &complexities, int skill, int start, int end) {
    int maxPossibleComplexity = -1;
    int minBiggerComplexity = MAX_COMPLEXITY;

    while (start <= end) {
        int middle = (start + end) / 2;
        int currentComplexity = complexities[middle];

        if (currentComplexity == skill) {
            return currentComplexity;
        }
        if (currentComplexity >= skill) {
            end = middle - 1;

            if (minBiggerComplexity > currentComplexity) {
                minBiggerComplexity = currentComplexity;
            }
        } else {
            start = middle + 1;

            if (maxPossibleComplexity < currentComplexity) {
                maxPossibleComplexity = currentComplexity;
            }
        }
    }

    if (maxPossibleComplexity == -1) {
        return minBiggerComplexity;
    } else if (minBiggerComplexity == MAX_COMPLEXITY) {
        return maxPossibleComplexity;
    } else if ((skill - maxPossibleComplexity) > (minBiggerComplexity - skill)) {
        return minBiggerComplexity;
    } else if ((skill - maxPossibleComplexity) < (minBiggerComplexity - skill)) {
        return maxPossibleComplexity;
    }

    return maxPossibleComplexity;
}

int main() {
    int issueCount = 0 , teamCount = 0;
    int number = 0;
    cin >> issueCount >> teamCount;

    vector<int>issues;
    vector<int>teams;

    for(int i = 0 ; i < issueCount ; i++){
        cin >> number;
        issues.push_back(number);
    }
    for(int i = 0 ; i < teamCount ; i++){
        cin >> number;
        teams.push_back(number);
    }
    sort(issues.begin() , issues.end());

    for(int i = 0 ;i < teams.size() ; ++i){
        int complexity = getRightPosition(issues , teams[i] , 0 , issues.size());
        cout << complexity << endl;
    }

    return 0;
}
