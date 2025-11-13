class Solution {
    vector<vector<char>> num_to_chars {
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r', 's'},
        {'t','u','v'},
        {'w','x','y', 'z'}
    };

    void backtrack(
        vector<string> &res,
        const string &digits,
        string &temp,
        const size_t digits_len,
        size_t curr_idx
    ) {
        if (curr_idx == digits_len) {
            res.push_back(temp);
            return;
        }

        size_t num_to_chars_idx = static_cast<size_t>(digits[curr_idx] - '2');

        for (char &ch: num_to_chars[num_to_chars_idx]) {
            temp.push_back(ch);
            backtrack(res, digits, temp, digits_len, curr_idx + 1);
            temp.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string temp{};

        backtrack(res, digits, temp, digits.size(), 0);

        return res;
    }
};
