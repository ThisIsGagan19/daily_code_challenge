// CODE

class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int>count(3,0);      // to store the frequencies of all three characters
        for(char c:s){
            count[c-'a']++;
        }
        for(int x: count){
            if(x<k) return -1;
        }

        int l = 0, r = 0, n = s.length();
        int len = 0;

        vector<int>windowCount(3,0);

        while(r<n){
            windowCount[s[r]-'a']++;

            while(l<=r && (count[0]-windowCount[0]<k || count[1]-windowCount[1]<k || 
            count[2]-windowCount[2]<k)){
                windowCount[s[l]-'a']--;
                l++;
            }
            len=max(len, r-l+1);
            r++;
        }

        return n - len;
    }
};