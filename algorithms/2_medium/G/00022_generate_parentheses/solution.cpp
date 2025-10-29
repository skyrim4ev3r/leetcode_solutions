class Solution {
    void generate_parenthesis_backtrack(vector<string> &res, string &tmp_string, int n, int open_count, int close_count) {
        if (open_count == n && close_count == n) {
            res.push_back(tmp_string);
            return;
        }

        if (open_count < n) {
            tmp_string.push_back('(');
            generate_parenthesis_backtrack(res, tmp_string, n, open_count + 1, close_count);
            tmp_string.pop_back();
        }

        if (close_count < open_count) {
            tmp_string.push_back(')');
            generate_parenthesis_backtrack(res, tmp_string, n, open_count, close_count + 1);
            tmp_string.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string tmp_string{};
        vector<string> res{};
        generate_parenthesis_backtrack(res, tmp_string, n, 0, 0);
        return res;
    }
};
