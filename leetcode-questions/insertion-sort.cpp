#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
    

    for(int i = 1; i<n; i++){
        int temp = arr[i];
        int j = i - 1;
        // for(j; j>=0; j--){

        //     if(arr[j] > temp){
        //         //left side
        //         arr[j+1] = arr[j];
        //     } else {
        //         break;
        //     }
        // }

        while(j>=0){
            if(arr[j] > temp){
                //left side
                arr[j+1] = arr[j];
            } else {
                break;
            }
            j--;
        }
        // Here arr[j+1] = temp means when the arr[j] > temp conditions false
        // at that index + 1 we have to put the temp value means replacing large 
        // element with smaller one
        arr[j+1] = temp;
    }


}