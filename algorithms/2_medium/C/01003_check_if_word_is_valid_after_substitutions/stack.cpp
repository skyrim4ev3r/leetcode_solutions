class Solution {
public:
    bool isValid(string s) {
        vector<char> stack{};

        for (const auto& ch : s) {
            if (ch == 'c') {
                const size_t len{ stack.size() };

                if (len >= 2 && stack[len - 1] == 'b' && stack[len - 2] == 'a') {
                    stack.pop_back();
                    stack.pop_back();
                } else {
                    return false;
                }
            } else {
                stack.push_back(ch);
            }
        }

        return stack.empty();
    }
};
