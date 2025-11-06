class Solution {
public:
    string finalString(string s) {

        string res{};
        bool should_reverse{false};

        for (const char &ch: s) {
            if (ch == 'i') {
                should_reverse = !should_reverse;
            } else {
                if (should_reverse) {
                    reverse(res.begin(), res.end());
                    should_reverse = false;
                }
                res.push_back(ch);
            }
        }

        if (should_reverse) {
            reverse(res.begin(), res.end());
        }

        return res;
    }
};
