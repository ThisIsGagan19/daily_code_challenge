
// TIME COMPLEXITY
// O(N * K)
// N -> total number of words
// K -> length of word

// SPACE COMPLEXITY
// O(1) -> best case
// O(N * K) -> worst case  for storing all char into vector of strings
// N -> total number of words
// K -> length of word

// CODE

class Solution {
public:
    void fillCount(string& str, int cnt[]){
        for(char& ch : str){
            cnt[ch - 'a']++;
        }
    }
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<string> res;

        int cnt[26] = {0};
        fillCount(words[0],cnt); // store freq of first word

        
        for(int i = 1; i < n; i++){
            int temp[26] = {0};
            fillCount(words[i],temp); // baki words ke alphabet ki freq store in temp
            for(int j = 0; j < 26; j++){
                cnt[j] = min(temp[j],cnt[j]); // upgrading the main array(cnt wala)
            }
        }

        for(int i = 0; i < 26; i++){
            int freq = cnt[i];
            while(freq--){
                // i + 'a' is representing the charracter
                res.push_back(string(1,i+'a')); // push the char into vector untill its occurence becoms 0
            }
        }
        return res;
    }
};