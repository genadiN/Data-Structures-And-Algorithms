#include<iostream>


using namespace std;

void myMerge(int arr[] , int l , int middle , int r ){
    int lz = middle - l + 1 , rz = r - middle;
    int lArr[lz] , rArr[rz];
    int i = 0 , j = 0 , k = l;
    for( i = 0 ; i < lz ; i++){
        lArr[i] = arr[l + i];
    }

    for(j = 0 ; j < rz ; j++){
        rArr[j] = arr[middle + 1 + j];
    }
    i = 0 , j = 0;
    while( i < lz && j < rz){
        if(lArr[i] <= rArr[j]){
            arr[k] = lArr[i];
            i++;
        }else{
            arr[k] = rArr[j];
            j++;
        }
        k++;
    }
    while(i < lz){
        arr[k++] = lArr[i++];
    }
    while( j < rz){
        arr[k++] = rArr[j++];
    }
}

void mergeSort(int arr[] , int l , int r){
    if( l < r){
        int middle = (l + r) / 2;

        mergeSort(arr , l , middle);
        mergeSort(arr , middle + 1 , r);
        myMerge(arr , l , middle , r);
    }
}
/*
void cleanArr(int arr[] , int N , int cleanedArr[]){
    int index = 0;
    for(int i = 0)
}*/

void input(int arr[] , int N){
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }
}

void print(int arr[] , int N){
    for(int i = 0 ; i < N ; i++){
        if( i == 0 ){
            cout << arr[0] << " ";
        }
        if( arr[i] != arr[i - 1] && i > 0){
            cout << arr[i] << " ";
        }
    }
}

int main(){
    int N = 0 ;
    cin >> N;
    int arr[N];
    input(arr , N);
    mergeSort(arr , 0 , N - 1);
    print(arr , N);
return 0;
}
