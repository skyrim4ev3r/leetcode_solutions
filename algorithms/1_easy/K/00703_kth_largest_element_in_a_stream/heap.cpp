class KthLargest {
    priority_queue<int, vector<int>, greater<int>> min_heap;
    const size_t k;
public:
    KthLargest(int k, const vector<int>& nums): k{static_cast<size_t>(k)} {
        for (const auto num : nums) {
            min_heap.push(num);

            if (min_heap.size() > this->k) {
                min_heap.pop();
            }
        }
    }

    int add(int val) {
        min_heap.push(val);

        if (min_heap.size() > k) {
            min_heap.pop();
        }

        return min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
