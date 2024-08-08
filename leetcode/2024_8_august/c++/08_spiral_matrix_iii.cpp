// TIME COMPEXITY
// O(max(rows,cols) ^ 2)

// SPACE COMPEXITY
// O(1)

// CODE

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> direction = {{0,1}, {1,0}, {0,-1}, {-1,0}}; // E S W N
        vector<vector<int>> res;


        int steps = 0; // increase on East and West
        int dir = 0; // currently east

        res.push_back({rStart, cStart});

        while(res.size() < rows * cols){
            if(dir == 0 || dir == 2){ // East and West
                steps++;
            }
            for(int i = 0; i < steps; i++){// jitne steps h utna chalna h
                rStart += direction[dir][0]; // row increament
                cStart += direction[dir][1]; // col increament

                // if valid
                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols){
                    res.push_back({rStart, cStart});
                }
            }

            dir = (dir + 1) % 4;
        }

        return res;
    }
};