// TIME COMPLEXITY
// O(n * logn)

// SPACE COMPLEXITY
// O(n)

// CODE

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(int &i : arr1){
            mp[i]++;
        }

        int index = 0;

        for(int &i : arr2){
            while(mp[i]-- > 0){
                arr1[index++] = i;
            }
        }

        for(auto &i : mp){
            int freq = i.second;
            while(freq > 0){
                arr1[index++] = i.first;
                freq--;
            }
        }

        return arr1;
    }
};