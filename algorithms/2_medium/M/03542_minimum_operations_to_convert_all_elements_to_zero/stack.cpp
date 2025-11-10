class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> stack{};
        int count{0};

        for (const int &num: nums) {
            while (!stack.empty() && stack.top() > num) {
                stack.pop();
                count += 1;
            }

            if (num == 0 || (!stack.empty() && stack.top() == num)) {
                continue;
            }

            stack.push(num);
        }

        return count + static_cast<int>(stack.size());
    }
};
