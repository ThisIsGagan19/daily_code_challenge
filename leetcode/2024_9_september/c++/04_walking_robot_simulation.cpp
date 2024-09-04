// CODE

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        set<pair<int, int>> st;
        for (auto it : obstacles) {
            st.insert({it[0], it[1]});
        }
        
        int xaxis = 0, yaxis = 0;
        int maxDist = 0;
        bool left = 0, right = 0, up = 1, down = 0;

        for (auto it : commands) {
            if (it == -1) {  // Turn right
                if (up) { up = 0; right = 1; }
                else if (right) { right = 0; down = 1; }
                else if (down) { down = 0; left = 1; }
                else { left = 0; up = 1; }
            } 
            else if (it == -2) {  // Turn left
                if (up) { up = 0; left = 1; }
                else if (left) { left = 0; down = 1; }
                else if (down) { down = 0; right = 1; }
                else { right = 0; up = 1; }
            } 
            else {  // Move forward
                for (int step = 0; step < it; step++) {
                    int newX = xaxis, newY = yaxis;
                    
                    if(up) newY += 1;
                    else if(right) newX += 1;
                    else if(down) newY -= 1;
                    else if(left) newX -= 1;
                    
                    // Check if the new position is an obstacle
                    if (st.find({newX, newY}) != st.end()) {
                        break; // Stop before hitting the obstacle
                    }
                    
                    // Update position
                    xaxis = newX;
                    yaxis = newY;
                    
                    // Update max distance squared
                    maxDist = max(maxDist, xaxis * xaxis + yaxis * yaxis);
                }
            }
        }
        return maxDist;
    }
};