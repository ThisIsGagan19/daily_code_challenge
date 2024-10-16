// CODE

class Solution {
public:
    typedef pair<int,char> p;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<p, vector<p> > pq;
        if(a > 0) {
            pq.push({a,'a'});
        }
        if(b > 0) {
            pq.push({b,'b'});
        }
        if(c > 0) {
            pq.push({c,'c'});
        }

        string ans = "";

        while(!pq.empty()){
            int currFreq = pq.top().first;
            int currChar = pq.top().second;
            pq.pop();
            if(ans.length() >= 2 && ans[ans.length() - 1] == currChar && ans[ans.length() - 2] == currChar){
                // not able to use it
                if(pq.empty()){
                    break;
                }
                int nextFreq = pq.top().first;
                int nextChar = pq.top().second;
                pq.pop();

                ans.push_back(nextChar);
                nextFreq--;
                if(nextFreq > 0){
                    pq.push({nextFreq,nextChar});
                }
            }
            else{
                ans.push_back(currChar);
                currFreq--;
            }
            if(currFreq > 0){
                pq.push({currFreq,currChar});
            }
        }
        return ans;
    }
};