class Solution {
    void backtrack(
        array<int, 10>& digits_count,
        vector<int>& res,
        int curr_num,
        int curr_depth
    ) {
        if (curr_depth == 3) {
            if (curr_num >= 100 && curr_num < 1000 && curr_num % 2 == 0) {
                res.push_back(curr_num);
            }

            return;
        }

        for (size_t i {0}; i < 10; ++i) {
            if (digits_count[i] > 0) {
                digits_count[i] -= 1;
                backtrack(digits_count, res, curr_num * 10 + static_cast<int>(i), curr_depth + 1);
                digits_count[i] += 1;
            }
        }
    }

public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        array<int, 10> digits_count {};

        for (const int& digit : digits) {
            digits_count[static_cast<size_t>(digit)] += 1;
        }

        vector<int> res {};

        backtrack(digits_count, res, 0, 0);

        return res;
    }
};
