// CODE

class CustomStack {
private:
    vector<int> arr;  
    int maxSize;      
    int top;          

public:

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        top = -1;              
    }

    void push(int x) {
        if (top < maxSize - 1) {
            top++;
            if (top < arr.size()) {
                arr[top] = x;
            } else {
                arr.push_back(x);
            }
        }
    }

    int pop() {
        if (top == -1) {
            return -1;  
        }
        int result = arr[top];
        top--;
        return result;
    }

    void increment(int k, int val) {
        int limit = min(k, top + 1);  
        for (int i = 0; i < limit; i++) {
            arr[i] += val;
        }
    }
};