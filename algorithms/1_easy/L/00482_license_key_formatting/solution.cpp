class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int total_valid_chars{0};

        for (const char& ch : s) {
            if (ch != '-') {
                total_valid_chars += 1;
            }
        }

        if (total_valid_chars == 0) {
            return "";
        }

        int total_res_char = total_valid_chars + (total_valid_chars - 1) / k;
        string res;
        res.reserve(static_cast<size_t>(total_res_char));
        int curr_count{0};

        for (auto it{s.rbegin()}; it != s.rend(); ++it) {
            if (*it == '-') {
                continue;
            }

            curr_count += 1;

            if (curr_count > k) {
                curr_count = 1;
                res.push_back('-');
            }

            if (*it >= 'a' && *it <= 'z') {
                res.push_back(*it - 32);
            } else {
                res.push_back(*it);
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
