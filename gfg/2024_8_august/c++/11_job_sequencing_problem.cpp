// TIME COMPEXITY
// O(nlogn)

// SPACE COMPEXITY
// O(n)

// CODE

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job a, Job b){
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, cmp);
        int maxDeadline = INT_MIN;
        
        for(int i = 0; i < n; i++){
            maxDeadline = max(maxDeadline,arr[i].dead);
        }
        
        vector<int> deadline(maxDeadline+1,-1);
        int cnt = 0;
        int maxProfit = 0;
        for(int i = 0; i < n; i++){
            int currProfit = arr[i].profit;
            int currId = arr[i].id;
            int currDeadline = arr[i].dead;
            
            for(int j = currDeadline; j > 0; j--){
                if(deadline[j] == -1){
                    cnt++;
                    maxProfit += currProfit;
                    deadline[j] = currId; 
                    break;
                }
            }
        }
        
        vector<int> ans;
        ans.push_back(cnt);
        ans.push_back(maxProfit);
        
        return ans;
        
    } 
};