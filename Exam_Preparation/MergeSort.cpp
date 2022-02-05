#include<iostream>

using namespace std;

void print(int arr[] , int N){
    for(int i = 0 ; i < N ; i++){
        cout << arr[i] << " ";
    }
}

void merge(int arr[] , int start , int middle , int end){
    int leftSize = middle - start + 1 , rightSize = end - middle;
    int arr1[leftSize] , arr2[rightSize];
    int i = 0 , j = 0 , k = start;

    for(i = 0; i < leftSize; i++){
        arr1[i] = arr[start + i];
    }
    for(j= 0; j < rightSize ; j++){
        arr2[j] = arr[middle + 1 + j];
    }

    i = 0 , j = 0 , k = start;
    while(i < leftSize && j < rightSize){
        if(arr1[i] <= arr2[j]){
            arr[k] = arr1[i++];
        }else{
            arr[k] = arr2[j++];
        }
        k++;
    }
    while(i <leftSize){
        arr[k++] = arr1[i++];
    }
    while(j < rightSize){
        arr[k++] = arr2[j++];
    }

}

void mergeSort(int arr[] , int l , int r){
    if(l < r){
        int middle = (l + r)/ 2;
        mergeSort(arr , l , middle);
        mergeSort(arr , middle + 1 , r);
        merge(arr , l , middle , r);
    }
}

int main(){
    int N = 0;
    cin >> N ;
    int arr[N];
    for(int i = 0 ;i < N ; i++){
        cin >> arr[i];
    }
    mergeSort(arr , 0 , N - 1);
    print(arr , N);
}
