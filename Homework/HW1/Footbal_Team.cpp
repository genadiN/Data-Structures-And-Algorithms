#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
   int N = 0 , i = 0 , foundNumber = 1 , variable = 0 ;
    cin >> N ;
    if(N >= 1 && N <= 1000000){
        vector<int> football_Team;
        while(i < N){
         cin >> variable;
            football_Team.push_back( variable );
            i++;
        }
        sort(football_Team.begin() , football_Team.end());
        football_Team.erase(unique(football_Team.begin() , football_Team.end()) , football_Team.end());
        for(int i = 0 ; i <= football_Team.size() ; i++){
            if(football_Team[i] > 0 ){
                cout << football_Team[i] << " " << foundNumber << " " << i << endl;
                if ( foundNumber == football_Team[i] ){
                    foundNumber++;
                }
                if(foundNumber - 1!= football_Team[i] ){
                    break;
                }
            }
        }
    }
    cout << foundNumber;
return 0;
}
