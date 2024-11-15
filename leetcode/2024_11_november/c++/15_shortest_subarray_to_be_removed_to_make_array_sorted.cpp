// CODE

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int pre=0, post=n-1;
        for(int i=1;i<n;i++)
            if(arr[pre]<=arr[i]) pre++; else break;
        for(int i=n-2;i>=0;i--)
            if(arr[post]>=arr[i]) post--; else break;

        if(post<=pre) return 0;

        int minSubarr=min(n-pre, post+1)-1;
        if(arr[pre]<=arr[post]) return min(minSubarr, post-pre-1);
        cout<<minSubarr<<" "<<pre<<" "<<post<<endl;
        int t1=0, t2=post;
        while(t1<=pre && t2<n){
            while(t2<n && arr[t1]>arr[t2]) t2++;
            minSubarr=min(minSubarr, t2-t1-1);
            t1++;
        }

        return minSubarr;

    }
};