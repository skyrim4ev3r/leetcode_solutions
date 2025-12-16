class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stack;

        for (const char& ch : s) {
            switch (ch) {
                case ')':
                    if (!stack.empty() && stack.top() == '(') {
                        stack.pop();
                    } else {
                        stack.push(ch);
                    }

                    break;
                default:
                    stack.push(ch);
                    break;
            }
        }

        return static_cast<int>(stack.size());
    }
};
