// APPROACH
// 1 simple binary search question.
// 2 if element at mid of arr1 is found at mid of arr2 then start is mid + 1.
// 3 if element at mid of arr1 is not found at mid of arr2 then e = mid.
// 4 update mid.
// 5 return start.

// TIME COMPLEXITY
// O(logn)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        int st = 0; 
        int e = n - 1;
        int mid = st + (e - st) / 2;
        
        while(st < e){
            if(arr1[mid] == arr2[mid]){
                st = mid + 1;
            }
            else{
                e = mid;
            }
            mid = st + (e - st) / 2;
        }
        return st;
    }
};