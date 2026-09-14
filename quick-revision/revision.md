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
