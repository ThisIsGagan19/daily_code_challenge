// CODE

class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            if (meetings.empty()) return days;
            sort(meetings.begin(), meetings.end());
            int occupiedDays=0;
            int start=-1, end=-1;
            for (const auto& meeting : meetings) {
                int currStart=meeting[0],currEnd=meeting[1];
                if (currStart > end) {
                    occupiedDays+=(end-start+1);
                    start=currStart;
                    end=currEnd;
                } 
                else {
                    end=max(end,currEnd);
                }
            }
            occupiedDays+=(end-start+1);
            return days-occupiedDays+1;
        }
    };