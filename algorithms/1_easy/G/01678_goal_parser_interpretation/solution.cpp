class Solution {
public:
    string interpret(string command) {
        string res{};

        for (const char &ch: command) {
            if (ch == ')') {
                if (!res.empty() && res.back() == '(') {
                    res.pop_back();
                    res.push_back('o');
                }
            } else {
                if (!res.empty() && res.back() == '(') {
                    res.pop_back();
                }
                res.push_back(ch);
            }
        }

        return res;
    }
};
