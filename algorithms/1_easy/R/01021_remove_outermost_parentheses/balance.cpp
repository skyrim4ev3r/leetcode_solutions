class Solution {
public:
    string removeOuterParentheses(string s) {
        string res{};
        int balance{0};

        for (const char &ch: s) {
            if (ch == '(') {
                balance += 1;
            } else {
                balance -= 1;
            }

            if ((balance == 1 && ch == '(') || balance == 0) {
               continue;
            }

            res.push_back(ch);
        }

        return res;
    }
};
