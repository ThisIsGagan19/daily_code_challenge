// CODE

class MyCalendar {
    map<int, int> stend;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if (start >= end) return false;  

        
        for (const auto& x : stend) {
            
            if (start < x.second && end > x.first) {
                return false;   
            }
        }

       
        stend[start] = end;
        return true;
    }
};