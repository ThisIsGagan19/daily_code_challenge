// CODE

class SpecialQueue {

  public:
    queue<int>q;
    deque<int>minq;
    deque<int>maxq;
    void enqueue(int x) {
        q.push(x);
        while(minq.size() && minq.back() > x) minq.pop_back();
        while(maxq.size() && maxq.back() < x) maxq.pop_back();
        minq.push_back(x);
        maxq.push_back(x);
    }

    void dequeue() {
        int x = q.front();
        q.pop();
        if(x == minq.front()) minq.pop_front();
        if(x == maxq.front()) maxq.pop_front();
    }

    int getFront() {
        return q.front();
    }

    int getMin() {
        return minq.front();
    }

    int getMax() {
        return maxq.front();
    }
};