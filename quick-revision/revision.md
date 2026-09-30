# DSA Concepts & Solutions

Quick revision reference — question name + solution code. No fluff.

---

## LeetCode

### 1. 3Sum

```js
var threeSum = function (nums) {
    nums.sort((a, b) => a - b)

    const ans = []

    for (let i = 0; i < nums.length - 2; i++) {

        if (i > 0 && nums[i] === nums[i - 1]) {
            continue
        }

        let leftPointer = i + 1
        let rightPointer = nums.length - 1

        while (leftPointer < rightPointer) {
            const sum = nums[i] + nums[leftPointer] + nums[rightPointer]

            if (sum < 0) {
                // Increasing the leftPointer because we need to move forward to 0 and the array is sorted
                leftPointer++
            } else if (sum > 0) {
                // Decreasing the rightPointer because we need to move forward to 0 and the array is sorted
                rightPointer--
            } else {
                // If above both conditions are false it means the sum is 0 and thats we want

                ans.push([nums[i], nums[leftPointer], nums[rightPointer]])

                leftPointer++
                rightPointer--

                // Skipping the duplicate elements by checking with the previous one that we have alreday used
                while (leftPointer < rightPointer && nums[leftPointer] === nums[leftPointer - 1]) {
                    leftPointer++
                }

                while (leftPointer < rightPointer && nums[rightPointer] === nums[rightPointer + 1]) {
                    rightPointer--
                }
            }
        }
    }

    return ans
};
```

---

### 2. Pivot Index

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        int leftTotal = 0;

        for(int i = 0; i < nums.size(); i++){
            total = total + nums[i];
        }

        for(int i = 0; i < nums.size(); i++){
            int rightTotal = total - leftTotal - nums[i];
            if(rightTotal == leftTotal){
                return i;
            }
            leftTotal = leftTotal + nums[i];
        }

        return -1;
    }
};
```

---

### 3. Unique Number of Occurrences

```js
var uniqueOccurrences = function(arr) {
    const obj = {}
    for(let i = 0; i<arr.length; i++){
      if(obj[arr[i]]){
        obj[arr[i]] = obj[arr[i]] + 1
      }else {
        obj[arr[i]] = 1
      }
    }

  let ans = 0
  let arr1 = Object.values(obj)

  let seen = new Set();

    for (let num of arr1) {
        if (seen.has(num)) {
            return false;
        }

        seen.add(num);
    }

    return true;
};
```

---

### 4. Find All Duplicates in an Array

```js
var findDuplicates = function(nums) {
    const ans = []
    for(let i = 0; i<nums.length; i++){
        const index = nums[Math.abs(nums[i]) - 1]
        if(index < 0){
            ans.push(Math.abs(nums[i]))
        }
        nums[Math.abs(nums[i]) - 1] = -nums[Math.abs(nums[i]) - 1]
    }
    return ans
};
```

---

### 5. Reverse Integer

```js
var reverse = function(x) {
    const minIntegerLength = -(2**31)
    const maxIntegerLength = (2**31)

    let ans = 0
    while (x !== 0){
        // Get last digit from given number
        let digit = x%10
        if((ans > Math.trunc(maxIntegerLength/10)) || (ans < Math.trunc(minIntegerLength/10))) {
            return 0
        }
        ans = (ans*10) + digit
        x = Math.trunc(x/10)
    }
    return ans
};
```

---

### 6. Binary Search

```cpp
int binarySearch(vector<int>& arr, int s, int e, int key) {

    int start = s;
    int end = e;
    int mid = start + (end-start)/2;

    while (start <= end) {
        
        if(arr[mid] == key) {
            return key;
        }
        
        if(arr[mid] < key){
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }

    return -1;
}
```

---

### 7. Sqrt(x)

```cpp
class Solution {
public:
    long long binarySearch(int n) {
        int s = 0;
        int e = n;
        long long int mid = s + (e - s) / 2;
        long long ans = -1;
        while (s <= e) {
            long long square = mid * mid;
            if (square == n) {
                return mid;
            }

            if (square < n) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }

        return ans;
    }

    int mySqrt(int x) {
        return binarySearch(x);
    }
};
```

---

### 8. Search in Rotated Sorted Array

```cpp
int calculatePivot(vector<int>& arr, int n) {
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    
    while(s<e){
        if(arr[mid] >= arr[0]) {
            s = mid + 1;
        } else {
            e = mid;
        } 
        
        mid = s + (e-s)/2;
    }
    return s;
}

int binarySearch(vector<int>& arr, int s, int e, int key) {
    
    int start = s;
    int end = e;
    int mid = start + (end-start)/2;

    while (start <= end) {
        
        if(arr[mid] == key) {
            return mid;
        }
        
        if(key > arr[mid]){
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }

    return -1;
}

int search(vector<int>& arr, int n, int k)
{
    int pivot = calculatePivot(arr, n);

    if(k >= arr[pivot] && k <= arr[n-1]) {
         return binarySearch(arr, pivot, n-1, k);
    } else {
        return binarySearch(arr, 0, pivot - 1, k);
    }
    
    return -1;
}
```

---

### 9. Find Pivot in Rotated Array

```cpp
int calculatePivot(int arr[], int n) {
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    
    while(s<e){
        if(arr[mid] >= arr[0]) {
            s = mid + 1;
        } else {
            e = mid;
        } 
        
        mid = s + (e-s)/2;
    }
    return s;
}

int main() {

    int arr[5] = {8,10,17,1,3};
    cout << "Pivot is: " << calculatePivot(arr, 5) << endl;
}
```

---

### 10. Bubble Sort

```cpp
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
```

---

### 11. Insertion Sort

```cpp
#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){

    for(int i = 1; i<n; i++){
        int temp = arr[i];
        int j = i - 1;

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
```

---
