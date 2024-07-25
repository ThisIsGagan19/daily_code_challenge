// TIME COMPLEXITY
// O(nlogn)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
public:
    void mergeArray(vector<int>& nums,int s, int e, int mid){
        int l1 = mid - s + 1;
        int l2 = e - mid;
        vector<int> left(l1);
        vector<int> right(l2);

        for(int i = 0; i < l1; i++){
            left[i] = nums[s+i];
        }
        for(int i = 0; i < l2; i++){
            right[i] = nums[mid+1+i];
        }
        int i = 0;
        int j = 0;
        int index = s;
        while(i < l1 && j < l2){
            if(left[i] < right[j]){
                nums[index] = left[i++];
            }
            else{
                nums[index] = right[j++];
            }
            index++;
        }
        while(i < l1){
            nums[index++] = left[i++];
        }
        while(j < l2){
            nums[index++] = right[j++];
        }
    }
    void mergeSort(vector<int>& nums,int l, int r){
        if(l >= r) return ;
        
        int mid = l + (r-l)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);

        mergeArray(nums,l,r,mid);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};