// TIME COMPLEXITY
// O(n * log(max day))

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
public:

    int check(vector<int>& bloomDay, int mid, int k){
        int bouq_count = 0;
        int consec_flower_count = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                consec_flower_count++;
            }
            else{
                consec_flower_count = 0;
            }

            if(consec_flower_count == k){
                bouq_count++;
                consec_flower_count = 0;
            }
        }
        return bouq_count;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();

        int res = -1;

        int start_day = 0;
        int end_day = *max_element(begin(bloomDay), end(bloomDay));  // worst case = max day

        // total time complexity = O(n * log(max day))

        while(start_day <= end_day){ // O(log(max day))
            int mid = start_day + (end_day - start_day) / 2;

            if(check(bloomDay,mid,k) >= m){ // O(n)
                res = mid;
                end_day = mid - 1;
            }
            else{
                start_day = mid + 1;
            }
        }
        return res;   
    }
};