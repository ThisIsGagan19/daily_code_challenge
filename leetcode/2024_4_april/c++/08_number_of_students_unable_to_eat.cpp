class Solution {
    public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int preferCircle = 0, preferSquare = 0;
        for(int s : students) {
            if(s == 0) preferCircle++;
            else preferSquare++;
        }
        for(int s : sandwiches) {
            if(s == 0 and preferCircle == 0) 
                return preferSquare;
            if(s == 1 and preferSquare == 0)
                return preferCircle;
            
            if(s == 0) preferCircle--;
            else preferSquare--;
        }
        return 0;
    }
};