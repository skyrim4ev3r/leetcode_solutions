class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nums_str;
        nums_str.reserve(nums.size());

        for (const auto& num : nums) {
            nums_str.push_back(to_string(num));
        }

        ranges::sort(nums_str, [](const auto& a, const auto& b) {
            const size_t a_len{ a.size() };
            const size_t b_len{ b.size() };
            const size_t total{ a_len + b_len };

            for (size_t i{ 0 }; i < total; ++i) {
                const size_t a_index{ i % a_len };
                const size_t b_index{ i % b_len };

                if (a[a_index] != b[b_index]) {
                    return a[a_index] > b[b_index];
                }
            }

            return false;
        });

        if (nums_str[0] == "0") {
            return "0";
        }

        string res{};

        for (const auto& n : nums_str) {
            res += n;
        }

        return res;
    }
};
