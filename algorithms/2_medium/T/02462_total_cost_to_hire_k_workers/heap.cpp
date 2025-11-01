class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {

        const size_t len{costs.size()};
        const size_t candidates_usize{static_cast<size_t>(candidates)};

        priority_queue<int> left_heap{};
        priority_queue<int> right_heap{};

        size_t left_index{0};
        size_t right_index{len - 1};
        long long res{0};

        for (int _unused_var{0}; _unused_var < k; _unused_var++) {
            while (left_index <= right_index && left_heap.size() < candidates_usize) {
                left_heap.push(-costs[left_index]);
                left_index += 1;
            }

            while (left_index <= right_index && right_heap.size() < candidates_usize ){
                right_heap.push(-costs[right_index]);
                right_index -= 1;
            }

            int cost_left = left_heap.empty() ? INT_MAX : abs(left_heap.top());
            int cost_right = right_heap.empty() ? INT_MAX : abs(right_heap.top());

            if (cost_left <= cost_right) {
                res += static_cast<long long>(cost_left);
                left_heap.pop();
            } else {
                res += static_cast<long long>(cost_right);
                right_heap.pop();
            }
        }

        return res;
    }
};
