class Solution {
    static inline bool are_consecutive(const char& a, const char& b) {
        return a == b - 1 ||
               a == b + 1 ||
               (a == 'z' && b == 'a') ||
               (a == 'a' && b == 'z');
    }

public:
    static string resultingString(string s) {
        string stack{};

        for (const char& ch : s) {
            if (!stack.empty() && are_consecutive(stack.back(), ch)) {
                stack.pop_back();
            } else {
                stack.push_back(ch);
            }
        }

        return stack;
    }
};
