class MyQueue {
    stack<int> put_stack, get_stack;

    void fill_get_stack() {
        if(get_stack.size() == 0) {
            while (put_stack.size() > 0) {
                get_stack.push(put_stack.top());
                put_stack.pop();
            }
        }
    }

public:
    MyQueue() {

    }

    void push(int x) {
        put_stack.push(x);
    }

    int pop() {
        fill_get_stack();
        int val = get_stack.top();
        get_stack.pop();
        return val;
    }

    int peek() {
        fill_get_stack();
        return get_stack.top();
    }

    bool empty() {
        return get_stack.size() == 0 && put_stack.size() == 0;
    }
};
