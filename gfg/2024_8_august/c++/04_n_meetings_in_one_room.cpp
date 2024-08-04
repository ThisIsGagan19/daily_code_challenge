// TIME COMPEXITY
// O(nlogn)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
    int maxMeetings(int n, int start[], int end[])
    {
        vector<pair<int,int>> temp;
        for(int i = 0; i < n; i++){
            temp.push_back({start[i], end[i]});
        }
        
        sort(temp.begin(), temp.end(), cmp);
        
        int cnt = 1;
        int ansEnd = temp[0].second;
        
        for(int i = 1; i < n; i++){
            if(temp[i].first > ansEnd){
                cnt++;
                ansEnd = temp[i].second;
            }
        }
        
        return cnt;
    }
};