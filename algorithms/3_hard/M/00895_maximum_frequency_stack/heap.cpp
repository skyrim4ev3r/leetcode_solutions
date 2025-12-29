class FreqStack {
    struct Data {
        int freq;
        int ts;
        int val;

        bool operator<(const Data& other) const {
            if (freq == other.freq) {
                return ts < other.ts;
            }

            return freq < other.freq;
        }
    };

    int ts;
    unordered_map<int, int> freqs;
    priority_queue<Data> heap;
public:
    FreqStack() : ts {0}, freqs {}, heap {} {

    }

    void push(int val) {
        ts += 1;
        freqs[val] += 1;
        heap.push({freqs[val], ts, val}) ;
    }

    int pop() {
        auto data {heap.top()};
        heap.pop();
        freqs[data.val] -= 1;
        return data.val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
