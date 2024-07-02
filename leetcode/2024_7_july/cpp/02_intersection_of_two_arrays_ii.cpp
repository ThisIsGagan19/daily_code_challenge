// TIME COMPLEXITY
// O(l1logl1 + l2logl2)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;

        int i = 0;
        int j = 0;

        int l1 = nums1.size();
        int l2 = nums2.size();

        while(i < l1 && j < l2){
            if(nums1[i] < nums2[j]) i++;
            else if(nums1[i] > nums2[j]) j++;
            else{
                res.push_back(nums1[i]);
                i++;
                j++;
                
            }

        }

        return res;
    }
};