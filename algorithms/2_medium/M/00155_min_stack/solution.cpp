class MinStack {
    std::stack<int> stack;
    std::stack<int> min_stack;
public:
    MinStack() : stack{}, min_stack{} {}

    void push(int val) {
        stack.push(val);

        if (min_stack.empty() || min_stack.top() >= val) {
            min_stack.push(val);
        }
    }

    void pop() {
        int val = stack.top();
        stack.pop();

        if (!min_stack.empty() && min_stack.top() == val) {
            min_stack.pop();
        }
    }

    int top() {
        return stack.top();
    }

    int getMin() {
        return min_stack.top(); // min_stack is never empty when stack is non‑empty
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
