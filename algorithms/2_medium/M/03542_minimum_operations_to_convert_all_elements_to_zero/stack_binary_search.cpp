class Solution {
public:
    static int minOperations(vector<int>& nums) {
        vector<int> stack;
        int count{0};

        for (const int &num: nums) {
            if (num == 0) {
                count += static_cast<int>(stack.size());
                stack.clear();
            } else {
                const size_t stack_len{stack.size()};
                const size_t pos{static_cast<size_t>(lower_bound(stack.begin(), stack.end(), num) - stack.begin())};

                if (pos == stack_len) {
                    stack.push_back(num);
                } else {
                    if (stack[pos] == num) {
                        count += static_cast<int>(stack_len - pos - 1);
                    } else {
                        stack[pos] = num;
                        count += static_cast<int>(stack_len - pos);
                    }

                    stack.resize(pos + 1, 0);
                }
            }
        }

        return count + static_cast<int>(stack.size());
    }
};
