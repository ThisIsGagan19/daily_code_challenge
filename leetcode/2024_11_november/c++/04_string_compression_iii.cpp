// CODE

class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int n = word.length();
        int i=1;
        char prev = word[0];
        int cnt = 1;
        while(i<n){
            if(word[i] == prev){
                cnt++;
                if(cnt == 9){
                    comp += cnt+'0';
                    comp += prev;
                    cnt = 0;
                }
            }
            else{
                if(cnt != 0){
                    comp += cnt+'0';
                    comp += prev;
                }
                cnt = 1;
                prev = word[i];
            }
            i++;
        }
        if(cnt != 0){
            comp += cnt+'0';
            comp += prev;
        }
        return comp;
    }
};