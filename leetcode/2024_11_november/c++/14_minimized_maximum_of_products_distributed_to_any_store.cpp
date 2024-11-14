// CODE

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        priority_queue<pair<double,double>> pq;
        for(int q: quantities)
        {
            pq.push({(double)q,1.0});
            n=n-1;
        }
                cout<<n<<endl;
        // if(n==1) return quantities[0];
        while(n>0)
        {
            double qty=pq.top().first;
            int stores=pq.top().second;
            // cout<<qty<<" "<<stores<<" "<<n<<endl;
            pq.pop();
        
                double newqty=(qty*stores)/(stores+1.0);
                pq.push({newqty,stores+1.0});
            n--;

        }
        return ceil(pq.top().first);
        
    }
};