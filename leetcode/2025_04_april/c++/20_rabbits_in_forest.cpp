// COPIED
// CODE

class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            int result = 0;
            unordered_map<int, int> umap;
    
            for (auto& a : answers)
                umap[a]++;
    
            for (auto [key, val] : umap) {
                int groupSize = key + 1;
                int groups = ceil((double)val / groupSize);
                result += groups * groupSize;
            }
    
            return result;
        }
};