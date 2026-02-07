class Solution {
    static bool backtrack(
        const string& s,
        vector<vector<bool>>& dp,
        const size_t curr_index,
        const int curr_balance
    ) {
        if (curr_balance < 0) {
            return false;
        }

        if (curr_index == s.size()) {
            return curr_balance == 0;
        }

        if (dp[curr_index][static_cast<size_t>(curr_balance)] == false) {
            return false;
        }

        bool res{ false };
        if (s[curr_index] == ')') {
            res = backtrack(s, dp, curr_index + 1, curr_balance - 1);
        } else if (s[curr_index] == '(') {
            res = backtrack(s, dp, curr_index + 1, curr_balance + 1);
        } else {
            res = backtrack(s, dp, curr_index + 1, curr_balance - 1) ||
                  backtrack(s, dp, curr_index + 1, curr_balance) ||
                  backtrack(s, dp, curr_index + 1, curr_balance + 1);
        }

        dp[curr_index][static_cast<size_t>(curr_balance)] = res;
        return res;
    }
public:
    static bool checkValidString(const string& s) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(s.size() + 1, true));
        return backtrack(s, dp, 0, 0);
    }
};
