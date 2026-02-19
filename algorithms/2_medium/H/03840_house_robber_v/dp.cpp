class Solution {
    struct AmountColor {
        long long amount;
        int color;
    };
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        const size_t len{ nums.size() };
        auto prev{ AmountColor {0, 0} };
        auto prev_prev{ AmountColor {0, 0} };

        for (size_t i{ 0 }; i < len; ++i) {
            const long long amount_to_add {
                colors[i] == prev.color ? prev_prev.amount : std::max(prev_prev.amount, prev.amount)
            };

            const auto curr { AmountColor {
                static_cast<long long>(nums[i]) + amount_to_add,
                colors[i]
            }};

            if (prev_prev.amount < prev.amount) {
                prev_prev = prev;
            }

            prev = curr;
        }

        return std::max(prev.amount, prev_prev.amount);
    }
};
