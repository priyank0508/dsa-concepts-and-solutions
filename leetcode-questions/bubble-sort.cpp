#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n)
{   
    for(int i = 1; i<n; i++){
    bool isswap = false;
    //here j<n-1 because when we check arr[j] > arr[j+1] so while checking arr[j+1]
    // it will be outside of an array when j is at the last element of an array

    // More optimised is j<n-i because we have already placed largest element of 
    // an array to the end
        for(int j = 0; j<n-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                isswap = true;
            }
        }
        
        if(isswap == false){
            break;
        }
    }
}
