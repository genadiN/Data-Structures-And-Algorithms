#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    unordered_map<int,int> freq;

    long long num;
    int counter=0;
    for (int i = 0; i < n; i++)
    {
        long long numEntered = 0;
        long long multiplier = pow(10, m-1);
        for (int j = 0; j < m; j++)
        {
            cin >> num;
            numEntered += num * multiplier;
            multiplier /= 10;

        }
            freq[numEntered]++;
    }

    for (auto it = freq.begin(); it != freq.end(); ++it) {
        if ((*it).second == 1) {
            counter++;
        }
    }
    cout << counter;

}
