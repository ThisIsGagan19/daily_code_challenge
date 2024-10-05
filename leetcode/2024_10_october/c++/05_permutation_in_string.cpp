// CODE

class Solution {
private:
    bool checkEqual(int a[26], int b[26]){
        for(int i = 0; i < 26; i++){
            if( a[i] != b[i]){
                return 0;
            }
        }
        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int arr1[26] = {0};
        int number1 = 0;
        
        // character count store in s1 string.
        for(int i = 0; i < s1.length(); i++){
            char ch1 = s1[i];
            number1 = ch1 - 'a';
            arr1[number1]++;
        }
        

        // traverse in s2 string in window form of the length of s1 string.
        int windowSize = s1.length();
        int arr2[26] = {0};
        int number2 = 0;

        // just for the first window.
        int i = 0;
        while(i < windowSize && i<s2.length()){
            char ch2 = s2[i];
            number2 = ch2 - 'a';
            arr2[number2]++;
            i++;
        }

        if (checkEqual(arr1,arr2)){
            return 1;
        }

        //for another windows.
        while(i < s2.length()){
            // adding next window
            char newchar = s2[i];
            int index = newchar - 'a';
            arr2[index]++;
            // removing the previous element from the window
            char oldchar = s2[i-windowSize];
            index = oldchar - 'a';
            arr2[index]--;

            i++;

            if (checkEqual(arr1,arr2)){
                return 1;
            }
        }
        return 0;
        
    }
};