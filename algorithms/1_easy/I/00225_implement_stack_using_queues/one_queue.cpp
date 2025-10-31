class MyStack {
    queue<int> queue;
public:
    MyStack() {

    }

    void push(int x) {
        queue.push(x);
    }

    int pop() {
        size_t len = queue.size();

        for (size_t i{0}; i < len - 1; ++i) {
            queue.push(queue.front());
            queue.pop();
        }

        int top_val = queue.front();
        queue.pop();

        return top_val;
    }

    int top() {
        size_t len = queue.size();

        for (size_t i{0}; i < len - 1; ++i) {
            queue.push(queue.front());
            queue.pop();
        }

        int top_val = queue.front();
        queue.push(queue.front());
        queue.pop();

        return top_val;
    }

    bool empty() {
        return queue.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
