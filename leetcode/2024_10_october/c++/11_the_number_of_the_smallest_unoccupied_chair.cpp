// CODE

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int targetTime = times[targetFriend][0];
        priority_queue< int, vector<int>, greater<int> > unOccChair; //to store available chairs

        sort(times.begin(), times.end());
        set< pair<int, int> > s; //to store departure time of arrives friends

        int n = times.size();
        for(int i=0; i<n; i++)  unOccChair.push(i); // since all chairs are unoccupied in the starting
        int i=0;
        while( i<n ){
            auto itr = *s.begin();
            while(  !s.empty() && itr.first<=times[i][0] ){ // to mark chair as unOccupied after friend has left.
                unOccChair.push(itr.second);
                s.erase(itr);
                itr = *s.begin();
            }
            if( times[i][0]==targetTime )   return unOccChair.top(); // to check if that is the target friend
            else{
                int chairN = unOccChair.top(); unOccChair.pop();
                s.insert({times[i][1], chairN}); // store departure time of arrived friend with the chair occupied by them
                i++;
            }
        }

        return -1;
    }
};