class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack {};
        size_t popped_index {0};
        const size_t popped_len {popped.size()};

        for (const auto& val : pushed) {
            stack.push(val);

            while (!stack.empty() && stack.top() == popped[popped_index]) {
                stack.pop();
                popped_index += 1;

                if (popped_index == popped_len) {
                    return true;
                }
            }
        }

        return false;
    }
};
