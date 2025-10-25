class Solution {
public:
    bool isValid(string s) {

        stack<char> stack{};
        char top_char;

        for (const char &ch: s) {
            switch (ch) {
                case ('}'):
                case (']'):
                case (')'):
                    if (stack.empty()) {
                        return false;
                    }

                    top_char = stack.top();
                    stack.pop();

                    if ((ch == '}' && top_char != '{') ||
                        (ch == ']' && top_char != '[') ||
                        (ch == ')' && top_char != '(')
                    ) {
                        return false;
                    }
                    break;
                default:
                    stack.push(ch);
                    break;
            }
        }

        return stack.empty();
    }
};
