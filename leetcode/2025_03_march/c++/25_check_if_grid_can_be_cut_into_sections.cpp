// CODE

class Solution {
    public:
        bool intervals(vector<pair<int,int>>& intervals){
            sort(intervals.begin(),intervals.end());
            int start=0;
            int end =0;
            int maxEnd=intervals[0].second;
            int count = 0;
            for(auto& it: intervals){
                start = it.first;
                end = it.second;
                if(start>=maxEnd) count++;
                maxEnd = max(maxEnd,end);
            }
            return count>=2;
        }
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            vector<pair<int,int>>x,y;
            for(auto& coord: rectangles){
                x.push_back({coord[0],coord[2]});
                y.push_back({coord[1],coord[3]});
            }
            return intervals(x) || intervals(y);
        }
    };