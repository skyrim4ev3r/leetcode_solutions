class Solution {
private:
    bool is_number(const string& token) {
        if (token[0] == '-') {
            return token.size() > 1 && std::all_of(token.begin() + 1, token.end(), ::isdigit);
        }
        return std::all_of(token.begin(), token.end(), ::isdigit);
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack{};

        for (const string& token : tokens) {
            if (is_number(token)) {
                stack.push(stoi(token));
            } else {
                const int num2{stack.top()};
                stack.pop();
                const int num1{stack.top()};
                stack.pop();

                switch (token[0]) {
                    case '/':
                        stack.push(num1 / num2);
                        break;
                    case '+':
                        stack.push(num1 + num2);
                        break;
                    case '*':
                        stack.push(num1 * num2);
                        break;
                    case '-':
                        stack.push(num1 - num2);
                        break;
                    default:
                        break;
                }
            }
        }

        return stack.top();
    }
};
