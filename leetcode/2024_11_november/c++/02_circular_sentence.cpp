// CODE

class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence[0]!=sentence[sentence.size()-1]){
            return false;
        }
        int n=sentence.size();
        for(int i=0;i<n;i++){
            if(sentence[i]==' '){
                if(sentence[i-1]!=sentence[i+1]){
                   return false;
                }
            }else{
                continue;
            }
        }
        return true;
    }
};