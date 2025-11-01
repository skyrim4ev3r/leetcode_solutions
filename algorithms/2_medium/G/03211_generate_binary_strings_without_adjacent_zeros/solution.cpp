class Solution {
    void generate_strings_backtrack(vector<string> &res,  string &curr, const size_t len) {
        if (curr.size() == len) {
            res.push_back(curr);
            return;
        }

        if (curr.empty() || curr.back() == '1') {
            curr.push_back('0');
            generate_strings_backtrack(res, curr, len);
            curr.pop_back();
        }

        curr.push_back('1');
        generate_strings_backtrack(res, curr, len);
        curr.pop_back();
    }

public:
    vector<string> validStrings(int n) { 
        vector<string> res{};
        string curr{};

        curr.reserve(static_cast<size_t>(n));

        generate_strings_backtrack(res, curr, static_cast<size_t>(n));

        return res;
    }
};
