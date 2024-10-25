class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        unordered_map<string, bool> mp;
        vector<string> ans;
        bool flag = 0;
        for (auto it: folder){
            for (int i=1; i<it.length(); i++){
                if (it[i] == '/'){
                    string temp = it.substr(0, i);
                    if (mp.find(temp) != mp.end()){
                        flag = 1;
                        break;
                    }
                }
            }
            if (!flag){
                mp[it] = 1;
                ans.push_back(it);
            }else{
                flag = 0;
            }
        }

        return ans;
    }
};