// CODE

class Solution {
    public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int mapOfS[256] = {0}, mapOfT[256] = {0};
        for(int i = 0; i < n; i++) {
            if(mapOfS[s[i]] != mapOfT[t[i]]) return 0;
            mapOfS[s[i]] = i + 1;
            mapOfT[t[i]] = i + 1;
        }
        return 1;
    }
};