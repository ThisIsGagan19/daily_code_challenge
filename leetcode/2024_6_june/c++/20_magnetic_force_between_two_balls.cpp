// TIME COMPLEXITY
// O(n * log(max force))

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
public:

    bool check(vector<int>& position, int mid, int m){
        int prev = position[0];
        int balls_count = 1;
        for(int i = 1; i < position.size(); i++){
            int curr = position[i];
            if(curr - prev >= mid){
                balls_count++;
                prev = curr;
            }
            if(balls_count == m) 
                break;
        }
        return balls_count == m;
    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());

        int res = 0;

        int min_force = 1;
        int max_force = position[n-1] - position[0];  // worst case = max force

        // total time complexity = O(n * log(max force))

        while(min_force <= max_force){ // O(log(max force))
            int mid = min_force + (max_force - min_force) / 2;

            if(check(position,mid,m)){ // O(n)
                res = mid;
                min_force = mid + 1;
            }
            else{
                max_force = mid - 1;
            }
        }
        return res;
    }
};