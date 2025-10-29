class Solution {
public:
    string removeStars(string s) {
        vector<char> stack{};

        for (const char &ch: s) {
            if (ch == '*' && !stack.empty()) {
                stack.pop_back();
            } else {
                stack.push_back(ch);
            }
        }

        string res {};
        res.insert(res.end(), stack.begin(), stack.end());

        return res;
    }
};
