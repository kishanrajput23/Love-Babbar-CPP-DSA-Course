class SpecialStack {
    stack<int> s;
    int mini;
    public:
        
    void push(int data) {
        // Implement the push() function.
        if (s.empty()) {
            s.push(data);
            mini = data;
        }
        else {
            if (data<mini) {
                int val = 2*data - mini;
                s.push(val);
                mini = data;
            }
            else {
                s.push(data);
            }
        }
    }

    int pop() {
        // Implement the pop() function.
        if (s.empty()) {
            return -1;
        }
        else {
            int curr = s.top();
            s.pop();

            if (curr>mini) {
                return curr;
            }
            else {
                int prevMini = mini;
                int val = 2*mini - curr;
                mini = val;
                return prevMini;
            }
        }
    }

    int top() {
        // Implement the top() function.
        if (s.empty()) {
            return -1;
        }

        int curr = s.top();
        if (curr>mini) {
            return curr;
        }
        else {
            return mini;
        }
    }

    int getMin() {
        // Implement the getMin() function.
        if (s.empty()) {
            return -1;
        }

        return mini;
    }  
};