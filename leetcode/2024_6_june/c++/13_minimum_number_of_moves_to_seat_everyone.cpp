// TIME COMPLEXITY
// O(nlogn)

// SPACE COMPLEXITY
// O(1)

// CODE

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int cnt = 0;

        for(int i = 0; i < students.size(); i++){
            cnt += abs(seats[i] - students[i]);
        }

        return cnt;
    }
};