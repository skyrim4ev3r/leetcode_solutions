class FreqStack {
    int max_freq;
    unordered_map<int, int> freqs;
    unordered_map<int, vector<int>> hash_stack;
public:
    FreqStack() : max_freq {0}, freqs {}, hash_stack {} {

    }

    void push(int val) {
        int& freq {freqs[val]};
        freq += 1;
        max_freq = std::max(max_freq, freq);
        hash_stack[freq].push_back(val);
    }

    int pop() {
        auto& vec {hash_stack[max_freq]};
        const int val {vec.back()};
        vec.pop_back();
        freqs[val] -= 1;

        if (vec.size() == 0) {
            max_freq -= 1;
        }

        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
