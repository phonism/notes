class Stack {
public:
    queue<int> q;
    // Push element x onto stack
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack
    void pop() {
        queue<int> p;
        while (!q.empty()) {
            if (q.size() == 1)
                break;
            p.push(q.front());
            q.pop();
        }
        q = p;
    }

    // Get the top element
    int top() {
        queue<int> p = q;
        while (!p.empty()) {
            if (p.size() == 1)
                return p.front();
            p.pop();
        }
    }

    // Return whether the stack is empty
    bool empty() {
        return q.empty();
    }
};
