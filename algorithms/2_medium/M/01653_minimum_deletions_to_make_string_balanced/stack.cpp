class Solution {
public:
    static int minimumDeletions(const string& s) {
        int res{ 0 };
        stack<char> stack{};

        for (const auto& ch : s) {
            if (ch == 'a') {
                if (!stack.empty() && stack.top() == 'b') {
                    stack.pop();
                    res += 1;
                } else {
                    stack.push('a');
                }
            } else {
                stack.push('b');
            }
        }

        return res;
    }
};
