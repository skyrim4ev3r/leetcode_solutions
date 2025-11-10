class CustomStack {
    vector<int> stack;
    const size_t max_size;
public:
    CustomStack(int maxSize) :  max_size{static_cast<size_t>(maxSize)} { }
    
    void push(int x) {
        if (stack.size() < max_size) {
            stack.push_back(x);
        }
    }
    
    int pop() {
        if (stack.empty()) {
            return -1;
        }

        int res{stack.back()};
        stack.pop_back();
        return res;
    }
    
    void increment(int k, int val) {
        const size_t end_index{min(stack.size(), static_cast<size_t>(k))};

        for (size_t i{0}; i < end_index; ++i) {
            stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
