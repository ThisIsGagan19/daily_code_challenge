// TC = O(NlogN) -> O(N)
// SC = O(N) -> O(1)

// CODE

class Solution {
public:
    string sortVowels(string s) {
        // approach 1
        // string vow = "";
        // string t = "";
        // for(char ch : s){
        //     if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        //         vow += ch;
        //         t += '#';
        //     }
        //     else{
        //         t += ch;
        //     }
        // }

        // sort(vow.begin(), vow.end());
        // int j = 0;
        // for(int i = 0; i < t.length() && j < vow.size(); i++){
        //     if(t[i] == '#'){
        //         t[i] = vow[j];
        //         j++;
        //     }
        // }

        // return t;

        // approach 2

        unordered_map<char,int> mp;


        for(char ch : s){
            if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                mp[ch]++;
            }
        }

        string vow = "AEIOUaeiou";
        int j = 0;

        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                while(mp[vow[j]] == 0){
                    j++;
                }
                s[i] = vow[j];
                mp[vow[j]]--;
            }
        }
        return s;

    }
};