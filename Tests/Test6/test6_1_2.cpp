#include<iostream>
#include<vector>

using namespace std;

void markComponent(int current , vector<vector<int>>& neighbours, vector<bool>& isFind){
    isFind[current] = true;
    for(int i = 0 ; i < neighbours[current].size() ; i++){
        if(!isFind[neighbours[current][i]]){
            markComponent( neighbours[ current ][i] , neighbours , isFind );
        }
    }
}

int main(){
    int testCount = 0;
    cin >> testCount;

    for(int i = 0 ; i < testCount ; i++){
        int vertices = 0 , edges = 0;
        cin >> vertices >> edges;

        vector<vector<int>> neighbours(vertices);
        while(edges){
            int start = 0 , finish = 0;
            cin >> start >> finish;
            neighbours[start].push_back(finish);
            neighbours[finish].push_back(start);
            edges--;
        }

        int componentCount = 0;
        vector<bool> isFind(vertices , false);

        for(int i = 0 ; i< vertices ; i++){
            if(!isFind[i]){
                componentCount++;
                markComponent(i , neighbours , isFind);
            }
        }
        cout << componentCount << " ";
    }


}
