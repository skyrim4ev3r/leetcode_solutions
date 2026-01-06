class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const size_t len {nums.size()};
        size_t max_index {0};

        for (size_t i {0}; i < len; ++i) {
            if (nums[i] > nums[max_index]) {
                max_index = i;
            }
        }

        vector<int> res = vector<int>(len, 0);
        res[max_index] = -1;
        size_t index {max_index == 0 ? len - 1 : max_index - 1};
        stack<int> stack;
        stack.push(nums[max_index]);

        while (index != max_index) {
            const int curr_num {nums[index]};

            while (!stack.empty() && stack.top() <= curr_num) {
                stack.pop();
            }

            if (!stack.empty()) {
                res[index] = stack.top();
            } else {
                res[index] = -1;
            }

            if (index == 0) {
                index = len - 1;
            } else {
                index -= 1;
            }

            stack.push(curr_num);
        }

        return res;
    }
};
