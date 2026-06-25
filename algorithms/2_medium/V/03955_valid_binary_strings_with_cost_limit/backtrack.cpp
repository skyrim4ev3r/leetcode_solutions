class Solution {
    static void backtrack(
        const int curr_len,
        const int target_len,
        const int curr_cost,
        const int target_max_cost,
        const bool prev_is_one,
        vector<string>& res,
        string& temp
    ) {
        if (curr_cost > target_max_cost) { return; }

        if (curr_len == target_len) {
            res.push_back(temp);
            return;
        }

        temp.push_back('0');
        backtrack(curr_len + 1, target_len, curr_cost, target_max_cost, false, res, temp);
        temp.pop_back();

        if (!prev_is_one) {
            temp.push_back('1');
            backtrack(curr_len + 1, target_len, curr_cost + curr_len, target_max_cost, true, res, temp);
            temp.pop_back();
        }
    }
public:
    static vector<string> generateValidStrings(const int target_len, const int target_max_cost) {
        assert(target_len >= 1 && target_len <= 12 && target_max_cost >= 0);
        auto res = vector<string>();
        auto temp = string();
        temp.reserve(target_len);

        backtrack(0, target_len, 0, target_max_cost, false, res, temp);

        return res;
    }
};
