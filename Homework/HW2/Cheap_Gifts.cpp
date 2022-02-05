#include<iostream>

using namespace std;

void myMerge(int arr[] , int start , int middle , int finish){
    int leftSize = middle - start + 1 , rightSize = finish - middle ;
    int arr1[leftSize] , arr2[rightSize];
    int i = 0 , j = 0 , k = start;
    for( i = 0; i < leftSize; i++ ){
        arr1[i] = arr[start + i];
    }
    for(j = 0; j < rightSize ; j++){
        arr2[j] = arr[middle + 1 + j];
    }
    i = 0 , j = 0 ;
    while(i < leftSize && j < rightSize ){
        if( arr1[i] <= arr2[j] ){
            arr[k] = arr1[i];
            i++;
        }else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while( i < leftSize){
        arr[k++] = arr1[i++];
    }
    while( j < rightSize){
        arr[k++] = arr2[j++];
    }
}

void mergeSort( int arr[] , int left , int right){
    if( left < right){
        int middle = (left + right) / 2;
        mergeSort( arr , left , middle);
        mergeSort( arr , middle + 1 , right);
        myMerge( arr , left , middle , right );
    }
}

void input( int *arr , int N){
    for ( int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }
}

void print( int *arr , int N){
    for ( int i = 0 ; i < N ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int N = 0 , K = 0;
    cin >> N;
    int arr[N];
    input( arr , N);
    cin >> K;
    if( K >= 1 && K <= N){
         mergeSort(arr , 0 , N - 1);
         long sumGifts = 0;
         for (int i = 0 ; i < K ; i++){
            sumGifts += arr[i];
         }
         cout << sumGifts ;
    }

}
