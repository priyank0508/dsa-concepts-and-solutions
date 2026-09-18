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
        mid = start + (end-start)/2
    }

    return -1;
}