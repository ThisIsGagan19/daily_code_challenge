// CODE

class Solution {
    public:
      /*You are required to complete below function */
      string multiplyStrings(string& s1, string& s2) {
          bool neg = false;
          if(s1[0] == '-'){
              neg = !neg;
              s1 = s1.substr(1);
          }
          if(s2[0] == '-'){
              neg = !neg;
              s2 = s2.substr(1);
          }
          int l1 = s1.length();
          int l2 = s2.length();
          vector<int> res(l1+l2,0);
          reverse(s1.begin(), s1.end());
          reverse(s2.begin(), s2.end());
          
          for(int i = 0; i < l1; i++){
              for(int j = 0; j < l2; j++){
                  res[i+j] += ((s1[i] - '0') * (s2[j] - '0'));
                  res[i+j+1] += res[i+j] / 10;
                  res[i+j] %= 10;
              }
          }
          
          string ans = "";
          bool zeros = true;
          for(int i = res.size() - 1; i >= 0; i--){
              if(res[i] != 0) zeros = false;
              if(zeros == false){
                  ans += (res[i] + '0');
              }
          }
          if(ans.empty()) return "0";
          if(neg){
              ans = '-' + ans;
          }
          return ans;
      }
};