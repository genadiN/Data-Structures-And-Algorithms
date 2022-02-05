#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int main(){
    string str;
    do{
        cin >> str;
    }while(str.length() < 1 || str.length() > 1000000);
    int arr[str.length()] , index = 0 , min_distance = 0 , distance = 0;
    char letter;
    cin >> letter;
    bool flag = false;
    for( int i = 0 ; i < str.length() ; i++){
       if( str[i] == letter && flag == false){
           for( int j = 0 ; j < str.length() ; j++){
                arr[index++] = abs(i - j);
           }
           flag = true;
       }
       if (str[i] == letter && flag == true){
            for ( int k = 0 ; k < str.length() ; k++){
                if( arr[k] > abs(i - k) ){
                    arr[k] = abs(i - k);
                }
            }
       }
    }
    for ( int i = 0 ; i < index ; i++){
        cout << arr[i] << " ";
    }
return 0;
}
