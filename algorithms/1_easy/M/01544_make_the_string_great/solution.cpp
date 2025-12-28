class Solution {
public:
    static string makeGood(const string& s) {
        string stack;

        for (const char& ch : s) {
            if (!stack.empty()) {
                const char top {stack.back()};

                if (top + 'A' - 'a' == ch || ch + 'A' - 'a' == top) {
                    stack.pop_back();
                } else {
                    stack.push_back(ch);
                }
            } else {
                stack.push_back(ch);
            }
        }

        return stack;
    }
};
