class Solution {
public:
    // TC = O(lengthof string/2) --> O(N)
    // SC = O(1)

    // just swaping the last element with first element and start++ and last--
    void reverseString(vector<char>& s) {
        int st = 0;
        int e = s.size() - 1;
        while(st<=e){
            swap(s[st++],s[e--]);
        }
        
    }
};