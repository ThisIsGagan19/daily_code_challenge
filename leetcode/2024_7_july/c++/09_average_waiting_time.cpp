// TIME COMPLEXITY
// O(n)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;
        double cnt = 0;
        int total_time = 0, wait_time = 0;

        int arrival_time = customers[0][0];
        int work_time = customers[0][1];

        total_time = arrival_time + work_time;

        wait_time = total_time - arrival_time;

        if(wait_time > 0){
            cnt++;
            ans += wait_time;
        }

        for(int i = 1; i < customers.size(); i++){
            arrival_time = customers[i][0];
            work_time = customers[i][1];

            if(total_time > arrival_time)
                total_time = total_time + work_time;
            else total_time = arrival_time + work_time;

            wait_time = total_time - arrival_time;

            if(wait_time > 0){
                cnt++;
                ans += wait_time;
            }
        }

        return ans / cnt;
    }
};