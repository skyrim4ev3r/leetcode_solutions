class Solution {
public:
    string clearDigits(string s) {
        string stack{};

        for (const char& ch : s) {
            if (
                !stack.empty() && 
                (ch >= '0' && ch <= '9') &&
                !(stack.back() >= '0' && stack.back() <= '9')
            ) {
                stack.pop_back();
            } else {
                stack.push_back(ch);
            }
        }

        return stack;
    }
};
